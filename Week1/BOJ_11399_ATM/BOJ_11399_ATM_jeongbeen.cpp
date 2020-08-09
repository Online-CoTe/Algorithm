#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n,sum;
	scanf("%d", &n);

	int *arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr,arr+n);
	sum = arr[0];

	for (int i = 0; i < n - 1; i++) {
		arr[i + 1] = arr[i] + arr[i+1];
		sum += arr[i + 1];
	}
	printf("%d", sum);
}
