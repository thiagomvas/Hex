#ifndef HEX_H
#define HEX_H

#include <memory>
#include "HexWindow.h"
#include "UiElement.h"
#include "Logger.h"
#include "UiManager.h"

namespace Hex {

// private reference to the singleton instance
static std::shared_ptr<HexWindow> hexWindow;
    static std::shared_ptr<Logger> logger;
    static std::shared_ptr<UiManager> uiManager;


    std::shared_ptr<HexWindow> Init(int argc, char **argv);
    void Update();
    bool IsRunning();
    void Dispose();

    void AddUiElement(std::shared_ptr<UiElement> element);



}

#endif //HEX_H
