#include "validation.h"
#include <cctype>
#include <limits>

void Validation::clearInput() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

bool Validation::isNumber(const std::string& str, bool allowNegative) {
    if (str.empty()) return false;
    size_t start = 0;
    if (allowNegative && str[0] == '-') {
        if (str.size() == 1) return false;
        start = 1;
    }
    for (size_t i = start; i < str.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) return false;
    }
    return true;
}

bool Validation::isDouble(const std::string& str, bool allowNegative) {
    if (str.empty()) return false;
    size_t start = 0;
    if (allowNegative && str[0] == '-') {
        if (str.size() == 1) return false;
        start = 1;
    }
    bool pointFound = false;
    bool digitFound = false;
    for (size_t i = start; i < str.size(); ++i) {
        char c = str[i];
        if (c == '.') {
            if (pointFound) return false;
            pointFound = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(c))) {
            digitFound = true;
        }
        else {
            return false;
        }
    }
    return digitFound;
}

bool Validation::validateNumberString(const std::string& line, std::vector<double>& numbers) {
    std::stringstream ss(line);
    std::vector<double> temp;
    std::string token;
    int pos = 1;
    while (ss >> token) {
        if (!isDouble(token)) {
            std::cout << "Ошибка! '" << token << "' не число (поз." << pos << ")\n";
            return false;
        }
        try {
            temp.push_back(std::stod(token));
        }
        catch (...) {
            std::cout << "Ошибка! Число '" << token << "' слишком большое\n";
            return false;
        }
        ++pos;
    }
    if (temp.size() < 2) {
        std::cout << "Ошибка! Введено " << temp.size() << " чисел, нужно минимум 2\n";
        return false;
    }
    numbers = temp;
    return true;
}

bool Validation::isFileValid(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;
    std::string token;
    bool hasNumber = false;
    while (file >> token) {
        if (!isNumber(token)) return false;
        hasNumber = true;
    }
    return hasNumber;
}

bool Validation::isFileValidDouble(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return false;
    std::string token;
    bool hasNumber = false;
    int pos = 1;
    while (file >> token) {
        if (!isDouble(token)) {
            std::cout << "Файл содержит не число на позиции " << pos << ": " << token << std::endl;
            return false;
        }
        hasNumber = true;
        ++pos;
    }
    return hasNumber;
}

std::string Validation::getValidFile() {
    std::string fname;
    while (true) {
        std::cin >> fname;
        std::ifstream test(fname);
        if (!test) {
            std::cout << "Файл не найден. Повторите: ";
            continue;
        }
        test.close();
        if (isFileValid(fname)) return fname;
        std::cout << "Файл содержит не числа. Повторите: ";
    }
}

std::string Validation::getValidFileDouble() {
    std::string fname;
    while (true) {
        std::cin >> fname;
        std::ifstream test(fname);
        if (!test) {
            std::cout << "Файл не найден. Повторите: ";
            continue;
        }
        test.close();
        if (isFileValidDouble(fname)) return fname;
        std::cout << "Файл содержит не числа. Повторите: ";
    }
}

int Validation::getInt() {
    std::string input;
    while (true) {
        std::cin >> input;
        if (!isNumber(input)) {
            std::cout << "Ошибка! Введите целое число: ";
            clearInput();
            continue;
        }
        try {
            return std::stoi(input);
        }
        catch (...) {
            std::cout << "Слишком большое число: ";
            clearInput();
        }
    }
}

int Validation::getIntMin(int minValue) {
    while (true) {
        int val = getInt();
        if (val >= minValue) return val;
        std::cout << "Ошибка! Число должно быть >= " << minValue << ": ";
    }
}

int Validation::getIntRange(int minValue, int maxValue) {
    while (true) {
        int val = getInt();
        if (val >= minValue && val <= maxValue) return val;
        std::cout << "Ошибка! Введите число от " << minValue << " до " << maxValue << ": ";
    }
}

int Validation::getInt(const std::string& prompt) {
    std::cout << prompt;
    return getInt();
}

int Validation::getIntMin(const std::string& prompt, int minValue) {
    std::cout << prompt;
    return getIntMin(minValue);
}

int Validation::getIntRange(const std::string& prompt, int minValue, int maxValue) {
    std::cout << prompt;
    return getIntRange(minValue, maxValue);
}