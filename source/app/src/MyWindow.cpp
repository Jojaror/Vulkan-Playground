
#include "MyWindow.hpp"

MyWindow::MyWindow(unsigned int width, unsigned int height, const std::string& title)
: width_(width), height_(height), title_(title), window_(nullptr) {

  InitWindow();
}

MyWindow::~MyWindow() {

  glfwDestroyWindow(window_);
  glfwTerminate();
}

void MyWindow::InitWindow() {

  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  window_ = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);
}

bool MyWindow::ShouldClose() {

  return glfwWindowShouldClose(window_);
}

void MyWindow::Events() {

  glfwPollEvents();
}

void MyWindow::SwapBuffers() {

  glfwSwapBuffers(window_);
}

float MyWindow::GetTime() {

  return static_cast<float>(glfwGetTime());
}
