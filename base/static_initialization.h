//
// Created by Bojan Roško on 11/5/17.
//

#ifndef INC_42_STATIC_INITIALIZATION_H
#define INC_42_STATIC_INITIALIZATION_H

#include <functional>

#include "common.h"

struct StaticInitializator {
public:
  explicit StaticInitializator(std::function<void(void)> init_function);
};

#define CONCAT(x,y,z) x ## y ## z
#define CONCAT_EXPAND(x,y,z) CONCAT(x,y,z)

// use this only with truly unique names
#define STATIC_INITIALIZATION(unique_name, lambda) \
StaticInitializator CONCAT_EXPAND(static_initializator_, unique_name, __COUNTER__)(lambda);

#endif //INC_42_STATIC_INITIALIZATION_H
