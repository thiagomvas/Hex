#include "UiContainer.h"

namespace Hex {
    void UiContainer::draw() {
        for (const auto& child : children) {
            child->draw();
        }
    }

    void UiContainer::update() {
        for (const auto& child : children) {
            child->update();
        }
    }

    void UiContainer::AddChild(std::shared_ptr<UiElement> child) {
        children.push_back(child);
    }
}