#pragma once
#include <memory>

#include "core/Construction.h"
#include "observer/Observer.h"

class GeometricObject;

namespace ComplexSolver {
/**
 * \brief Base class for implementations of geometric objects.
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date February 2023
 *
 * \see PointImplementation
 * \see LineImplementation
 * \see ConicImplementation
 *
 */
class GeometricObjectImplementation : public ObservableGeometricObject {
 public:
  /**
   * \brief Destructor.
   *
   */
  ~GeometricObjectImplementation() override = default;

 private:
  std::unique_ptr<Construction> construction_;  //!< Construction of object.
};

/**
 * \brief Implementation of Point
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date April 2023
 *
 * \see Point
 */
class PointImplementation final : public GeometricObjectImplementation {};

/**
 * \brief Implementation of Line
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date April 2023
 *
 * \see Line
 */
class LineImplementation : public GeometricObjectImplementation {};
}  // namespace ComplexSolver