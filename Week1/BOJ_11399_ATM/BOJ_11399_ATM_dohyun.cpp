#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    // N과 P_i 입력
    // 편의상 P_1부터 받지 않고 P_0부터 받음. 즉, P_0부터 P_(N-1)까지
    
    sort(arr, arr+N);
    int result = 0;
    for (int i=0; i<N; i++) {
        result += (N-i)*arr[i];
    }
    // 구하고자 하는 값을 계산하면 sum (N-i)*P_i, i=0 to N-1 이므로
    // 재배열 부등식에 의해 P_i는 오름차순으로 정렬될 때 그 값이 최소가 된다.
    // 따라서 오름차순 정렬 후 값을 계산    
    
    cout << result <<endl;
    delete[] arr;

    return 0;    
}
