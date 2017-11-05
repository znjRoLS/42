//
// Created by Bojan Roško on 11/2/17.
//

#include <string>
#include <vector>

#include "base/base.h"
#include "strings/string_split.h"

using namespace std;

int main(int argc, char *argv[]) {

  string test_string = "test.test2.test3";
  vector<string> test_vector;
  String::Split(test_string, ".", &test_vector);

  LOG(INFO) << "neki info1";
  LOG(ERROR) << "neki error";

  _LOG_LEVEL = LOG_LEVEL::DEBUG;

  LOG(INFO) << "neki info2";

  return 0;
}