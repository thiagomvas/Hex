
#ifndef HEXWINDOW_H
#define HEXWINDOW_H

namespace Hex {
struct HexWindow {
  int width;
  int height;
  const char *title;
  bool fullscreen;

  bool active;
  };
};

#endif //HEXWINDOW_H
