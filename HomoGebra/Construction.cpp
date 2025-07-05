#include "Construction.h"

namespace HomoGebra
{
void Construction::Update(const ObjectEvent::Moved& moved_event)
{
  // Recalculate equation
  RecalculateEquation();
}
}  // namespace HomoGebra