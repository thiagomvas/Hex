#include "HexInitArgs.h"
#include <cstring>
#include <cstdlib>

namespace Hex {
    HexInitArgs parseArgs(int argc, char **argv) {
        HexInitArgs args;

        for(int i = 0; i < argc; i++) {
            if(strcmp(argv[i], "-w") == 0) {
                args.width = atoi(argv[i + 1]);
            } else if(strcmp(argv[i], "-h") == 0) {
                args.height = atoi(argv[i + 1]);
            } else if(strcmp(argv[i], "-t") == 0) {
                args.title = argv[i + 1];
            } else if(strcmp(argv[i], "-f") == 0) {
                args.fullscreen = true;
            }
        }

        return args;
    }
}