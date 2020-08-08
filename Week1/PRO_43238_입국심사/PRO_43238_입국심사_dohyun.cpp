#include <vector>
#include <algorithm>
using namespace std;

unsigned long long solution(int n, vector<int> times) {
    /*
    이진탐색 이용
    주어진 시간 내에 심사받을 수 있는 사람 수를 구한 후,
    그 값을 n과 비교하여 더 작으면 시간을 늘리고 더 크면 시간을 줄여가며
    적절한 시간을 찾는다.    
    */
    sort(times.begin(), times.end()); // times 오름차순 정렬
    unsigned long long i = 0, j = times[times.size()-1]*n; // i는 시간의 최솟값, j는 최댓값
    unsigned long long answer = j;
    while (i<=j) { // 이분탐색 실행
        unsigned long long mid = (i+j)/2; // 중간값
        unsigned long long sum = 0; // 심사받을 수 있는 사람 수(가 될 예정)
        for (int time: times) {
            sum += mid/time;
        }
        if (sum>=n) { // 심사받을 수 있는 사람 수가 n보다 크면,
            j = mid-1; // j=mid-1로 바꾼다.
            answer = min(answer, mid);
        }
        else { // 그렇지 않으면,
            i = mid+1; // i=mid+1로 바꾼다.
        }
    }
    return answer;
}
