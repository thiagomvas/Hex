#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <memory>
#include <vector>
#include "UiElement.h"

namespace Hex {
    class UiManager {
    public:
      void Init();
      void Update();
      void Draw();
      void Dispose();
      void AddElement(std::shared_ptr<UiElement> element);
      void Clear();
    private:
      std::shared_ptr<UiElement> root;
    };
}

#endif //UIMANAGER_H
