//
// Created by Bojan Roško on 11/5/17.
//

#ifndef INC_42_FLAGS_H
#define INC_42_FLAGS_H

#include <unordered_map>

#include "common.h"
#include "static_initialization.h"

extern std::unordered_map<string, string> flag_descriptions_;
extern std::unordered_map<string, string*> flags_string_;
extern std::unordered_map<string, int*> flags_int_;

//#define DEFINE_FLAG(type, name, default_value, description) \
//  type FLAG_##name = default_value; \
//  STATIC_INITIALIZATION(name, ([](void) { \
//    flag_descriptions_.insert({#name, description}); \
//    flags_.insert({#name, &FLAG_##name}); \
//  }))

#define DEFINE_FLAG_STRING(name, default_value, description) \
  string FLAG_##name = default_value; \
  STATIC_INITIALIZATION(name, ([](void) { \
    flags_string_.insert({#name, &FLAG_##name}); \
    flag_descriptions_.insert({#name, description}); \
  }))

#define DECLARE_FLAG_STRING(name) \
  extern string FLAG_##name;

#define DEFINE_FLAG_INT(name, default_value, description) \
  int FLAG_##name = default_value; \
  STATIC_INITIALIZATION(name, ([](void) { \
    flags_int_.insert({#name, &FLAG_##name}); \
    flag_descriptions_.insert({#name, description}); \
  }))

#define DECLARE_FLAG_INT(name) \
  extern int FLAG_##name;

// Processes all flags from the input
void ProcessFlags(int* argc, char***argv);


#endif //INC_42_FLAGS_H
