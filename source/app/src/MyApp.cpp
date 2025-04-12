
#include "MyApp.hpp"

MyApp::MyApp()
: WIDTH(800), HEIGHT(600), TITLE("Vulkan Playground"),
my_window_(WIDTH, HEIGHT, TITLE.c_str()) {}

void MyApp::Run() {

  last_frame_ = my_window_.GetTime();
  while (!my_window_.ShouldClose()) {
    current_frame_ = my_window_.GetTime();
    my_window_.Events();
    Display();
    my_window_.SwapBuffers();
  }
}

void MyApp::Display() {

  delta_frame_ = current_frame_ - last_frame_;
  last_frame_ = current_frame_;
  //my_gui_.Display(delta_frame_, window_);
}
