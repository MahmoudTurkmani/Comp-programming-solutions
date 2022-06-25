#include <bits/stdc++.h>

using namespace std;

int getChainLength(int n){
    int chainLength = 0;
    while(n != 1){
        if(n % 2 == 1){
            n = 3*n + 1;
        }
        else{
            n /= 2;
        }
        chainLength++;
    }
    return chainLength;
}

int main()
{
    int num1, num2;
    while(cin >> num1 >> num2){
        int maxChain = 0;
        int x = num1 > num2 ? num2 : num1;
        int y = num1 > num2 ? num1 : num2;
        for(int i = x; i <= y; i++){
            int chainLength = getChainLength(i);
            maxChain = chainLength > maxChain ? chainLength : maxChain;
        }
        printf("%i %i %i\n", num1, num2, maxChain+1);
    }
    return 0;
}
