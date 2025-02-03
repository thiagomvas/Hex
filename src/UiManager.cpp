#include "UiManager.h"
#include "Hex.h"
#include <memory>
#include "raylib.h"

#include "UiContainer.h"

namespace Hex {
    void UiManager::init() {
      if(root == nullptr) {
        root = std::make_shared<UiContainer>();
        }

        root->position = {0, 0};
        root->size = {static_cast<float>(hexWindow->width), static_cast<float>(hexWindow->height)};
        root->visible = true;
    }

    void UiManager::update() {

      root->update();
    }

    void UiManager::draw() {
        root->draw();
    }

    void UiManager::dispose() {
        root->children.clear();
    }

    void UiManager::addElement(std::shared_ptr<UiElement> element) {
      if(root == nullptr) {
        root = element;
      } else {
        root->children.push_back(element);
        }
    }

    void UiManager::clear() {
        root->children.clear();
    }
}