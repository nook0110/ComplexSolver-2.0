#include "GeometricObjectImplementation.h"

#include <utility>

namespace ComplexSolver {
PointImplementation::PointImplementation(PointEquation equation)
    : equation_(std::move(equation)) {}

void PointImplementation::SetEquation(PointEquation equation) {
  // Set equation
  equation_ = std::move(equation);

  // Notify observers
  Notify(ObjectEvent::Moved());
}

const PointEquation& PointImplementation::GetEquation() const {
  // Return equation
  return equation_;
}

LineImplementation::LineImplementation(LineEquation equation)
    : equation_(std::move(equation)) {}

void LineImplementation::SetEquation(LineEquation equation) {
  // Set equation
  equation_ = std::move(equation);

  // Notify observers
  Notify(ObjectEvent::Moved());
}

const LineEquation& LineImplementation::GetEquation() const {
  // Return equation
  return equation_;
}
}  // namespace ComplexSolver