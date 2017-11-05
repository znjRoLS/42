//
// Created by Bojan Roško on 11/4/17.
//

#include "logging.h"

// Default logging output
std::ostream& _LOG_OUTPUT = std::cout;

// Default logging level
DEFINE_FLAG_INT(CURRENT_LOG_LEVEL, 2, "Current log level");
