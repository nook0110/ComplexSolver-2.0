#include <SFML/OpenGL.hpp>
#include <cstdlib>

#include "ButtonsImplementations.h"
#include "EventConverter.h"
#include "GeometricObject.h"
#include "GeometricObjectFactory.h"
#include "Gui.h"
#include "imgui-SFML.h"
#include "imgui.h"

namespace ComplexSolver::Editor {}  // namespace ComplexSolver::Editor

int main() {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 16;
  settings.majorVersion = 3;
  settings.minorVersion = 0;
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "ComplexSolver",
                          sf::Style::Titlebar | sf::Style::Close, settings);

  window.setView(sf::View({0, 0}, {1000, 1000}));

  if (!ImGui::SFML::Init(window)) {
    return EXIT_FAILURE;
  }

  window.setFramerateLimit(60);
  // ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  auto plane = std::make_unique<ComplexSolver::Plane>();

  auto first = ComplexSolver::PointOnPlaneFactory{plane.get()}(
      ComplexSolver::PointEquation{});
  auto second = ComplexSolver::PointOnPlaneFactory{plane.get()}(
      ComplexSolver::PointEquation{});

  ComplexSolver::LineByTwoPointButton line_by_two_point_button{plane.get()};
  ComplexSolver::DeleteButton delete_button{plane.get()};

  ComplexSolver::EventConverter converter(&window);
  converter.Attach(plane.get());
  while (window.isOpen()) {
    sf::Event event{};
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::MouseWheelScrolled) {
      }

      ComplexSolver::Gui::Global::ProcessEvent(event);

      if (auto const& io = ImGui::GetIO();
          io.WantCaptureMouse || io.WantCaptureKeyboard) {
        break;
      }

      converter.Update(event);
    }
    window.clear(sf::Color::White);

    ComplexSolver::Gui::Global::Update(window);

    // print distance from mouse to all objects
    auto mouse_position =
        window.mapPixelToCoords(sf::Mouse::getPosition(window));

    ImGui::Begin("Distance");
    for (auto const& object :
         plane->GetObjects<ComplexSolver::GeometricObject>()) {
      ImGui::Text("%s: %f", object->GetName().c_str(),
                  object->GetDistance(mouse_position));
    }
    ImGui::End();

    ImGui::Begin("Mouse position");
    ImGui::Text("Mouse position: (%f, %f)", mouse_position.x, mouse_position.y);
    ImGui::End();

    plane->UpdateBodies(window);  // TODO: Should be called only when window
                                  // size changes or it moves
    window.draw(*plane);

    line_by_two_point_button.Draw();
    delete_button.Draw();

    ComplexSolver::Gui::Global::Render(window);

    window.display();
  }

  ImGui::SFML::Shutdown();
  return 0;
}