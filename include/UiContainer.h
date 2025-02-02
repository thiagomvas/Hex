//
// Created by thiagomv on 02/02/25.
//

#ifndef UICONTAINER_H
#define UICONTAINER_H

#include "UiElement.h"

namespace Hex {
    class UiContainer : public UiElement {
    public:
        void draw() override;
        void update() override;
        void AddChild(std::shared_ptr<UiElement> child);
    };
}

#endif //UICONTAINER_H
