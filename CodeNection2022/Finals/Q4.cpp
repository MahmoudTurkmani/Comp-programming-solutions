#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(vector<int>, int, int, bool);
int getinrow(vector<int>, int, int);

int answer = 0;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, types, canType;
    cin >> n >> types >> canType;
    vector<int> cans = vector<int>(n);
    for(int x = 0; x < n; x++){
        cin >> cans[x];
    }
    solve(cans, 0, canType, false);
    cout << answer;
    return 0;
}

void solve(vector<int> cans, int packed, int canType, bool done){
    if(done || cans.size() == 0){
        if(packed > answer){
            answer = packed;
        }
        return;
    }
    bool noChange = true;
    int pos = 0;
    int count = 0;
    for(vector<int>::iterator it = cans.begin(); it != cans.end(); it++){
        count = getinrow(cans, cans.size(), pos);
        if(count > 2){
            packed += count;
            noChange = false;
            break;
        }
        else if(*it == canType && count+1 == 3){
                vector<int> temp(cans);
                vector<int>::iterator it1 = temp.begin()+pos;
                vector<int>::iterator it2 = temp.begin()+pos+count;
                temp.erase(it1, it2);
                solve(temp, packed+2, 0, false);
                pos++;
        }
        else{
            pos++;
        }
    }
    if(!noChange){
        vector<int>::iterator it1 = cans.begin()+pos;
        vector<int>::iterator it2 = cans.begin()+pos+count;
        cans.erase(it1, it2);
    }
    solve(cans, packed, canType, noChange);
}

int getinrow(vector<int> row, int n, int pos){
    int length = 1;
    for(int i = pos; i < n-2; n++){
        if(row[pos] == row[pos+1]){
            pos++;
            length++;
        }
        else{
            break;
        }
    }
    return length;
}