#pragma once
#include <imgui.h>

class IndentGuard {
 public:
  IndentGuard(float size = 5.f) : indent_(size / 2, size) {
    ImGui::BeginGroup();

    ImGui::Dummy(indent_);
    ImGui::Dummy(indent_);
    ImGui::SameLine();

    ImGui::BeginGroup();
  }
  IndentGuard(const IndentGuard&) = delete;
  IndentGuard(IndentGuard&&) = delete;
  IndentGuard& operator=(const IndentGuard&) = delete;
  IndentGuard& operator=(IndentGuard&&) = delete;

  ~IndentGuard() {
    ImGui::EndGroup();

    ImGui::SameLine();
    ImGui::Dummy(indent_);
    ImGui::Dummy(indent_);

    ImGui::EndGroup();

    ImVec2 top = ImGui::GetItemRectMin();
    ImVec2 down = ImGui::GetItemRectMax();
    ImGui::GetWindowDrawList()->AddRectFilled(top, down, kColor, 5.f,
                                              ImDrawFlags_RoundCornersAll);
  }

 private:
  static constexpr auto kColor = IM_COL32(255, 255, 255, 16);
  ImVec2 indent_;
};