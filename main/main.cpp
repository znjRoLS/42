//
// Created by Bojan Roško on 11/2/17.
//

#include <string>
#include <vector>

#include "base/base.h"
#include "strings/string_split.h"

DEFINE_FLAG_STRING(test_flag, "default_val", "desription");

DECLARE_FLAG_INT(CURRENT_LOG_LEVEL);

using namespace std;

int main(int argc, char *argv[]) {

  FLAG_CURRENT_LOG_LEVEL  = LOG_LEVEL::DEBUG;

  LOG(ERROR) << FLAG_test_flag << std::endl;

  ProcessFlags(&argc, &argv);

  LOG(ERROR) << FLAG_test_flag;

  string test_string = "test.test2.test3";
  vector<string> test_vector;
  String::Split(test_string, ".", &test_vector);

  LOG(INFO) << "neki info1";
  LOG(ERROR) << "neki error";

  FLAG_CURRENT_LOG_LEVEL = LOG_LEVEL::DEBUG;

  LOG(INFO) << "neki info2";

  return 0;
}