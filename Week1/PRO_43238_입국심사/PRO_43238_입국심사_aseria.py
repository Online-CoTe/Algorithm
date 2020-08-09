def solution(n, times):
    answer = 0

    l, r = 1, max(times) * n
    while l <= r:
        m = (l + r) // 2
        proceed = 0
        for i in times:
            proceed += m // i
            if proceed >= n:
                # 심사 가능한 경우
                break
        if proceed >= n:
            # 심사 가능한 경우, 시간을 줄여서 재 시도
            answer = min(answer, m) if answer > 0 else m
            r = m - 1
        else :
            # 심사 불가능한 경우, 시간을 늘여서
            l = m + 1
    return answer