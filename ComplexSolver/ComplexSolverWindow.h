#pragma once
#include <SFML/Window.hpp>

#include "Plane.h"

namespace ComplexSolver {
class ComplexSolverWindow final : public sf::Window {
 public:
  ComplexSolverWindow(sf::VideoMode mode, const sf::String& title,
                  sf::Uint32 style = sf::Style::Default,
                  const sf::ContextSettings& settings = sf::ContextSettings());

 private:
  void onResize() override;
  void onCreate() override;
};
}  // namespace ComplexSolver