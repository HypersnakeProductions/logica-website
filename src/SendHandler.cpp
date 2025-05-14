#include "SendHandler.h"
#include <iostream>
#include <regex>

void handle_send(const std::string& line) {
    // Using double quotes for a standard string literal
    std::regex send_regex("^\\s*send\\s*\\(\\s*\"([^\"]+)\"\\s*\\)\\s*$");
    std::smatch match;

    if (std::regex_match(line, match, send_regex)) {
        std::string message = match[1];  // Capture the message inside the quotes
        std::cout << "[MESSAGE] " << message << std::endl;
    } else {
        std::cerr << "[ERROR] Invalid send syntax: " << line << std::endl;
    }
}
