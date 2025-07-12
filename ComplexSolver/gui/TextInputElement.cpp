#include "gui/TextInputElement.h"

#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>

namespace ComplexSolver {

TextInputElementBody::TextInputElementBody(Plane* plane)
    : UniquePlaneObserver(plane) {}

void TextInputElementBody::Draw() { ImGui::InputText("Text", &text_); }

const std::string& TextInputElementBody::GetText() const { return text_; }

const std::string& TextInputElement::operator()() const {
  return this->GetText();
}

}  // namespace ComplexSolver