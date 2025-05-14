#include "runner.h"
#include "interpreter.h"
#include <iostream>
#include <fstream>
#include <string>

void run_script(const std::string& path) {

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[ERROR] Could not open script file: " << path << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // You need to make sure that the interpret_line function is defined elsewhere
        interpret_line(line);
    }

    file.close();
}

