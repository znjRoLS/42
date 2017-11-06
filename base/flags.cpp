//
// Created by Bojan Roško on 11/5/17.
//

#include <vector>
#include <iostream>

#include "flags.h"

std::unordered_map<string, string>& flag_descriptions() {
  static std::unordered_map<string, string> internal;
  return internal;
};

std::unordered_map<string, string*>& flags_string() {
  static std::unordered_map<string, string*> internal;
  return internal;
};

std::unordered_map<string, int*>& flags_int() {
  static std::unordered_map<string, int*> internal;
  return internal;
};

//std::unordered_map<string, string> flag_descriptions_;
//std::unordered_map<string, string*> flags_string_;
//std::unordered_map<string, int*> flags_int_;

void ProcessFlags(int* argc, char** argv[]) {
  int newargc = 1;
  std::vector<string> arguments;

  for(int i = 1; i < *argc; i++) {
    string temp((*argv)[i]);
    if (temp.size() > 2 && temp[0] == '-' && temp[1] == '-' && temp[2] != '-' && temp.find('=') != temp.npos) { // it's a flag!
      int equal_sign_position = temp.find('=');
      string name = temp.substr(2, equal_sign_position - 2);
      string value = temp.substr(equal_sign_position + 1);
      if (flags_string().find(name) != flags_string().end()) { // flag is a string
        *(flags_string()[name]) = value;
      } else if (flags_int().find(name) != flags_int().end()) { // flag is a int
        *(flags_int()[name]) = std::stoi(value);
      } else {
        throw "Flag not defined!";
      }
    } else {
      (*argv)[newargc] = (*argv)[i];
      newargc++;
    }
  }
  *argc = newargc;
}
