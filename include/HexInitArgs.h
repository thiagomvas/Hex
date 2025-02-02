#ifndef HEXINITARGS_H
#define HEXINITARGS_H

namespace Hex {
    struct HexInitArgs {
        int width = 800;
        int height = 600;
        const char *title = "Hex Window";
        bool fullscreen = false;
    };

    HexInitArgs parseArgs(int argc, char **argv);
}

#endif //HEXINITARGS_H
