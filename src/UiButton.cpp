#include "UiButton.h"

#include <Hex.h>

namespace Hex {
    void UiButton::draw() {
        DrawRectangle(position.x, position.y, size.x, size.y, color);
        DrawText(text.c_str(), position.x, position.y, 20, textColor);
    }

    void UiButton::update() {
        auto mouse = GetMousePosition();
        if (mouse.x >= position.x && mouse.x <= position.x + size.x &&
            mouse.y >= position.y && mouse.y <= position.y + size.y) {
            setCurrentCursor(MOUSE_CURSOR_POINTING_HAND);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                OnClick(this);
            }
        }
    }

    std::shared_ptr<UiButton> createButton(Vector2 position, Vector2 size, Color color, Color textColor, std::string text) {
        auto button = std::make_shared<UiButton>();
        button->position = position;
        button->size = size;
        button->color = color;
        button->textColor = textColor;
        button->text = text;
        return button;
    }
}
