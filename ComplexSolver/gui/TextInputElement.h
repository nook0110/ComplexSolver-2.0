#pragma once

#include "utils/Observer.h"
#include <string>

namespace ComplexSolver {

class Plane;

/**
 * @brief Body class for text input element
 */
class TextInputElementBody : public UniquePlaneObserver {
public:
    explicit TextInputElementBody(Plane* plane);

    void Draw();

    const std::string& GetText() const;

private:
    std::string text_;
};

/**
 * @brief Text input element class
 */
class TextInputElement : public TextInputElementBody {
public:
    explicit TextInputElement(Plane* plane) : TextInputElementBody(plane) {}

    /**
     * @brief Returns the text entered by the user
     * @return const std::string& The entered text
     */
    [[nodiscard]] const std::string& operator()() const;
};

} // namespace ComplexSolver