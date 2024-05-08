#include <iostream>

#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;
int countDigits(int n){
	if(n!=0) return 1+countDigits(n/10);
	else return 0;	
}
class Runner
{
    int N;

    public:
    
 void takeInput()
    {
        cin >> N;
    }

    void execute()
    {
        int ans = countDigits(N);
    }
     void executeAndPrintOutput()
    {

        int ans = countDigits(N);
        cout << ans << endl;
    }
};

int main()
{
    
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}