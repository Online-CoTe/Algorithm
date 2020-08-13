#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000

int store[MAX];

int make1(int num) {
    if (store[num] || num==1)    return store[num]; // make1(num)이 이미 존재하거나 num이 1인 경우 바로 return
    int a, b, c;
    a = num%3? MAX : make1(num/3); // n이 3으로 나누어 떨어지면, 3으로 나눈다.
    b = num%2? MAX : make1(num/2); // n이 2로 나누어 떨어지면, 2로 나눈다.
    c = make1(num-1); // 1을 뺀다.
    int result = min(min(a, b), c)+1; // 그 중 최소값을 택한 후 +1
    store[num] = result; // store에 result 저장
    return result;
}

int main() {
    int X;
    cin >> X;
    cout << make1(X);
    return 0;
}
