#include "Hex.h"
#include "HexWindow.h"
#include "HexInitArgs.h"
#include <memory>
#include "raylib.h"

namespace Hex {

    void RaylibLogToLogger(int msgType, const char* text, va_list args) {
        auto level = "INFO";
        switch (msgType) {
            case LOG_INFO:
                level = "INFO";
                break;
            case LOG_ERROR:
                level = "ERROR";
                break;
            case LOG_WARNING:
                level = "WARNING";
                break;
            case LOG_DEBUG:
                level = "DEBUG";
                break;
        }
        logger->log(text, level, "libraylib", 0, "RaylibLogAdapter");

    }

    std::shared_ptr<HexWindow> init(int argc, char **argv) {
        // Initialize hexWindow here
        hexWindow = std::make_shared<HexWindow>();
        uiManager = std::make_shared<UiManager>();
        logger = std::make_shared<Logger>(&std::cout);

        // Log args
        logger->logInfo("Initializing Hex", __FILE__, __LINE__, __FUNCTION__);

        auto args = parseArgs(argc, argv);
        hexWindow->width = args.width;
        hexWindow->height = args.height;
        hexWindow->title = args.title;
        hexWindow->fullscreen = args.fullscreen;

        SetTraceLogCallback(RaylibLogToLogger);

        InitWindow(hexWindow->width, hexWindow->height, hexWindow->title);

        hexWindow->active = true;

        if (hexWindow->fullscreen) {
            ToggleFullscreen();
        }

        logger->logInfo("Hex initialized", __FILE__, __LINE__, __FUNCTION__);

        return hexWindow;
    }

    bool isRunning() {
        return !WindowShouldClose();
    }

    void update() {
        if (!hexWindow->active)
            return;

          if(WindowShouldClose()) {
            hexWindow->active = false;
          }

        BeginDrawing();
        ClearBackground(BLACK);
        uiManager->update();
        uiManager->draw();
        EndDrawing();

    }

    void dispose() {

      logger->logInfo("Disposing Hex", __FILE__, __LINE__, __FUNCTION__);
        CloseWindow();
        hexWindow.reset();
        uiManager->dispose();

        logger->logInfo("Hex disposed", __FILE__, __LINE__, __FUNCTION__);
    }

    void addUiElement(std::shared_ptr<UiElement> element) {
        uiManager->addElement(element);
    }
}
