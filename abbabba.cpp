#include <bits/stdc++.h>
using namespace std;

bool checkAB(char input[]) {
    // Calculate the length of the input array
    int n = sizeof(input);

    // If the string is empty, return false
    if (n == 0) {
        return false;
    }

    // Rule a: The string begins with an 'a'
    if (input[0] != 'a') {
        return false;
    }

    // Rule b: Each 'a' is followed by nothing or an 'a' or "bb"
    for (int i = 1; i < n; i++) {
        if (input[i] == 'a') {
            continue; // 'a' can be followed by another 'a'
        } else if (input[i] == 'b') {
            // Check if 'b' is followed by another 'b' or an 'a'
            if (i + 1 < n && input[i + 1] == 'b') {
                i++; // Skip the next character as it is part of "bb"
                continue;
            } else if (i + 1 == n || input[i + 1] == 'a') {
                continue; // 'b' can be followed by 'a' or nothing
            } else {
                return false; // If 'b' is followed by any other character, return false
            }
        } else {
            return false; // If any other character is encountered, return false
        }
    }

    return true; // If all rules are satisfied, return true
}

int main() {
    char input1[] = "abba";    // Should return true
    char input2[] = "aba";     // Should return false
    char input3[] = "abab";    // Should return true
    char input4[] = "abbaabb"; // Should return true

    cout << std::boolalpha << checkAB(input1) << endl;
    cout << std::boolalpha << checkAB(input2) << endl;
    cout << std::boolalpha << checkAB(input3) << endl;
    cout << std::boolalpha << checkAB(input4) << endl;

    return 0;
}
