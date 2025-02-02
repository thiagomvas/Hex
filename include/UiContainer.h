//
// Created by thiagomv on 02/02/25.
//

#ifndef UICONTAINER_H
#define UICONTAINER_H

#include "UiElement.h"

namespace Hex {
    class UiContainer : public UiElement {
    public:
        void Draw() override;
        void Update() override;
        void AddChild(std::shared_ptr<UiElement> child);
    };
}

#endif //UICONTAINER_H
