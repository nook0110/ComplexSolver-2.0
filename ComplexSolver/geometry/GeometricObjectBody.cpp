#include "GeometricObjectBody.h"

#include <SFML/Graphics.hpp>
#include <Thor/Shapes.hpp>
#include <array>
#include <numbers>
#include <utility>

#include "Equation.h"
#include "GeometricObject.h"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Vector2.hpp"
#include "core/Assert.h"
#include "misc/Font.h"

namespace ComplexSolver {
float CalculateSizeOfPixel(const sf::RenderTarget& target) {
  // Calculate position of pixel with coordinate (0, 0)
  const auto first_pixel_position = target.mapPixelToCoords({0, 0});

  // Calculate position of pixel with coordinate (1, 0)
  const auto second_pixel_position = target.mapPixelToCoords({1, 0});

  // Calculate size of pixel
  const auto pixel_size =
      std::abs(second_pixel_position.x - first_pixel_position.x);

  return pixel_size;
}
}  // namespace ComplexSolver

namespace ComplexSolver {
ObjectName::ObjectName(std::string name) {
  // Load font
  font_.loadFromMemory(kFontData.data(), kFontData.size());

  // Set font
  text_.setFont(font_);
  text_.setCharacterSize(kCharacterSize);

  // Set color
  text_.setFillColor(kTextColor);

  // Set name
  SetName(std::move(name));
}

void ObjectName::SetName(std::string name) {
  // Set name
  name_ = std::move(name);

  // Set text
  text_.setString(name_);
}

const std::string& ObjectName::GetName() const { return name_; }

void ObjectName::SetSize(const float size) {
  const auto height = text_.getLocalBounds().height;
  auto factor = size / height;
  text_.setScale({factor, factor});
}

void ObjectName::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  // Apply transform
  states.transform *= getTransform();
  // Draw
  target.draw(text_, states);
}

void ObjectBody::SetName(std::string name) {
  // Set name
  text_.SetName(std::move(name));
}

const std::string& ObjectBody::GetName() const {
  // Return name
  return text_.GetName();
}

void ObjectBody::SetNamePosition(const sf::Vector2f& position) {
  // Set position
  text_.setPosition(position);
}

void ObjectBody::SetNameSize(const float size) {
  // Set size
  text_.SetSize(size);
}

void ObjectBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  // Draw name
  target.draw(text_, states);
}

PointBody::PointBody(PointEquation equation) : equation_(std::move(equation)) {
  body_.setFillColor(sf::Color::Red);
}

void PointBody::Update(const sf::RenderTarget& target) {
  // Calculate position
  sf::Vector2f position = {equation_.GetEquation().x,
                           equation_.GetEquation().y};
  body_.setPosition(position);
  SetNamePosition(position);

  // Set size
  auto size = CalculateSizeOfBody(target);
  constexpr auto kTextFactor = 2.f;
  SetNameSize(size * kTextFactor);

  // Set size
  body_.setRadius(size);
  body_.setOrigin(size, size);
}

void PointBody::SetEquation(PointEquation equation) {
  equation_ = std::move(equation);
}

const PointEquation& PointBody::GetEquation() const { return equation_; }

void PointBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  // Draw point
  target.draw(body_, states);
  ObjectBody::draw(target, states);
}

Distance PointBody::GetDistance(const sf::Vector2f& position) const {
  sf::Vector2f point_position = {equation_.GetEquation().x,
                                 equation_.GetEquation().y};
  return Length(point_position - position);
}

float PointBody::CalculateSizeOfBody(const sf::RenderTarget& target) {
  // Calculate size of pixel
  const auto pixel_size = CalculateSizeOfPixel(target);

  // Ratio of size of body to size of pixel
  constexpr float kRatio = 2 * std::numbers::pi_v<float>;

  // Calculate size of body
  const auto size = pixel_size * kRatio;

  // Return size of body
  return size;
}

LineBody::LineBody(LineEquation equation)
    : line_equation_(std::move(equation)) {}

std::array<sf::Vertex, 2> static GenerateIntersectionWithWindow(
    const sf::RenderTarget& target, const LineEquation& equation) {
  const auto& a = equation.GetEquation().A;
  const auto& b = equation.GetEquation().B;
  const auto& c = equation.GetEquation().C;

  const auto& center = target.getView().getCenter();
  const auto& size = target.getView().getSize();

  const auto left = center.x - size.x / 2.f;
  const auto right = center.x + size.x / 2.f;
  const auto up = center.y + size.y / 2.f;
  const auto down = center.y - size.y / 2.f;

  std::array<sf::Vertex, 2> line_vertices;

  std::ranges::for_each(line_vertices, [](sf::Vertex& vertex) {
    vertex.color = sf::Color::Black;
  });

  constexpr size_t first = 0;
  constexpr size_t second = 1;

  if (std::abs(a / b) > size.y / size.x) {
    line_vertices[first].position.y = down;
    line_vertices[second].position.y = up;
    line_vertices[first].position.x =
        -(line_vertices[first].position.y * b + c) / a;
    line_vertices[second].position.x =
        -(line_vertices[second].position.y * b + c) / a;
  } else {
    line_vertices[first].position.x = left;
    line_vertices[second].position.x = right;
    line_vertices[first].position.y =
        -(line_vertices[first].position.x * a + c) / b;
    line_vertices[second].position.y =
        -(line_vertices[second].position.x * a + c) / b;
  }

  return line_vertices;
}

static std::array<sf::Vertex, 4> GenerateThickLine(
    const std::array<sf::Vertex, 2>& line_vertices, const float thickness) {
  std::array<sf::Vertex, 4> vertices_with_thickness;

  const auto& first = line_vertices[0];
  const auto& second = line_vertices[1];

  const auto direction = second.position - first.position;
  const auto normal = sf::Vector2f(-direction.y, direction.x);
  const auto normalized_normal = normal / std::hypot(normal.x, normal.y);

  const auto half_thickness = thickness / 2.f;
  const auto first_vertex = first.position + normalized_normal * half_thickness;
  const auto second_vertex =
      second.position + normalized_normal * half_thickness;
  const auto third_vertex =
      second.position - normalized_normal * half_thickness;
  const auto fourth_vertex =
      first.position - normalized_normal * half_thickness;

  vertices_with_thickness[0] = sf::Vertex(first_vertex, first.color);
  vertices_with_thickness[1] = sf::Vertex(second_vertex, first.color);
  vertices_with_thickness[2] = sf::Vertex(third_vertex, second.color);
  vertices_with_thickness[3] = sf::Vertex(fourth_vertex, second.color);

  return vertices_with_thickness;
}

void LineBody::Update(const sf::RenderTarget& target) {
  auto line_vertices = GenerateIntersectionWithWindow(target, line_equation_);

  line_body_ = GenerateThickLine(line_vertices, CalculateSizeOfBody(target));
}

void LineBody::SetEquation(LineEquation equation) {
  line_equation_ = std::move(equation);
}

const LineEquation& LineBody::GetEquation() const { return line_equation_; }

void LineBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(line_body_.data(), line_body_.size(), sf::Quads);
}

Distance LineBody::GetDistance(const sf::Vector2f& position) const {
  const auto& [a, b, c] = line_equation_.GetEquation();

  return DistanceToLine(position, a, b, c);
}

float LineBody::CalculateSizeOfBody(const sf::RenderTarget& target) {
  constexpr auto kLineFactor = 2.f;
  return CalculateSizeOfPixel(target) * kLineFactor;
}
}  // namespace ComplexSolver