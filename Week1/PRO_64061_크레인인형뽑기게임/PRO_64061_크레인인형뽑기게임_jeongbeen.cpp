#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int>s;
int top[35];

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int m = board.size();
    for(int i = 0; i < m; i++){
        top[i] = m-1;
    }
    
    for(int i =0; i<m; i++){
         for(int j =0; j<m; j++){
             if(board[i][j] > 0) {
                 top[j] = min(i, top[j]);
             }
         }
    }
    
    for(int i = 0; i<moves.size(); i++){
        int x = moves[i]-1;
        if(top[x] >= m || board[top[x]][x] == 0) continue;
        
        if(!s.empty() && s.top() == board[top[x]][x]){
            answer+=2;
            s.pop();
        }
        else{
            s.push(board[top[x]][x]);
        }
        board[top[x]][x] = 0;
        top[x]++;
    }
    
    return answer;
}
