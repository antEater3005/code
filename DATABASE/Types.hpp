#include <iostream>
#include <string>
using namespace std;

class InputBuffer {
public:
  string buffer;

  void read_input() { getline(cin, buffer); }
};