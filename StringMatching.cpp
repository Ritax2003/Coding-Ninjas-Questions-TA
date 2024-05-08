#include<iostream>
#include<string>
using namespace std;

int main(){
    string txt,pat;
    cin>>txt;
    cin>>pat;
    int N = txt.length();
    int M = pat.length();
    for (int i = 0; i <= N - M; ++i) {
            int j;
            for (j = 0; j < M; ++j) {
                    if (txt[i + j] != pat[j]) break;                                                        
             }
            if (j == M) {
                    cout << i << " ";
         }
     }
}