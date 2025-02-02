
#include "Hex.h"
#include "HexWindow.h"
#include "HexInitArgs.h"
#include <memory>
#include "raylib.h"

namespace Hex {

    std::shared_ptr<HexWindow> Init(int argc, char **argv) {
        // Initialize hexWindow here
        hexWindow = std::make_shared<HexWindow>();

        auto args = parseArgs(argc, argv);
        hexWindow->width = args.width;
        hexWindow->height = args.height;
        hexWindow->title = args.title;
        hexWindow->fullscreen = args.fullscreen;

        InitWindow(hexWindow->width, hexWindow->height, hexWindow->title);

        SetExitKey(0);

        hexWindow->active = true;

        if (hexWindow->fullscreen) {
            ToggleFullscreen();
        }

        return hexWindow;
    }

    bool IsRunning() {
        return hexWindow->active;
    }

    void Update() {
        if (hexWindow->active) {
          if(WindowShouldClose()) {
            hexWindow->active = false;
          }
        }
    }

    void Dispose() {
        CloseWindow();
        hexWindow->active = false;
        hexWindow.reset();
    }
}
