#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 100003
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

string str;
int n, a = 2;
long long p[200005]; //a(2)의 power를 담는 배열

/*
	이분탐색 + 라빈카프
*/

int main() {
	scanf("%d", &n);
	cin >> str;

	p[0] = 1;
	for (int i = 1; i < 200001; i++) //우선 power를 다 구해줌
		p[i] = (p[i - 1] * 2) % mod;

	int st = 0, en = n ; //이분 탐색을 위해 시작점과 끝점을 정함
	while (st + 1 < en) {
		int mid = (st + en) / 2; //패턴 문자열의 길이를 정해줌(<- 이 값이 최대가 될 때까지 while문을 반복한다)

		long long H = 0; //해시 값
		vector<int>hash_[mod];

		for (int i = 0; i < mid; i++) 
		{
			H = (H + str[i] * p[mid - i - 1]) % mod;
		}
		hash_[H].push_back(0); //str의 0번 째부터 시작한 부분 문자열의 해시값을 구해준다.

		bool go = 0;
		for (int i = 1; i <= n - mid; i++) // str를 돌면서 해시값을 다 구함
		{
			bool same = 0;
			H = (H - p[mid - 1] * str[i - 1]) % mod;
			if (H < 0) H += mod;
			H = (H*a) % mod;
			H = (H + str[i - 1 + mid]) % mod; //식은 라빈카프 참고
			if (!hash_[H].empty()) { //만약 해시에 있다면, 같은 문자열이거나 우연히 해시값이 같은 경우
				for (int k = 0; k < hash_[H].size(); k++)
				{
					bool same = 1;
					int x = hash_[H][k];
					for (int j = 0; j < mid; j++) //문자열을 확인해서 같은 문자열인지 확인한다
					{
						if (str[x + j] != str[i + j]) {
							same = 0; break;
						}
					}
					if (same) { //두 번 이상 등장한 부분 문자열 중 가장 길이가 긴 것을 찾는 것이 목표이므로
						go = 1; // 같은 문자열을 찾았으면 바로 break하면 됨
						break;
					}
				}
			}
			if (same) break; //같은 문자열을 찾았으면 break
			else hash_[H].push_back(i); //그게 아니면 해시에 넣고 다시 같은 걸 찾을 때까지 탐색
		}
		if (go) st = mid; //만약 같은 걸 찾았다면, 패턴 문자열 길이를 더 늘려본다.
		else en = mid; //같은 게 없다면, 패턴 문자열 길이를 줄여본다.
	}
	printf("%d", st);
}
