#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    unsigned long long i = 0, j = times[times.size()-1]*n;
    unsigned long long answer = j;
    while (i<=j) {
        unsigned long long mid = (i+j)/2;
        unsigned long long sum = 0;
        for (int time: times) {
            sum += mid/time;
        }
        if (sum>=n) {
            j = mid-1;
            answer = min(answer, mid);
        }
        else {
            i = mid+1;
        }
    }
    return answer;
}

int main() {
    int n = 6;
    vector<int> times;
    times.push_back(7);
    times.push_back(10);
    cout << solution(n, times) << endl;
    return 0;
}