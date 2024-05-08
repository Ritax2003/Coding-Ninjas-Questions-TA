#include<bits/stdc++.h>
using namespace std;
string removeConsecutiveDuplicates(string str) 
{
    
    for (int j =0; j < str.size(); j++){
        int i = j;
        while (i+1 < str.size() && str[i] == str[i+1]){
            str.erase((i+1),1);
        }
    }
    return str;
}
int main() {
    std::string str = "aaabbbcccdddeee";
    std::cout << "Original string: " << str << std::endl;
    std::cout << "String after removing consecutive duplicates: " << removeConsecutiveDuplicates(str) << std::endl;
    return 0;
}