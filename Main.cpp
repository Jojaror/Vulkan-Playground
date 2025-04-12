
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "MyApp.hpp"

int main() {

  MyApp vulkan_playground;
  try {
    vulkan_playground.Run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
