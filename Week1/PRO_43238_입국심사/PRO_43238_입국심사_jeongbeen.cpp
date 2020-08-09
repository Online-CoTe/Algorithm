#include <string>
#include <vector>
#include <algorithm>
typedef unsigned long long ll;
using namespace std;

/*
이분탐색
최악의 경우 : 사람(n)이 1,000,000,000명이고, 걸리는 시간이 1,000,000,000이라 long long 범위(약 10^18)를 넘어선다.
따라서 unsigned long long을 써줘야한다.
*/

long long solution(int n, vector<int> times) {
    ll answer = 0;
    
    sort(times.begin(),times.end());
    int m = times.size();
    
    ll st = 0, en = times[m-1] * n;
    
    while(st+1<en){
        ll mid = (st+en)/2;
        ll sum = 0;
        for(int i = 0; i<m; i++){
            sum += mid/times[i];
        }
        if(sum >= n) en = mid;
        else st = mid;
    }
   answer = en;
    
    return answer;
}
