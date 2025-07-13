#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include "DistanceUtilities.h"
#include "Equation.h"
#include "SFML/Graphics/RenderTarget.hpp"

namespace ComplexSolver {
/**
 * \brief Name of object that you can draw.
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date April 2023
 */
class ObjectName final : public sf::Drawable, public sf::Transformable {
 public:
  /**
   * \brief Constructs an object name.
   *
   * \param name Name of the object.
   */
  explicit ObjectName(std::string name = {});
  /**
   * \brief Destructor.
   *
   */
  ~ObjectName() override = default;

  /**
   * \brief Sets name of the object.
   *
   * \param name Name of the object.
   */
  void SetName(std::string name);
  /**
   * \brief Gets name of the object.
   *
   * \return Name of the object.
   */
  [[nodiscard]] const std::string& GetName() const;

  /**
   * \brief Sets size of the object name.
   *
   * \param size Size of the object name.
   */
  void SetSize(float size);
  /**
   * \brief Draw the object name to a render target.
   *
   * \param target Render target to draw to.
   * \param states States of the render.
   */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  static constexpr unsigned kCharacterSize = 50;  //!< Character size
  inline static const sf::Color kTextColor =
      sf::Color{0, 0, 0};  //!< Color of the text

  std::string name_;  //!< Name of the object

  sf::Font font_;  //!< Font of the text
  sf::Text text_;  //!< Text of the name
};

/**
 * \brief Base class for bodies.
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date July 2023
 */
class ObjectBody : public sf::Drawable {
 public:
  /**
   * \brief Set name of the point.
   *
   * \param name Name of the point.
   */
  void SetName(std::string name);

  /**
   * \brief Gets name of the point.
   *
   * \return Name of the point.
   */
  [[nodiscard]] const std::string& GetName() const;

  /**
   * \brief Sets position of the name.
   *
   * \param position Position of the name.
   */
  void SetNamePosition(const sf::Vector2f& position);

  /**
   * \brief Sets size of the name.
   *
   * \param size Size of the name.
   */
  void SetNameSize(float size);

  /**
   * \brief Draw the object body to a render target.
   *
   * \param target Render target to draw to.
   * \param states Current render states.
   */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  /**
   * \brief Gets distance from object to position.
   *
   * \param position Position to calculate distance.
   *
   * \return Distance from object to position.
   */
  [[nodiscard]] virtual Distance GetDistance(
      const sf::Vector2f& position) const = 0;

 private:
  ObjectName text_;  //!< Name of the name.
};

/**
 * \brief Body of a point
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date February 2023
 */
class PointBody final : public ObjectBody {
 public:
  /**
   * \brief Default constructor.
   *
   */
  explicit PointBody(PointEquation equation);

  /**
   * \brief Destructor.
   *
   */
  ~PointBody() override = default;

  /**
   * \brief Updates the point body.
   *
   * \param equation Equation of the point.
   * \param size Size of the point.
   */
  void Update(const sf::RenderTarget& target);

  void SetEquation(PointEquation equation);

  const PointEquation& GetEquation() const;

  /**
   * \brief Draw the point to a render target.
   *
   * \param target Render target to draw to.
   * \param states Current render states.
   */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  Distance GetDistance(const sf::Vector2f& position) const override;

  /**
   * \brief Calculates size of a body
   *
   * \details Calculates size of pixel and than multiply size on a const
   *
   * \param target Render target to draw to.
   *
   * \return Size of body.
   */
  static float CalculateSizeOfBody(const sf::RenderTarget& target);

 private:
  /**
   * Member data.
   */

  PointEquation equation_;  //!< Projective position of the point.
  sf::CircleShape body_;    //!< Body of the point.
};

/**
 * \brief Body of a line.
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date February 2023
 */
class LineBody final : public ObjectBody {
 public:
  /**
   * \brief Default constructor.
   *
   */
  explicit LineBody(LineEquation equation);

  /**
   * \brief Destructor.
   *
   */
  ~LineBody() override = default;

  /**
   * \brief Updates the line body.
   *
   * \param equation Equation of the line.
   */
  void Update(const sf::RenderTarget& target);

  void SetEquation(LineEquation equation);

  const LineEquation& GetEquation() const;

  /**
   * \brief Draw line to a render target.
   *
   * \param target Render target to draw to.
   * \param states Current render states.
   */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

  Distance GetDistance(const sf::Vector2f& position) const override;

  /**
   * \brief Calculates size of a body
   *
   * \details Calculates size of pixel and than multiply size on a const
   *
   * \param target Render target to draw to.
   *
   * \return Size of body.
   */
  static float CalculateSizeOfBody(const sf::RenderTarget& target);

 private:
  LineEquation line_equation_;
  std::array<sf::Vertex, 4> line_body_;
};
}  // namespace ComplexSolver