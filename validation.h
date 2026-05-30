#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

namespace Validation {
    void clearInput();
    bool isNumber(const std::string& str, bool allowNegative = true);
    bool isDouble(const std::string& str, bool allowNegative = true);
    bool validateNumberString(const std::string& line, std::vector<double>& numbers);
    bool isFileValid(const std::string& filename);
    bool isFileValidDouble(const std::string& filename);
    std::string getValidFile();
    std::string getValidFileDouble();
    int getInt();
    int getIntMin(int minValue);
    int getIntRange(int minValue, int maxValue);
    int getInt(const std::string& prompt);
    int getIntMin(const std::string& prompt, int minValue);
    int getIntRange(const std::string& prompt, int minValue, int maxValue);
}