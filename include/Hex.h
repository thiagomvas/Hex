#ifndef HEX_H
#define HEX_H

#include <memory>
#include "HexWindow.h"
#include "UiElement.h"
#include "Logger.h"

namespace Hex {

// private reference to the singleton instance
static std::shared_ptr<HexWindow> hexWindow;
    static std::shared_ptr<Logger> logger;
    static std::shared_ptr<UiElement> root;


    std::shared_ptr<HexWindow> Init(int argc, char **argv);
    void Update();
    bool IsRunning();

    void Dispose();
}

#endif //HEX_H
