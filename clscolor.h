#include <iostream>
#include <map>
#include <string>

// Function to print text in a specified color
void color(const std::string& text, const std::string& colorName) {
    // Map of color names to ANSI escape codes
    std::map<std::string, std::string> colors = {
        {"black", "30"},
        {"red", "31"},
        {"green", "32"},
        {"yellow", "33"},
        {"blue", "34"},
        {"magenta", "35"},
        {"cyan", "36"},
        {"white", "37"}
    };

    // Get the ANSI escape code for the specified color name
    auto it = colors.find(colorName);
    if (it != colors.end()) {
        // ANSI escape code to set text color
        std::cout << "\033[" << it->second << "m" << text << "\033[0m";
    } else {
        std::cerr << "Invalid color name: " << colorName << std::endl;
    }
}

// Function to print text with a specified background color
void bgcolor(const std::string& text, const std::string& bgColorName) {
    // Map of background color names to ANSI escape codes
    std::map<std::string, std::string> bgColors = {
        {"black", "40"},
        {"red", "41"},
        {"green", "42"},
        {"yellow", "43"},
        {"blue", "44"},
        {"magenta", "45"},
        {"cyan", "46"},
        {"white", "47"}
    };

    // Get the ANSI escape code for the specified background color name
    auto it = bgColors.find(bgColorName);
    if (it != bgColors.end()) {
        // ANSI escape code to set background color
        std::cout << "\033[" << it->second << "m" << text << "\033[0m";
    } else {
        std::cerr << "Invalid background color name: " << bgColorName << std::endl;
    }
}

// Function to clear the screen
void clear() {
    // ANSI escape code to clear the screen
    std::cout << "\033[2J\033[H";
}

