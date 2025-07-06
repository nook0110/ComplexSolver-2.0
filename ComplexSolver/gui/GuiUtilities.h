#pragma once
#include "geometry/GeometricObject.h"

namespace ComplexSolver {
inline bool ObjectsNameGetter(void* data, int index, const char** name) {
  // Convert data to std::vector<GeometricObject*> pointer
  const std::vector<GeometricObject*>& objects =
      *static_cast<std::vector<GeometricObject*>*>(data);

  // Check if index is valid
  if (index < 0 || index >= static_cast<int>(objects.size())) {
    return false;
  }

  // Set name
  *name = objects[index]->GetName().data();

  return true;
}
}  // namespace ComplexSolver
