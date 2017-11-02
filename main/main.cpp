//
// Created by Bojan Roško on 11/2/17.
//

#include <string>
#include <vector>

#include "strings/string_split.h"

using namespace std;

int main(int argc, char *argv[]) {

  string test_string = "test.test2.test3";
  vector<string> test_vector;
  String::Split(test_string, ".", &test_vector);

  return 0;
}