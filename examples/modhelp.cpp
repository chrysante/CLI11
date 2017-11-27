// Modify the help print so that argument values are accessible 
// Note that this will not shortcut `->required` and other similar options

#include "CLI/CLI.hpp"

#include <iostream>

int main(int argc, char **argv) {
  CLI::App test;

  // Remove help flag because it shortcuts all processing
  test.set_help_flag();

  // Add custom flag that activates help
  auto help = test.add_flag("-h,--help", "Request help");

  std::string some_option;
  test.add_option("-a", some_option, "Some description");
  
  try {
    test.parse(argc, argv);
    if(*help)
        throw CLI::CallForHelp();
  } catch (const CLI::Error &e) {
    std::cout << "Option string:" << some_option << std::endl;
    return test.exit(e);
  }

  std::cout << "Option string:" << some_option << std::endl;
  return 0;
}
