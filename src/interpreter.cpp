#include "interpreter.h"
#include "SendHandler.h"
#include <iostream>
#include <algorithm>
#include <cctype>

void interpret_line(const std::string& line) {
    // Skip empty or whitespace-only lines
    if (line.find_first_not_of(" \t\n\v\f\r") == std::string::npos) return;

    // Trim leading whitespace
    std::string trimmed = line;
    trimmed.erase(trimmed.begin(), std::find_if(trimmed.begin(), trimmed.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));

    if (trimmed.rfind("send(", 0) == 0) {
        handle_send(trimmed);
    } else {
        std::cerr << "[ERROR] Unknown command: " << trimmed << std::endl;
    }
}
