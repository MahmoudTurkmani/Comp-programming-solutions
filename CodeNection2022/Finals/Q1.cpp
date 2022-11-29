#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n >> m;
    string longString;
    string word;
    cin >> longString >> word;
    bool possible = true;
    for(char letter : word){
        size_t position = longString.find(letter);
        if(position == string::npos){
            possible = false;
            break;
        }
        else{
            longString.erase(position, 1);
        }
    }
    possible == true ? cout << "YES" : cout << "NO";
    return 0;
}