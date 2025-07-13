#pragma once
#include <imgui.h>

#include "ButtonImplementation.h"
#include "utils/Indent.h"

namespace ComplexSolver {

/**
 * \brief Button.
 *
 * \see LineByTwoPointButton
 * \see DeleteButton
 *
 */
template <class... Elements>
class ButtonElement : public ButtonImplementation<Elements...> {
 public:
  /**
   * \brief Construct button for plane.
   *
   */
  explicit ButtonElement(Plane* plane)
      : ButtonImplementation<Elements...>(plane) {}

  /**
   * \brief Draws button.
   *
   */
  void Draw() {
    IndentGuard indent{};
    ButtonImplementation<Elements...>::Draw();
  }

  template <class... Args>
  void operator()(Args&&... arguments) const {
    ButtonImplementation<Elements...>::PassArguments(
        std::forward<Args>(arguments)...);
  }
};
}  // namespace ComplexSolver
