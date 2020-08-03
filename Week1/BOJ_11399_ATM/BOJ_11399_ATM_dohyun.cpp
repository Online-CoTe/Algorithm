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
    sort(arr, arr+N);
    int result = 0;
    for (int i=0; i<N; i++) {
        result += (N-i)*arr[i];
    }
    cout << result <<endl;

    return 0;    
}