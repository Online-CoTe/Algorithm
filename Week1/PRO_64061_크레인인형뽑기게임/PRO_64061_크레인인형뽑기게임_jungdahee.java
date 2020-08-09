import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int cnt = 0;
		
		Stack<Integer> st = new Stack<Integer>();
		
		for(int i = 0; i < moves.length; i++) {
			int n = moves[i] - 1;
			
			for(int j = 0; j < board.length; j++) {
				if(board[j][n] != 0) {
					if(!st.isEmpty() && st.peek() == board[j][n]) {
						st.pop();
						cnt += 2;
					}
					else st.push(board[j][n]);
					
					board[j][n] = 0;
					break;
				} 
			}
		}
		
	    return cnt;
    }
}
