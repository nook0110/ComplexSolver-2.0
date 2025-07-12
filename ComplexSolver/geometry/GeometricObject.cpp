#include "GeometricObject.h"

#include <utility>

#include "core/Equation.h"
#include "GeometricObjectImplementation.h"

namespace ComplexSolver {
Point::Point(PointEquation equation) : implementation_(std::move(equation)) {}

void Point::AlertDestruction() const {
  // Notify observers that object was destroyed
  Notify(ObjectEvent::GoingToBeDestroyed{this});
}

template <class Event>
void Point::Notify(const Event& event) const {
  // Call implementation method
  implementation_.Notify(event);
}

template void Point::Notify<ObjectEvent::GoingToBeDestroyed>(
    const ObjectEvent::GoingToBeDestroyed& event) const;

template void Point::Notify<ObjectEvent::Renamed>(
    const ObjectEvent::Renamed& event) const;

void Point::SetEquation(PointEquation equation) {
  // Set equation in implementation
  implementation_.SetEquation(std::move(equation));
}

const PointEquation& Point::GetEquation() const {
  // Return equation
  return implementation_.GetEquation();
}

Distance Point::GetDistance(const sf::Vector2f& position) const {
  return body_.GetDistance(position);
}

void Point::Attach(GeometricObjectObserver* observer) {
  // Call implementation method
  implementation_.Attach(observer);
}

void Point::Detach(const GeometricObjectObserver* observer) {
  implementation_.Detach(observer);
}

void Point::UpdateBody(const sf::RenderTarget& target) {
  // Update body
  body_.Update(target, implementation_.GetEquation());
}

void Point::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  // Draw body
  target.draw(body_, states);
}

void Point::SetName(std::string name) {
  const ObjectEvent::Renamed renamed{this, body_.GetName(), name};

  // Set name in body
  body_.SetName(std::move(name));

  // Notify observers that object was renamed
  Notify(renamed);
}

const std::string& Point::GetName() const {
  // Return name
  return body_.GetName();
}

Line::Line(LineEquation equation) : implementation_(std::move(equation)) {}

void Line::AlertDestruction() const {
  // Notify observers that object was destroyed
  Notify(ObjectEvent::GoingToBeDestroyed{this});
}

void Line::SetEquation(LineEquation equation) {
  // Set equation in implementation
  implementation_.SetEquation(std::move(equation));
}

const LineEquation& Line::GetEquation() const {
  // Return equation
  return implementation_.GetEquation();
}

void Line::UpdateBody(const sf::RenderTarget& target) {
  // Update body
  body_.Update(implementation_.GetEquation());
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  // Draw body
  target.draw(body_, states);
}

void Line::SetName(std::string name) {
  const ObjectEvent::Renamed renamed{this, body_.GetName(), name};

  // Set name in body
  body_.SetName(std::move(name));

  // Notify observers that object was renamed
  Notify(renamed);
}

const std::string& Line::GetName() const {
  // Return name
  return body_.GetName();
}

void Line::Attach(GeometricObjectObserver* observer) {
  // Call implementation method
  implementation_.Attach(observer);
}

void Line::Detach(const GeometricObjectObserver* observer) {
  implementation_.Detach(observer);
}

Distance Line::GetDistance(const sf::Vector2f& position) const {
  return body_.GetDistance(position);
}

template <class Event>
void Line::Notify(const Event& event) const {
  // Call implementation method
  implementation_.Notify(event);
}

template void Line::Notify<ObjectEvent::GoingToBeDestroyed>(
    const ObjectEvent::GoingToBeDestroyed& event) const;

template void Line::Notify<ObjectEvent::Renamed>(
    const ObjectEvent::Renamed& event) const;
}  // namespace ComplexSolver