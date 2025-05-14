#include "runner.h"
#include <iostream>
#include <string>

const std::string LANGVERSION = "Logica v1.0.0";
const std::string COMMANDVERSION = "Logica Executable v1.0.0";

void show_help() {
    std::cout << "\n"
              << "\n"
              << "Usage: logica [option] <script.lg>\n\n"
              << "Options:\n"
              << "  --help       Show this help message\n"
              << "  --version    Show version information\n"
              << "\nExamples:\n"
              << "  logica script.lg\n"
              << "  logica --help\n"
              << "  logica --version\n"
              << "\n"
              << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "[ERROR] No arguments provided. Use --help for usage.\n";
        return 1;
    }

    std::string arg1 = argv[1];

    if (arg1 == "--help") {
        show_help();
    } else if (arg1 == "--version") {
        std::cout << LANGVERSION << std::endl;
        std::cout << COMMANDVERSION << std::endl;
    } else if (arg1.find("--") != 0) {  // Check if the string doesn't start with "--"
        // Assume it's a filename
        run_script(arg1);
    } else {
        std::cout << "Unknown command: " << arg1 << std::endl;
    }

    return 0;
}
