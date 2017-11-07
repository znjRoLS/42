//
// Created by Bojan Roško on 11/4/17.
//

#ifndef INC_42_OSTREAM_NEWLINE_H
#define INC_42_OSTREAM_NEWLINE_H

#include <iostream>

#include "common.h"

// Adds newline to the output when deleted.
// Why is this class created? Example
//   OStreamNewline(std::cout) << "test" << "test2";
// will also add newline at the end.

class OStreamNewline{
public:
  explicit OStreamNewline(std::ostream& output);
  ~OStreamNewline();
private:
  template<typename T>
  friend std::ostream& operator<<(OStreamNewline output, T& object);
  template<typename T>
  friend std::ostream& operator<<(OStreamNewline output, T object);

  std::ostream& output_;
};

template<typename T>
std::ostream& operator<<(OStreamNewline output, T& object) {
  output.output_ << object;
  return output.output_;
}

template<typename T>
std::ostream& operator<<(OStreamNewline output, T object) {
  output.output_ << object;
  return output.output_;
}

#endif //INC_42_OSTREAM_NEWLINE_H
