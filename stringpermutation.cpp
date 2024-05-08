#include <iostream>
#include <unordered_map>

bool isPermutation(char input1[], char input2[]) {
    std::unordered_map<char, int> charCount;

    // Count characters in input1
    for (int i = 0; input1[i] != '\0'; i++) {
        charCount[input1[i]]++;
    }

    // Decrement count for characters in input2
    for (int i = 0; input2[i] != '\0'; i++) {
        charCount[input2[i]]--;
    }

    // Check if all counts are zero
    for (const auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    char input1[] = "sinrtg";
    char input2[] = "string";

    if (isPermutation(input1, input2)) {
        std::cout << "The arrays are permutations of each other." << std::endl;
    } else {
        std::cout << "The arrays are not permutations of each other." << std::endl;
    }

    return 0;
}
