#include "ObjectSelector.h"

#include "geometry/GeometricObject.h"

namespace ComplexSolver {
template <class GeometricObjectType>
GeometricObjectType* ObjectSelector<GeometricObjectType>::operator()() const {
  return ObjectSelectorBody<GeometricObjectType>::GetObject();
}

template class ObjectSelector<GeometricObject>;
template class ObjectSelector<Point>;
template class ObjectSelector<Line>;
}  // namespace ComplexSolver