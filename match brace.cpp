#include <iostream>
#include <stack>
#include <string>
using namespace std;
int countBracketReversals(const std::string& input) {
    std::stack<char> s;
    if (input.size() % 2 != 0) {
        return -1; // Not possible to balance an odd-length string
    }

    int i = 0, count = 0;
    while (i < input.size()) {
        if (input[i] == '{') {
            s.push('{');
        } else {
            if (s.empty()) {
                count++; // Need to reverse current '}' to '{'
                s.push('{'); // Simulate reversal
            } else {
                s.pop(); // Match found, remove '{' from stack
            }
        }
        i++;
    }

    // At this point, stack contains only unmatched '{' (if any)
    // To balance, we need equal number of '{' and '}', or 2 reversals for each pair
    // So, total count is half of the stack size
    count += s.size() / 2;

    return count;
}

int main() {
    std::string input = "{{{{}}";
    int result = countBracketReversals(input);
    if (result == -1) {
        std::cout << result << std::endl;
    } else {
        cout << result << std::endl;
    }
    return 0;
}