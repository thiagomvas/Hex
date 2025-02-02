//
// Created by thiagomv on 02/02/25.
//

#include "UiElement.h"

#ifndef UIBUTTON_H
#define UIBUTTON_H

namespace Hex {
class UiButton : public UiElement {
  public:
    Color color;
    Color textColor;
    std::string text;

    void Draw() override;
    void Update() override;

    void (*OnClick)(UiButton*);
};

std::shared_ptr<UiButton> createButton(Vector2 position, Vector2 size, Color color, Color textColor, std::string text);
}
#endif //UIBUTTON_H
