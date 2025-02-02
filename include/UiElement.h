#ifndef UIELEMENT_H
#define UIELEMENT_H

#include <memory>
#include "raylib.h"
#include <vector>
namespace Hex {
  class UiElement {
  public:
    Vector2 position;
    Vector2 size;
    bool visible;

    virtual void draw() = 0;
    virtual void update() = 0;

    std::vector<std::shared_ptr<UiElement>> children;
  };
}

#endif
