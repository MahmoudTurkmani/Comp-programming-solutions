#include <bits/stdc++.h>

using namespace std;

    vector<vector<string>> answer;

    bool column(vector<string> board, int row, int col){
        bool attack = false;
        for(int x = 0; x < board.size(); x++){
            if(x == row){
                continue;
            }
            else{
                if(board[x][col] == 'Q'){
                    attack = true;
                    break;
                }
            }
        }
        return attack;
    }

    bool diagonal(vector<string> board, int row, int col){
        bool attack = false;
        // go down right
        int count = 1;
        while(true){
            if(row + count >= board.size() || col + count >= board.size()){
                break;
            }
            else{
                if(board[row+count][col+count] == 'Q'){
                    attack = true;
                    break;
                }
            }
            count++;
        }
        // go up left
        count = 1;
        while(true && !attack){
            if(row - count < 0 || col - count < 0){
                break;
            }
            else{
                if(board[row-count][col-count] == 'Q'){
                    attack = true;
                    break;
                }
            }
            count++;
        }
        return attack;
    }

    bool reverseDiagonal(vector<string> board, int row, int col){
        bool attack = false;
        // go down left
        int count = 1;
        while(true){
            if(row + count >= board.size() || col - count < 0){
                break;
            }
            else{
                if(board[row+count][col-count] == 'Q'){
                    attack = true;
                    break;
                }
            }
            count++;
        }
        // go up right
        count = 1;
        while(true && !attack){
            if(row - count < 0 || col + count >= board.size()){
                break;
            }
            else{
                if(board[row-count][col+count] == 'Q'){
                    attack = true;
                    break;
                }
            }
            count++;
        }
        return attack;
    }

    bool checkAttack(vector<string> board, int row, int col){

        if(diagonal(board, row, col)){
            return true;
        }
        if(reverseDiagonal(board, row, col)){
            return true;
        }
        if(column(board, row, col)){
            return true;
        }
        return false;
    }

    //      0    1   2   3

    // 0    Q    .   .   .
    // 1    .    Q   .   .
    // 2    Q    .   .   .
    // 3    .    .   .   Q

    void generateSolutions(vector<string> board, int row, int n){
        if(row == 1){
            answer.push_back(board);
            return;
        }
        for(int x = 0; x < n; x++){
            board[row][x] = 'Q';
            if(checkAttack(board, row, x)){
                // do nothing
            }
            else{
                generateSolutions(board, row+1, n);
            }
            board[row][x] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        generateSolutions(board, 0, n);
        return answer;
    }

    int main(){
        solveNQueens(4);
        for(auto sol: answer){
            for(auto str: sol){
                cout << str << endl;
            }
            cout << "====" << endl;
        }
        return 0;
    }
