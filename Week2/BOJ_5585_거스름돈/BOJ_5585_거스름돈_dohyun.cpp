#include <iostream>
using namespace std;

int main() {
    int money;
    cin >> money;
    money = 1000-money;
    int result = 0;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    for (int i=0; i<6; i++) {
        result += money/coin[i];
        money -= money/coin[i]*coin[i];
    }
    cout << result << endl;
    return 0;
}
