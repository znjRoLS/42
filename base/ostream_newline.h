//
// Created by Bojan Roško on 11/4/17.
//

#ifndef INC_42_OSTREAM_NEWLINE_H
#define INC_42_OSTREAM_NEWLINE_H

#include <iostream>

// Adds newline to the output when deleted.
// Why is this class created? Example
//   OStreamNewline(std::cout) << "test" << "test2";
// will also add newline at the end.

class OStreamNewline: public std::ostream {
public:
  explicit OStreamNewline(std::ostream& output);
  ~OStreamNewline();
private:
  template<typename T>
  friend OStreamNewline& operator<<(OStreamNewline& output, T object);

  std::ostream& output_;

};

template<typename T>
OStreamNewline& operator<<(OStreamNewline& output, T object) {
  output.output_ << object;
  return output;
}

#endif //INC_42_OSTREAM_NEWLINE_H
