#include<iostream>
using namespace std;
int isBeautiful(const std::string& str) {
    if (str.empty()) {
        return false; // Empty string is not beautiful
    }
    char prev = str[0];
    int operations = 0;
    for (size_t i = 1; i < str.length(); i++) {
        if (str[i] != prev) {
            prev = str[i];
        } else {
            // Need to change current character
            prev = (prev == '0') ? '1' : '0';
            operations++;
        }
    }
    return operations;
}

int main() {
    std::string str;
    std::cout << "Enter a binary string: ";
    std::cin >> str;

    cout<<isBeautiful(str)<<endl;

    return 0;
}