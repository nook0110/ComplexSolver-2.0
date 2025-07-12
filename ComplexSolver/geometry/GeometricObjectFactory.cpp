#include "GeometricObjectFactory.h"
#include <string_view>

#include "ObjectConstruction.h"
#include "plane/Plane.h"

namespace ComplexSolver {
Point* PointOnPlaneFactory::operator()(PointEquation equation, std::string_view name) const {
  // Create construction
  auto construction = std::make_unique<PointOnPlane>(std::move(equation));

  const auto point = construction->GetPoint();

  // Add construction to plane
  plane_->AddConstruction(std::move(construction));

  const auto& name_generator = plane_->GetNameGenerator();

  // Rename point
  point->SetName(static_cast<std::string>(name_generator.GenerateName(name)));

  // Return point
  return point;
}

Line* LineOnPlaneFactory::operator()(LineEquation equation) const {
  // Create construction
  auto construction = std::make_unique<LineOnPlane>(std::move(equation));

  const auto line = construction->GetLine();

  // Add construction to plane
  plane_->AddConstruction(std::move(construction));

  const auto& name_generator = plane_->GetNameGenerator();

  // Rename line
  line->SetName(static_cast<std::string>(name_generator.GenerateName()));

  // Return line
  return line;
}

Line* LineByTwoPointsFactory::operator()(Point* first, Point* second) const {
  if (first == second) return nullptr;

  // Create construction
  auto construction = std::make_unique<class ByTwoPoints>(first, second);

  const auto line = construction->GetLine();

  // Add line to plane
  plane_->AddConstruction(std::move(construction));

  const auto& name_generator = plane_->GetNameGenerator();

  line->SetName(static_cast<std::string>(
      name_generator.GenerateName(first->GetName() + second->GetName())));

  // Return line
  return line;
}
}  // namespace ComplexSolver