#include <bits/stdc++.h>

using namespace std;

int main(){
    int count = 0;
    string input;
    while(getline(cin, input)){
        while(input.find('"') != string::npos){
            input.replace(input.find('"'), 1, count % 2 == 1 ? "''" : "``");
            count++;
        }
        cout << input << endl;
    }
    return 0;
}
