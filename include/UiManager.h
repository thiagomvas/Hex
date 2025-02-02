#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <memory>
#include <vector>
#include "UiElement.h"

namespace Hex {
    class UiManager {
    public:
      void init();
      void update();
      void draw();
      void dispose();
      void addElement(std::shared_ptr<UiElement> element);
      void clear();
    private:
      std::shared_ptr<UiElement> root;
    };
}

#endif //UIMANAGER_H
