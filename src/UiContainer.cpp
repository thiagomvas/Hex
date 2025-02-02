#include "UiContainer.h"

namespace Hex {
    void UiContainer::Draw() {
        for (const auto& child : children) {
            child->Draw();
        }
    }

    void UiContainer::Update() {
        for (const auto& child : children) {
            child->Update();
        }
    }

    void UiContainer::AddChild(std::shared_ptr<UiElement> child) {
        children.push_back(child);
    }
}