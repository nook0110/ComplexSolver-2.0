#include "ObjectConstruction.h"

#include <utility>

#include "Equation.h"
#include "GeometricObject.h"
#include "core/Assert.h"

namespace ComplexSolver {
ConstructionPoint::~ConstructionPoint() = default;

GeometricObject* ConstructionPoint::GetObject() const { return GetPoint(); }

Point* ConstructionPoint::GetPoint() const {
  // Return point
  return point_.get();
}
void ConstructionPoint::Update(const ObjectEvent::GoingToBeDestroyed& event) {
  Assert(event.object != GetObject());

  // Destroy the point
  point_->AlertDestruction();
}

void ConstructionPoint::Update(const ObjectEvent::Renamed& renamed_event) {
  // Renaming has no effect on object
}

ConstructionPoint::ConstructionPoint() : point_(std::make_unique<Point>()) {}

const PointEquation& ConstructionPoint::GetEquation() const {
  // Return point equationHomoGebra
  return point_->GetEquation();
}

void ConstructionPoint::SetEquation(PointEquation equation) const {
  // Set new equation
  point_->SetEquation(std::move(equation));
}

PointOnPlane::PointOnPlane(PointEquation equation)
    : ConstructionPoint(), equation_(std::move(equation)) {
  // Set equation
  PointOnPlane::RecalculateEquation();
}

void PointOnPlane::RecalculateEquation() {
  // Set equation
  SetEquation(equation_);
}

GeometricObject* ConstructionLine::GetObject() const {
  // Return line
  return GetLine();
}

ConstructionLine::~ConstructionLine() = default;

Line* ConstructionLine::GetLine() const {
  // Return line
  return line_.get();
}

void ConstructionLine::Update(const ObjectEvent::GoingToBeDestroyed& event) {
  Assert(event.object != GetObject());

  // Destroy the line
  line_->AlertDestruction();
}

void ConstructionLine::Update(const ObjectEvent::Renamed& event) {}

ConstructionLine::ConstructionLine() : line_(std::make_unique<Line>()) {}

const LineEquation& ConstructionLine::GetEquation() const {
  // Return line equation
  return line_->GetEquation();
}

void ConstructionLine::SetEquation(const LineEquation& equation) const {
  // Set new equation
  line_->SetEquation(equation);
}

LineOnPlane::LineOnPlane(LineEquation equation)
    : equation_(std::move(equation)) {
  // Set equation
  LineOnPlane::RecalculateEquation();
}

void LineOnPlane::RecalculateEquation() {
  // Set equation
  SetEquation(equation_);
}

ByTwoPoints::ByTwoPoints(Point* first_point, Point* second_point)
    : first_point_(first_point), second_point_(second_point) {
  // Attach to points
  first_point_->Attach(this);
  second_point_->Attach(this);

  // Recalculate equation
  RecalculateEquation();
}

ByTwoPoints::~ByTwoPoints() {
  // Detach from points
  first_point_->Detach(this);
  second_point_->Detach(this);
}

void ByTwoPoints::RecalculateEquation() {
  // Construct equation

  // Get equations of points
  const auto& first_equation = first_point_->GetEquation().GetEquation();
  const auto& second_equation = second_point_->GetEquation().GetEquation();

  LineEquation line_equation{
      LineEquation::Equation{first_equation.y - second_equation.y,
                             -first_equation.x + second_equation.x,
                             first_equation.x * second_equation.y -
                                 second_equation.x * first_equation.y}};
  SetEquation(std::move(line_equation));
}
}  // namespace ComplexSolver