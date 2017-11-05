//
// Created by Bojan Roško on 11/5/17.
//

#include "flags.h"

std::unordered_map<string, string> flag_descriptions_;
std::unordered_map<string, string*> flags_string_;
std::unordered_map<string, int*> flags_int_;

void ProcessFlags(int* argc, char** argv[]) {
  int newargc = 1;

  for(int i = 1; i <= *argc; i++) {

  }
}
