#pragma once

#include "Var.h"

namespace ComplexSolver {

/**
 * \brief Struct that defines position of the point.
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date February 2023
 *
 * \see PointImplementation
 *
 */
class PointEquation {
 public:
  struct Equation {
    float x;
    float y;

    float& operator[](Var var) {
      switch (var) {
        case Var::kX:
          return x;
        case Var::kY:
          return y;
      }
    }
    const float& operator[](Var var) const {
      switch (var) {
        case Var::kX:
          return x;
        case Var::kY:
          return y;
      }
    }
  };

  /**
   * \brief Constructor.
   *
   * \param equation Equation of point.
   */
  explicit PointEquation() = default;

  /**
   * \brief Return current equation of point.
   *
   * \return Point equation.
   */
  [[nodiscard]] PointEquation::Equation& GetEquation() { return equation_; }

  /**
   * \brief Return current equation of point.
   *
   * \return Point equation.
   */
  [[nodiscard]] const PointEquation::Equation& GetEquation() const {
    return equation_;
  }

 private:
  Equation equation_;
};

/**
 * \brief Struct that defines position of the line
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date February 2023
 *
 * \see LineImplementation
 *
 */
class LineEquation {
 public:
  struct Equation {
    float A;
    float B;
    float C;
  };
  /**
   * \brief Constructor.
   *
   * \param equation Equation of line.
   */
  explicit LineEquation() = default;

  /**
   * \brief Return current equation of point.
   *
   * \return Point equation.
   */
  [[nodiscard]] LineEquation::Equation& GetEquation() { return equation_; }

  /**
   * \brief Return current equation of point.
   *
   * \return Point equation.
   */
  [[nodiscard]] const LineEquation::Equation& GetEquation() const {
    return equation_;
  }

 private:
  Equation equation_;
};
}  // namespace ComplexSolver
