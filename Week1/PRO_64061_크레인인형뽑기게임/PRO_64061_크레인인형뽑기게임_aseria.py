def solution(board, moves):
    answer = 0
    # array 초기화
    s = []
    for _ in range(len(board[0])):
        s.append([])

    #밑에서 부터 쌓여진 인형 정보
    for row in reversed(board):
        for i, e in enumerate(row):
            if e != 0:
                s[i].append(e)

    basket = []
    for m in moves:
        m -= 1
        if s[m]:
            if basket and basket[-1] == s[m][-1]:
                answer += 2
                basket.pop()
            else:
                basket.append(s[m][-1])
            s[m].pop()
    return answer


board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves = [1,5,3,5,1,2,1,4]

solution(board, moves)