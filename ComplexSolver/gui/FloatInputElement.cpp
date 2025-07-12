#include "gui/FloatInputElement.h"

#include <imgui.h>

namespace ComplexSolver {

FloatInputElementBody::FloatInputElementBody(Plane* plane)
    : UniquePlaneObserver(plane) {}

void FloatInputElementBody::Draw() {
  ImGui::PushID(this);
  ImGui::InputFloat(
      "Value", ImGui::GetStateStorage()->GetFloatRef(ImGui::GetID(this), 0.f));
  ImGui::PopID();
}

float FloatInputElementBody::GetValue() const {
  return ImGui::GetStateStorage()->GetFloat(ImGui::GetID(this));
}

}  // namespace ComplexSolver