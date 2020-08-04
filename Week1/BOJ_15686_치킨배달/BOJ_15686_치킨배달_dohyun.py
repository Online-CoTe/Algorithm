import sys
import itertools

N, M = map(int, input().split())
BOARD = []
for i in range(N):
    BOARD.append(list(map(int, sys.stdin.readline().split())))
# 데이터 입력 및 저장
# 도시의 정보는 이중 list로 BOARD에 저장, 즉 BOARD[i][j]는 (i, j)의 정보를 의미

HOME, CHICKEN = set(), set()
for i, row in enumerate(BOARD):
    for j, ele in enumerate(row):
        if ele==1:
            HOME.add((i, j))
        elif ele==2:
            CHICKEN.add((i, j))
# 집의 위치를 (i, j) 형태로 모아서 HOME이라는 set에 저장
# 치킨집의 위치를 (i, j) 형태로 모아서 CHICKEN이라는 set에 저장

            
def get_dist(chicken):
    """
    Get the chicken distance of the city for the given set of chicken restaurants.
    """
    
    return sum([min({abs(i1-i2)+abs(j1-j2) for i1, j1 in chicken}) for i2, j2 in HOME])


result = -1
for remain in itertools.combinations(CHICKEN, M):
    dist = get_dist(remain)
    if dist<result or result<0:
        result = dist
# CHICKEN에서 M개를 선택한 후 get_dist 함수를 통해 그때의 도시의 치킨 거리를 구한다.
# 가능한 모든 경우의 수를 계산한 후 그 중 최솟값을 구한다.

print(result)
