import sys

R, C, T = map(int, sys.stdin.readline().split())
CLEANER = []
board = []
for i in range(R):
    row = list(map(int, sys.stdin.readline().split()))
    board.append(row)
    for j, entry in enumerate(row):
        if entry==-1:
            CLEANER.append((i, j))

def diff(board):
    for i in range(R):
        for j in range(C):
            if board[i][j]%1001 and board[i][j]!=-1:
                diff_dust = (board[i][j]%1001)//5
                if i>0 and board[i-1][j]!=-1:
                    board[i-1][j] += diff_dust*1001
                    board[i][j] -= diff_dust
                if j>0 and board[i][j-1]!=-1:
                    board[i][j-1] += diff_dust*1001
                    board[i][j] -= diff_dust
                if i+1<R and board[i+1][j]!=-1:
                    board[i+1][j] += diff_dust*1001
                    board[i][j] -= diff_dust
                if j+1<C and board[i][j+1]!=-1:
                    board[i][j+1] += diff_dust*1001
                    board[i][j] -= diff_dust
    for i in range(R):
        for j in range(C):
            if board[i][j]!=-1:
                board[i][j] = board[i][j]//1001+board[i][j]%1001
                    

def clean(board):
    up_cleaner, down_cleaner = CLEANER[0][0], CLEANER[1][0]
    for i in range(up_cleaner-1, -1, -1):
        board[i][0] = board[i-1][0]
    for j in range(C-1):
        board[0][j] = board[0][j+1]
    for i in range(up_cleaner):
        board[i][-1] = board[i+1][-1]
    for j in range(C-1, 1, -1):
        board[up_cleaner][j] = board[up_cleaner][j-1]
    board[up_cleaner][1] = 0
    for i in range(down_cleaner+1, R-1):
        board[i][0] = board[i+1][0]
    for j in range(C-1):
        board[-1][j] = board[-1][j+1]
    for i in range(R-1, down_cleaner, -1):
        board[i][-1] = board[i-1][-1]
    for j in range(C-1, 1, -1):
        board[down_cleaner][j] = board[down_cleaner][j-1]
    board[down_cleaner][1] = 0
    
        
for _ in range(T):
    diff(board)
    clean(board)
result = sum([sum(row) for row in board])+2
print(result)
