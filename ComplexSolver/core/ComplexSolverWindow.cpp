#include "ComplexSolverWindow.h"
#include <SFML/Window.hpp>

namespace ComplexSolver {
ComplexSolverWindow::ComplexSolverWindow(const sf::VideoMode mode,
                                         const sf::String& title,
                                         const sf::Uint32 style,
                                         const sf::ContextSettings& settings)
    : Window(mode, title, style, settings) {}

void ComplexSolverWindow::onResize() { Window::onResize(); }

void ComplexSolverWindow::onCreate() { Window::onCreate(); }
}  // namespace ComplexSolver