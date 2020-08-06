#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define mod 100003
typedef pair<int, int>pi;
typedef pair<int, pair<int, int>>pii;
typedef long long ll;

/*
풀이방법
1. 해쉬를 이용한 구현
2. 트라이
3. string을 이용해서 정렬

이 중 해시를 이용해서 해결함
모든 전화번호를 해시에 넣고
겹치는 접두사가 있는지 확인
*/

int n, t;

const int PN = 23;
const int HASH_SIZE = 5000; //input의 3/1

int table[HASH_SIZE][50]; // 10000 * 5 < HASH_SIZE * 50
int pointer = 0;
char number[10005][15];
bool endd;

/*
table : 해시테이블, 안에는 인덱스가 들어가 있어서 number랑 매칭됨
table[key][0] : 현재 키 값에 들어와있는 원소의 개수
number : 문자열을 담는 테이블
pointer : vector를 안써서, 값이 어디까지 들어와있는지 나타내는 애
*/


//해시 키 구해주는 함수
unsigned int get_key(char str[]) {
	unsigned int key = 0, p = 1;

	for (int i = 0; str[i] != 0; ++i) {
		key += (str[i] * p);
		p *= PN;
	}
	return (key % HASH_SIZE);
}

//해시에 값을 넣어줌
void add(char str[]) {
	int len = 0;
	for (len = 0; str[len] != 0; ++len) {
		number[pointer][len] = str[len];
	}
	number[pointer][len] = 0;

	unsigned int key = get_key(str);
	int& size = table[key][0];
	table[key][++size] = pointer;

	++pointer;
}

//st : number에서의 인덱스. 자기자신이라 포함되는 경우를 막기 위함
void search(char str[], int st) {
	unsigned int key = 0, p = 1;

	//ex 123이 있다면, 1의 key값, 12의 key값, 123의 key값을 구해
	//해시 테이블에서 찾아본다.

	for (int i = 0; str[i] != 0; i++) {
		key += (str[i] * p);
		p *= PN;

		int size = table[key % HASH_SIZE][0]; 

		if (size > 0) {
			for (int j = 1; j <= size; j++) //해시 테이블을 돌면서 접두사 겹치는 애가 있는지 찾아본다
			{
				int idx = table[key % HASH_SIZE][j]; //현재 인덱스가 st랑 같다는건, 자기 자신이란 소리
				if (idx == st) continue;

				bool flag = 1;
				for (int k = 0; number[idx][k] != 0; k++) 
					/*
						여기서 k를 k<=i이렇게 했는데, 이러면
						1234
						124 같은 경우에서 꼬이게 된다.

						왜냐하면 
						str가 1이고, number가 1234일때,
						k<=i이면, 1 == 1이렇게 되어버리기 때문이다.
						이렇게 되면
						같다고 판정해서 endd로 탈출해서 NO가 떠버린다. 
					
					*/

				{
					if (str[k] == 0 || str[k] != number[idx][k]) { //문자열이 다를경우 123이랑 456524 이렇다는 소리니까 그냥 넘어감
						flag = 0;
						break;
					}
				}
				if (flag) { //123 1234이런게 발견됐다는 것이므로, no를 출력해주러가자
					endd = 1;
					return;
				}
			}
		}
	}
}
void init() {
	for (int i = 0; i < HASH_SIZE; i++) 
		for (int j = 0; j < 50; j++)
			table[i][j] = 0;

	for (int i = 0; i < 10005; i++)
		for (int j = 0; j < 15; j++)
			number[i][j] = 0;

	pointer = 0;
	endd = 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {

		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char a[15];
			scanf("%s", a);
			add(a);
		}

		/*
		2
		12345
		123

		이런 경우를 위해서 일단 해시에 문자열을 다 넣어주고
		search로 탐색한다
		*/
		for (int i = 0; i < n; i++)
		{
			search(number[i], i);
			if (endd) break;
		}
		if (endd) printf("NO\n");
		else printf("YES\n");
	}
}
