#include <iostream>
using namespace std;

#define MOD 100003

int L;
string str;
int hash_table[MOD][10];
// hash를 저장하는 2차원 배열
// hash_table[hash]는 hash를 가지는 문자열의 시작 index를 모은 배열이다. 이때, 첫 원소는 index의 개수이다.

int mod(long long n) {
    // n이 주어졌을 때 MOD로 나눈 나머지를 구하는 함수
    if (n>=0) return n%MOD;
    return ((n%MOD)+MOD)%MOD;
}

bool check(int mid) {
    // 주어진 길이의 문자열이 두 번 이상 등장하는지 확인하는 함수
    for (int i=0; i<MOD; i++) { //hash_table 초기화
        hash_table[i][0] = 0;
    }
    int hash = 0, power = 1;
    for (int i=0; i<=L-mid; i++) {
        if (!i) { // 처음에는 직접 hash를 구한다.
            for (int j=mid-1; j>=0; j--) {
                hash = mod(hash+power*str[i+j]);
                if (j) power = mod(power*2);
            }
        }
        else { // 그 다음부터는 이전의 hash와의 관계식을 이용하여 구한다.
            hash = mod(2*(hash-str[i-1]*power)+str[i+mid-1]);
        }
        for (int j=1; j<=hash_table[hash][0]; j++) {// 만약 hash가 같다면, 문자열을 직접 비교해본다.
            int index = hash_table[hash][j];
            bool found = true;
            for (int k=0; k<mid; k++) {
                if (str[i+k]!=str[index+k]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        } 
        int &size = hash_table[hash][0];
        hash_table[hash][++size] = i; // size 변경 및 hash에 해당하는 index 저장
    }
    return false;
}

int main() {
    cin >> L;
    cin >> str;
    int i = 0, j = L;
    int ans = 0;
    while (i<=j) {
        // 길이가 n인 문자열이 두 번 이상 등장한다는 것은 길이가 1, 2, ..., n-1인 문자열도 모두 두 번 이상 등장함을 의미
        // 따라서 이분탐색을 통해 두 번 이상 등장하는 문자열의 최대 길이를 구할 수 있다.
        int mid = (i+j)/2;
        if (check(mid)) {
            ans = mid;
            i = mid+1;
        }
        else {
            j = mid-1;
        }

    }
    cout << ans << endl;
    return 0;
}