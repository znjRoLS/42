//
// Created by Bojan Roško on 11/2/17.
//

#include "string_split.h"

#include <sstream>

using namespace std;

namespace String {

  void Split(string original, string delimiter, vector<string>* dest) {
    size_t pos = 0;
    std::string token;
    while ((pos = original.find(delimiter)) != std::string::npos) {
      token = original.substr(0, pos);
      dest->push_back(token);
      original.erase(0, pos + delimiter.length());
    }
  };

}