//
// Created by thiagomv on 02/02/25.
//

#include <iostream>
#include <Hex.h>
#include "raylib.h"
#include <UiButton.h>
#include <UiContainer.h>

void OnClick(Hex::UiButton* btn) {
  std::cout << "Button clicked!" << std::endl;
}


int main(int argc, char **argv) {

  auto window = Hex::init(argc, argv);

  auto btn = Hex::createButton({10, 10}, {100, 50}, RED, WHITE, "Click me!");
  btn->OnClick = OnClick;

  auto btn2 = Hex::createButton({10, 70}, {100, 50}, BLUE, WHITE, "Click me!");
  btn2->OnClick = OnClick;


  auto root = std::make_shared<Hex::UiContainer>();
  root->AddChild(btn);
  root->AddChild(btn2);

  Hex::addUiElement(root);

  while (!WindowShouldClose()) {
    Hex::update();
  }
  Hex::dispose();


  return 0;
}