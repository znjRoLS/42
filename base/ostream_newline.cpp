//
// Created by Bojan Roško on 11/4/17.
//

#include "ostream_newline.h"

#include <iostream>

OStreamNewline::OStreamNewline(std::ostream &output):
    output_(output) {
}

OStreamNewline::~OStreamNewline() {
  output_ << std::endl;
}