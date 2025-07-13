#pragma once
#include <imgui.h>

#include "Button.h"
#include "PointEquationElement.h"
#include "TextInputElement.h"
#include "elements/ObjectSelector.h"
#include "geometry/GeometricObject.h"
#include "geometry/GeometricObjectFactory.h"

namespace ComplexSolver {
/**
 * @brief A class representing a window button.
 *
 * This class is a template class that inherits from a specified button class.
 * It provides functionality to draw a button inside an ImGui window.
 *
 * @tparam ButtonClass The class of the button to inherit from.
 */
template <class ButtonClass>
class WindowButton : public ButtonClass {
 public:
  /**
   * @brief Constructs a new WindowButton object.
   *
   * @param name The name of the button.
   * @param plane The plane associated with the button.
   */
  explicit WindowButton(std::string name, Plane* plane)
      : ButtonClass(plane), name_(std::move(name)) {}

  /**
   * @brief Draws the button inside an ImGui window.
   */
  void Draw() {
    ImGui::Begin(name_.data(), nullptr, ImGuiWindowFlags_AlwaysAutoResize);
    ButtonClass::Draw();
    ImGui::End();
  }

 private:
  std::string name_; /**< The name of the button. */
};

template <class Button>
class ApplyButton : public Button {
 public:
  /**
   * \brief Construct button for plane.
   *
   */
  explicit ApplyButton(Plane* plane) : Button(plane) {}

  /**
   * \brief Draws button.
   *
   */
  void Draw() {
    Button::Draw();
    if (DrawApplyButton()) {
      Button::operator()();
    }
  }

 private:
  /**
   * \brief Draws the apply button.
   *
   * \return True if the apply button is pressed, false otherwise.
   */
  bool DrawApplyButton() { return ImGui::Button("Apply"); }
};

class PointOnPlaneButton final
    : public WindowButton<
          ApplyButton<ButtonElement<PointEquationElement, TextInputElement,
                                    FactoryWrapper<PointOnPlaneFactory>>>> {
 public:
  /**
   * @brief Constructs a new PointOnPlaneButton object.
   *
   * @param plane The plane associated with the button.
   */
  explicit PointOnPlaneButton(Plane* plane)
      : WindowButton("Point on plane", plane) {}
};

/**class Li

 * @brief A class representing a button for creating a line by two points.
 *
 * This class is a specialization of the WindowButton class.
 * It provides functionality to create a line by selecting two points on a
 * plane.
 */
class LineByTwoPointButton final
    : public WindowButton<
          ApplyButton<ButtonElement<IndentWrapper<ObjectSelector<Point>>,
                                    IndentWrapper<ObjectSelector<Point>>,
                                    FactoryWrapper<LineByTwoPointsFactory>>>> {
 public:
  /**
   * @brief Constructs a new LineByTwoPointButton object.
   *
   * @param plane The plane associated with the button.
   */
  explicit LineByTwoPointButton(Plane* plane)
      : WindowButton("Line by two points", plane) {}
};

/**
 * @brief A class representing a delete button.
 *
 * This class is a specialization of the WindowButton class.
 * It provides functionality to delete a selected geometric object.
 */
class DeleteButton final
    : public WindowButton<ApplyButton<
          ButtonElement<ObjectSelector<GeometricObject>, Deleter>>> {
 public:
  /**
   * @brief Constructs a new DeleteButton object.
   *
   * @param plane The plane associated with the button.
   */
  explicit DeleteButton(Plane* plane) : WindowButton("Delete button", plane) {}
};
}  // namespace ComplexSolver
