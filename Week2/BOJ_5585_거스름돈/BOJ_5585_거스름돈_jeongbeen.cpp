#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;

int a;
int main() {
	scanf("%d", &a);
	int n = 1000 - a;

	int ans = 0, i = 0;
	int arr[] = { 500,100,50,10,5,1 };
	while (n != 0) {
		ans += (n / arr[i]);
		n %= arr[i];
		i++;
	}
	printf("%d", ans);
}
