//
// Created by Bojan Roško on 11/4/17.
//

#ifndef INC_42_TIME_CLASS_H
#define INC_42_TIME_CLASS_H

#include <chrono>
#include <iostream>

#include "common.h"

class Time {
public:
  explicit Time(std::chrono::system_clock::time_point time_point);
private:
  friend std::ostream& operator<<(std::ostream& out, const Time& time);

  std::chrono::system_clock::time_point time_point_;
};

std::ostream& operator<<(std::ostream& out, const Time& time);

Time CurrentTime();

#endif //INC_42_TIME_CLASS_H
