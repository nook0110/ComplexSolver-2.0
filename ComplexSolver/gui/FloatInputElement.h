#pragma once

#include "observer/Observer.h"

namespace ComplexSolver {

class Plane;

/**
 * @brief Body class for float input element
 */
class FloatInputElementBody : public UniquePlaneObserver {
 public:
  explicit FloatInputElementBody(Plane* plane);

  void Draw();

  float GetValue() const;
};

/**
 * @brief Float input element class
 */
class FloatInputElement : public FloatInputElementBody {
 public:
  explicit FloatInputElement(Plane* plane) : FloatInputElementBody(plane) {}

  float operator()() const { return GetValue(); }
};

}  // namespace ComplexSolver