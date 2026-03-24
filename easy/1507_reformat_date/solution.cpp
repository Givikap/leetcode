#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

class Solution {
public:
  std::string reformatDate(std::string date) {
    std::unordered_map<std::string, int> monthsMap = {
        {"Jan", 1}, {"Feb", 2},  {"Mar", 3},  {"Apr", 4},
        {"May", 5}, {"Jun", 6},  {"Jul", 7},  {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12},
    };

    std::istringstream iss(date);
    std::string token;

    std::getline(iss, token, ' ');
    token.erase(token.size() - 2);
    int day = std::stoi(token);

    std::getline(iss, token, ' ');
    int month = monthsMap[token];

    std::string year;
    std::getline(iss, year, ' ');

    std::ostringstream oss;
    oss << year << '-' << std::setw(2) << std::setfill('0') << month << '-'
        << std::setw(2) << std::setfill('0') << day;

    return oss.str();
  }
};
