#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board[0].size();
    vector<int> basket = {0};
    for (int move: moves) {
        int item = 0;
        for (int i=0; i<size; i++) {
            if (board[i][move-1]) {
                item = board[i][move-1];
                board[i][move-1] = 0;
                break;
                // 만약 move열에 인형이 있다면 그 인형을 item이라 하고
                // 해당 자리를 0(빈 칸)으로 바꾼다.
            }
        }
        if (item) { // 만약 인형을 뽑았으면, 
            int old = basket.back(); // 바구니 가장 위에 있는 인형을 old라 하고
            if (old==item) { // 그 둘이 같으면,
                answer++; // answer값을 1 올리고
                basket.pop_back(); // old를 지운다.
            }
            else basket.push_back(item); // 다르면, 새로운 인형을 넣는다.
        }
    }
    return 2*answer; // 한 번 터뜨릴 때, 2개 씩 터지므로 2를 곱해준다.
}