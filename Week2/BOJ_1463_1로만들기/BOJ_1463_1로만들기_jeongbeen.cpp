#include <iostream>
#include <algorithm>
using namespace std;
int a;
int dp[1000000];

int main() {
	scanf("%d", &a);
	dp[1] = 0;
	for (int i = 2; i <= a; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3]+1);
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2]+1);
	}
	printf("%d", dp[a]);
}
