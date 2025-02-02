
#include "Hex.h"
#include "HexWindow.h"
#include "HexInitArgs.h"
#include <memory>

namespace Hex {

    // Static ensures internal linkage to Hex.cpp

    std::shared_ptr<HexWindow> Init(int argc, char **argv) {
        // Initialize hexWindow here
        hexWindow = std::make_shared<HexWindow>();

        auto args = parseArgs(argc, argv);
        hexWindow->width = args.width;
        hexWindow->height = args.height;
        hexWindow->title = args.title;
        hexWindow->fullscreen = args.fullscreen;


        return hexWindow;
    }
}
