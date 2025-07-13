#include "FloatInputElement.h"

#include <imgui.h>

namespace ComplexSolver {

FloatInputElementBody::FloatInputElementBody(Plane* plane)
    : UniquePlaneObserver(plane) {}

void FloatInputElementBody::Draw() {
  ImGui::PushID(this);
  ImGui::InputFloat("Value", &value_, 0.f);
  ImGui::PopID();
}

float FloatInputElementBody::GetValue() const { return value_; }

}  // namespace ComplexSolver