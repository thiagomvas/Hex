//
// Created by thiagomv on 02/02/25.
//

#include <iostream>
#include <Hex.h>

int main(int argc, char **argv) {
  auto window = Hex::Init(argc, argv);

  while (Hex::IsRunning()) {
    Hex::Update();
  }
  Hex::Dispose();


  return 0;
}