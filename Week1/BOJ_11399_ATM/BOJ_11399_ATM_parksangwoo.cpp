#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> P;

int main(){
	
	cin >> N;
	for(int i = 0; i<N; i++){
		int x;
		cin >> x;
		P.push_back(x);
 	}
	
	sort(P.begin(),P.end());
	int sum=0;
	int time=0;
	
	for(int i = 0; i<N; i++){
		time += P[i];
		sum += time;
	}
	
	printf("%d", sum);
	return 0;
}
