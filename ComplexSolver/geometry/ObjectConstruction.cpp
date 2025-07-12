#include "ObjectConstruction.h"

#include <array>
#include <random>
#include <utility>

#include "core/Assert.h"
#include "GeometricObject.h"
#include "utils/Matrix.h"

namespace ComplexSolver {
ConstructionPoint::~ConstructionPoint() = default;

GeometricObject* ConstructionPoint::GetObject() const { return GetPoint(); }

Point* ConstructionPoint::GetPoint() const {
  // Return point
  return point_.get();
}
void ConstructionPoint::Update(const ObjectEvent::GoingToBeDestroyed& event) {
  // Check if event object is point that we contain
  if (event.object == GetObject()) {
    point_.reset();
    return;
  }

  // Destroy the point
  point_->AlertDestruction();
}

void ConstructionPoint::Update(const ObjectEvent::Renamed& renamed_event) {
  // Renaming has no effect on object
}

ConstructionPoint::ConstructionPoint() : point_(std::make_unique<Point>()) {}

const PointEquation& ConstructionPoint::GetEquation() const {
  // Return point equationHomoGebra
  return point_->GetEquation();
}

void ConstructionPoint::SetEquation(PointEquation equation) const {
  // Set new equation
  point_->SetEquation(std::move(equation));
}

PointOnPlane::PointOnPlane(PointEquation equation)
    : ConstructionPoint(), equation_(std::move(equation)) {
  // Set equation
  PointOnPlane::RecalculateEquation();
}

void PointOnPlane::RecalculateEquation() {
  // Set equation
  SetEquation(equation_);
}

GeometricObject* ConstructionLine::GetObject() const {
  // Return line
  return GetLine();
}

ConstructionLine::~ConstructionLine() = default;

Line* ConstructionLine::GetLine() const {
  // Return line
  return line_.get();
}

void ConstructionLine::Update(const ObjectEvent::GoingToBeDestroyed& event) {
  // Check if event object is line that we contain
  if (event.object == GetObject()) {
    // Destroy the line
    line_.reset();
    return;
  }

  // Destroy the line
  line_->AlertDestruction();
}

void ConstructionLine::Update(const ObjectEvent::Renamed& event) {}

ConstructionLine::ConstructionLine() : line_(std::make_unique<Line>()) {}

const LineEquation& ConstructionLine::GetEquation() const {
  // Return line equation
  return line_->GetEquation();
}

void ConstructionLine::SetEquation(const LineEquation& equation) const {
  // Set new equation
  line_->SetEquation(equation);
}

LineOnPlane::LineOnPlane(LineEquation equation)
    : equation_(std::move(equation)) {
  // Set equation
  LineOnPlane::RecalculateEquation();
}

void LineOnPlane::RecalculateEquation() {
  // Set equation
  SetEquation(equation_);
}

ByTwoPoints::ByTwoPoints(Point* first_point, Point* second_point)
    : first_point_(first_point), second_point_(second_point) {
  // Attach to points
  first_point_->Attach(this);
  second_point_->Attach(this);

  // Recalculate equation
  RecalculateEquation();
}

ByTwoPoints::~ByTwoPoints() {
  // Detach from points
  first_point_->Detach(this);
  second_point_->Detach(this);
}

void ByTwoPoints::RecalculateEquation() {
  // Construct equation

  // Calculate equation of a line that goes through 2 points
  // We need to solve the system of equations [matrix]:
  // f_ is first, s_ is second
  // and r is random numbers
  // | f_x f_y 1 | 0 |
  // | s_x s_y 1 | 0 |
  // |  r   r   r  | 1 |

  // Get equations of points
  const std::array equations = {first_point_->GetEquation().GetEquation(),
                                second_point_->GetEquation().GetEquation()};

  // Create matrix
  FloatSquaredMatrix matrix{3};

  // Set first two rows using equations
  for (size_t row = 0; row < equations.size(); ++row) {
    auto& matrix_row = matrix[row];
    const auto& equation = equations[row];

    for (size_t column = 0; column < matrix_row.size(); ++column) {
      if (column == 2) {
        matrix_row[column] = 1;
        continue;
      }

      matrix_row[column] = equation[static_cast<Var>(column)];
    }
  }

  // Get third row
  auto& third_row = matrix[2];

  // Set random number generator
  constexpr long double kLowerBound = -10000;
  constexpr long double kUpperBound = 10000;
  std::uniform_real_distribution<float> uniform_real_distribution(kLowerBound,
                                                                  kUpperBound);
  std::default_random_engine default_random_engine;

  // Set third row
  std::ranges::for_each(third_row, [&uniform_real_distribution,
                                    &default_random_engine](float& value) {
    value = uniform_real_distribution(default_random_engine);
  });

  // Get augmentation
  auto& augmentation = matrix.GetAugmentation();

  // Set augmentation
  std::fill(augmentation.begin(), std::prev(augmentation.end()), 0);
  augmentation.back() = 1;

  // Get solution
  const auto solution = matrix.GetSolution();

  // Check if solution exists
  Assert(solution.has_value(), "Matrix has no solution!");

  // Get value
  const auto& value = *solution;

  // Create equation
  SetEquation(LineEquation({value[0], value[1], value[2]}));
}
}  // namespace ComplexSolver