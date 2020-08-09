count = input()
arr = list(map(int, input().split(' ')))

# 결국 최소 대기시간을 가져야 하므로, 걸리는 시간순으로 오름차순하여 계산
arr.sort()

pre_sum = 0
total = 0
for i in arr:
    pre_sum += i
    total += pre_sum

print(total)