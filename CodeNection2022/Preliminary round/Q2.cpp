#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // The varibales for N, M, and T and assign
    int N, M, T;
    cin >> T >> N >> M;
    // Vectors to hold the segments of N and M
    vector<pair<int, int>> vn = vector<pair<int, int>>(N);
    vector<pair<int, int>> vm = vector<pair<int, int>>(M);
    // the final answer
    int ans = 0;
    // pointers for the position of N and M in their respective arrays
    int np = 0, mp = 0; 
    // Getting all the segments of N
    for(int x = 0; x < N; x++){
        cin >> vn[x].first >> vn[x].second;
    }
    // Getting all the segments of M
    for(int x = 0; x < M; x++){
        cin >> vm[x].first >> vm[x].second;
    }
    // Current time in N and M
    int tempn = 1;
    int tempm = 1;
    for(int time = 1; time <= T; time++){
        // Segment completed?
        if(tempn > vn[np].first){
            np++;
            tempn = 1;
        }
        // Segment completed?
        if(tempm > vm[mp].first){
            mp++;
            tempm = 1;
        }
        // Is maverick above the limit?
        if(vn[np].second < vm[mp].second){
            int temp = vm[mp].second - vn[np].second;
            if(temp > ans){
                ans = temp;
            }
        }
        
        // Update clocks
        tempn++;
        tempm++;
    }
    // Return the answer
    cout << ans;
    return 0;
}