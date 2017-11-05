//
// Created by Bojan Roško on 11/3/17.
//

#ifndef INC_42_LOGGING_H
#define INC_42_LOGGING_H

#include <iostream>

#include "ostream_newline.h"
#include "time_class.h"

enum LOG_LEVEL {
  DEBUG,
  INFO,
  ERROR
};

extern std::ostream& _LOG_OUTPUT;
extern LOG_LEVEL _LOG_LEVEL;

#define LOG(x) if (_LOG_LEVEL <= LOG_LEVEL::x) _LOG_OUTPUT << CurrentTime() << " - "#x": "
//#define LOG_DEBUG if (_LOG_LEVEL <= LOG_LEVEL::DEBUG) OStreamNewline(_LOG_OUTPUT) << CurrentTime() << " - DEBUG: "
//#define LOG_INFO  if (_LOG_LEVEL <= LOG_LEVEL::INFO ) OStreamNewline(_LOG_OUTPUT) << CurrentTime() << " -  INFO: "
//#define LOG_ERROR if (_LOG_LEVEL <= LOG_LEVEL::ERROR) OStreamNewline(_LOG_OUTPUT) << CurrentTime() << " - ERROR: "


#endif //INC_42_LOGGING_H