#pragma once
#include <utility>

namespace ComplexSolver {
class Plane;

template <class T>
concept ButtonElementConcept = requires(T button_part) {
  { T{static_cast<Plane*>(nullptr)} };
} && requires(const T button_part) {
  { button_part() };
};

template <class T>
concept HasDraw = requires(T t) { t.Draw(); };

/**
 * \brief Wrapper of element
 *
 * \tparam Element Element to wrap.
 * \tparam index Index.
 */
template <class Element, std::size_t index = 0>
struct Wrapper : Element {
  explicit Wrapper(Plane* plane) : Element(plane) {}

  void Draw() {
    if constexpr (HasDraw<Element>) {
      Element::Draw();
    }
  }
};

/**
 * \brief Button implementation.
 *
 *
 * \tparam First First element type.
 * \tparam Rest Rest elements types.
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date July 2023
 */
template <ButtonElementConcept First, class... Rest>
class ButtonImplementation : public Wrapper<First, sizeof...(Rest)>,
                             public ButtonImplementation<Rest...> {
 public:
  /**
   * \brief Construct button for plane.
   *
   * \param plane Plane to construct button for.
   */
  explicit ButtonImplementation(Plane* plane)
      : Wrapper<First, sizeof...(Rest)>(plane),
        ButtonImplementation<Rest...>(plane) {}

  /**
   * \brief Draws button.
   *
   */
  void Draw() {
    Wrapper<First, sizeof...(Rest)>::Draw();
    ButtonImplementation<Rest...>::Draw();
  }

  /**
   * \brief Construct object from arguments.
   *
   * \tparam Args Argument types.
   * \param arguments Already received arguments.
   */
  template <class... Args>
  void PassArguments(Args&&... arguments) const;
};

/**
 * \brief Object constructor for one element.
 *
 * \details Tail of ObjectConstructor.
 *
 * \tparam First First element type.
 *
 * \author nook0110
 *
 * \version 1.0
 *
 * \date July 2023
 */
template <ButtonElementConcept First>
class ButtonImplementation<First> : public Wrapper<First, 0> {
 public:
  /**
   * \brief Construct button for plane.
   *
   * \param plane Plane to construct button for.
   */
  explicit ButtonImplementation(Plane* plane) : Wrapper<First>(plane) {}

  /**
   * \brief Draws button.
   *
   */
  void Draw() { Wrapper<First>::Draw(); }

  /**
   * \brief Construct object from arguments.
   *
   * \tparam Args Argument types.
   * \param arguments Already received arguments.
   */
  template <class... Args>
  void PassArguments(Args&&... arguments) const;
};

template <ButtonElementConcept First, class... Rest>
template <class... Args>
void ButtonImplementation<First, Rest...>::PassArguments(
    Args&&... arguments) const {
  ButtonImplementation<Rest...>::PassArguments(
      std::forward<Args>(arguments)...,
      Wrapper<First, sizeof...(Rest)>::operator()());
}

template <ButtonElementConcept First>
template <class... Args>
void ButtonImplementation<First>::PassArguments(Args&&... arguments) const {
  Wrapper<First, 0>::operator()(std::forward<Args>(arguments)...);
}
}  // namespace ComplexSolver
