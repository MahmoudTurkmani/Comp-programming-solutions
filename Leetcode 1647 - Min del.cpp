#include <bits/stdc++.h>

using namespace std;

// driver program

int main(){
	string s = "abcdaaabcs";
	printf("Minimum deletions: %i", minDeletions(s));
	return 0;	
}

// note: this implementation is very time consuming O(n^2)
// try finding another one

int minDeletions(string s) {
     int answer = 0;
     map<char, int> frequency;
     // iterate and get amount of each
     for(auto ch: s){
         frequency[ch] += 1;
     }
     vector<int> count;
     for(auto entry: frequency){
         count.push_back(entry.second);
     }
     // check for matches
     // still matches? go back to prev stop
     for(int x = 0; x < count.size(); x++){
         for(int y = 0; y < count.size(); y++){
             if(x == y){
                 continue;
             }
             if(count[x] == count[y] && count[x] > 0){
                 answer += 1;
                 count[x] -= 1;
                 x = 0;
                 break;
             }
         }
     }
     // if not, return count
     return answer;
}