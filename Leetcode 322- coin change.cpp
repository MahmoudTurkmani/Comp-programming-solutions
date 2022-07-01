#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int solve(vector<int> &coins, int amount){
    if(amount == 0) return 0;
    if(amount < 0) return 100000;
    if(memo[amount] != INT_MAX) return memo[amount];
    int best = INT_MAX;
    for(auto coin: coins){
        best = min(best, solve(coins, amount - coin) + 1);
    }
    memo[amount] = best;
    return best;
}

int coinChange(vector<int>& coins, int amount) {
    memo = vector<int>(amount+1, INT_MAX);
    int answer = solve(coins, amount);
    return answer > 99999 ? -1 : answer;
}

int main(){
    vector<int> coins = {1, 6, 7};
    int amount = 20;
    printf("Minimum number of coins to reach %i is: %i", amount, solve(coins, amount));
    return 0;
}
