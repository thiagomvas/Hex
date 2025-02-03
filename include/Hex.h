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
    static std::shared_ptr<UiElement> customDecorator = nullptr;

    static MouseCursor currentCursor;





    std::shared_ptr<HexWindow> init(int argc, char **argv);
    void update();
    bool isRunning();
    void dispose();
    void setCurrentCursor(MouseCursor cursor);

    void addUiElement(std::shared_ptr<UiElement> element);
    void setDecorator(std::shared_ptr<UiElement> decorator);



}

#endif //HEX_H
