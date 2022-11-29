#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    // int z;
    cin >> N >> Q;
    vector<int> ns = vector<int>(N);
    for(int x = 0; x < N; x++){
        cin >> ns[x];
    }
    vector<int> nq = vector<int>(Q);
    for(int x = 0; x < Q; x++){
        cin >> nq[x];
    }
    for(int query : nq){
        find(ns.begin(), ns.end(), query) == ns.end() ? cout << "No\n" : cout << "Yes\n";
    }
    // for(int x = 0; x < Q; x++){
    //     cin >> z;
    //     find(ns.begin(), ns.end(), z) == ns.end() ? cout << "No\n" : cout << "Yes\n";
    // }
    return 0;
}