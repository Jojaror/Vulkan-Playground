
#pragma once
#include "MyWindow.hpp"

class MyApp {

public:
  MyApp();
  ~MyApp() = default;
public:
  const unsigned int WIDTH;
  const unsigned int HEIGHT;
  const std::string TITLE;
public:
  void Run();
private:
  void Display();
private:
  MyWindow my_window_;
  float last_frame_, current_frame_, delta_frame_;
};
