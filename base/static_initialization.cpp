//
// Created by Bojan Roško on 11/5/17.
//

#include "static_initialization.h"

StaticInitializator::StaticInitializator(std::function<void(void)> init_function) {
  init_function();
}
