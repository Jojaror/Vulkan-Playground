
#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class MyWindow {

public:
  MyWindow(unsigned int width, unsigned int height, const std::string& title);
  ~MyWindow();
public:
  bool ShouldClose();
  void Events();
  void SwapBuffers();
  float GetTime();
private:
  void InitWindow();
private:
  unsigned int width_;
  unsigned int height_;
  std::string title_;
  GLFWwindow* window_;
};
