#include "Construction.h"

namespace ComplexSolver {
void Construction::Update(const ObjectEvent::Moved& moved_event) {
  // Recalculate equation
  RecalculateEquation();
}
}  // namespace ComplexSolver