//
// Created by Bojan Roško on 11/3/17.
//

#ifndef INC_42_LOGGING_H
#define INC_42_LOGGING_H

#include <iostream>

#include "common.h"
#include "flags.h"
#include "ostream_newline.h"

enum LOG_LEVEL {
  DEBUG,
  INFO,
  ERROR
};

extern std::ostream& _LOG_OUTPUT;
DECLARE_FLAG_INT(CURRENT_LOG_LEVEL);

#define LOG(x) if (FLAG_CURRENT_LOG_LEVEL <= LOG_LEVEL::x) OStreamNewline(_LOG_OUTPUT) << CurrentTime() << " - "#x": "

#endif //INC_42_LOGGING_H
