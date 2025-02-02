#ifndef HEX_H
#define HEX_H

#include <memory>
#include "HexWindow.h"

namespace Hex {

// private reference to the singleton instance
static std::shared_ptr<HexWindow> hexWindow;


    std::shared_ptr<HexWindow> Init(int argc, char **argv);
}

#endif //HEX_H
