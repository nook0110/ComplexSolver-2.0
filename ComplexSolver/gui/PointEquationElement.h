#pragma once

#include "core/Equation.h"
#include "gui/FloatInputElement.h"
#include "observer/Observer.h"

namespace ComplexSolver {

class Plane;

/**
 * @brief Element for inputting point coordinates (x,y)
 */
class PointEquationElement : public UniquePlaneObserver {
 public:
  explicit PointEquationElement(Plane* plane);

  void Draw();

  PointEquation operator()() const;

 private:
  FloatInputElement x_input_;
  FloatInputElement y_input_;
};

}  // namespace ComplexSolver