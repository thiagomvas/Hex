//
// Created by thiagomv on 02/02/25.
//

#include <iostream>
#include <Hex.h>

int main(int argc, char **argv) {
  auto window = Hex::Init(argc, argv);
  std::cout << "Window width: " << window->width << std::endl;
  std::cout << "Window height: " << window->height << std::endl;
  std::cout << "Window title: " << window->title << std::endl;
  std::cout << "Fullscreen: " << window->fullscreen << std::endl;
  return 0;
}