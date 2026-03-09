#include <Types.hpp>
#include <string>
using namespace std;

void print_prompt() { cout << "db >"; }

int main() {

  InputBuffer *input_buffer = new InputBuffer();

  while (true) {
    cout << "db >";
    input_buffer->read_input();
    if (input_buffer->buffer == ".exit")
      return EXIT_SUCCESS;
    else {
      std::cout << "Unrecognized command: " << input_buffer->buffer
                << std::endl;
    }
  }
  delete input_buffer;
  return 0;
}