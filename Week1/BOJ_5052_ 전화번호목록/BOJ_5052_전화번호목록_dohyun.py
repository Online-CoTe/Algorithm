import sys

t = int(sys.stdin.readline())

def is_consi(num_list):
    """
    Check whether the given 'num_list' is consistent.
    """
    
    num_list = sorted(num_list)
    for i, num in enumerate(num_list[:-1]):
        length = len(num)
        if num==num_list[i+1][:length]:
            return False
    return True
    # num_list를 사전식으로 배열
    # 그 후 각 원소가 바로 다음 원소의 앞부분과 같은지 확인
            

for i in range(t):
    n = int(sys.stdin.readline())
    num_list = [sys.stdin.readline().strip() for j in range(n)]
    result = 'YES' if is_consi(num_list) else 'NO'
    print(result)
