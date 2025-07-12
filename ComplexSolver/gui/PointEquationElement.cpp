#include "gui/PointEquationElement.h"

#include <imgui.h>

namespace ComplexSolver {

PointEquationElement::PointEquationElement(Plane* plane)
    : UniquePlaneObserver(plane), x_input_(plane), y_input_(plane) {}

void PointEquationElement::Draw() {
  ImGui::Text("X:");
  x_input_.Draw();

  ImGui::Text("Y:");
  y_input_.Draw();
}

PointEquation PointEquationElement::operator()() const {
  return PointEquation{PointEquation::Equation{x_input_(), y_input_()}};
}

}  // namespace ComplexSolver