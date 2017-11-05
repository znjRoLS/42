//
// Created by Bojan Roško on 11/4/17.
//

#include "time_class.h"

#include <iomanip>

Time::Time(std::chrono::system_clock::time_point time_point):
    time_point_(time_point) {

}

std::ostream& operator<<(std::ostream& out, const Time& time) {
  std::time_t now_c = std::chrono::system_clock::to_time_t(time.time_point_);
  out << std::put_time(std::localtime(&now_c), "%F %T");
  return out;
}

Time CurrentTime() {
  return Time(std::chrono::system_clock::now());
}

