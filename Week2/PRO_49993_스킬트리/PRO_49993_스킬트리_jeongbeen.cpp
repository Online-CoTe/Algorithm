#include <string>
#include <vector>
using namespace std;

/*
구현 - 스킬트리 배열을 돌면서, 문자열을 skill과 비교해준다

bool chk[] : 문자열 skill에 들어간 스킬들을 표시
bool did[] : skill에 있는 스킬중 사용된 스킬
만약 이전에 배운 스킬이 이번에 또 사용된다면 그냥 넘어가야된다.
그러나 이전에 배운 스킬이 아니면서, 현재 배울 스킬이 아닐 때 문제가 된다.

*/

bool chk[30];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=0; i<skill.length(); i++){
        chk[skill[i]-65] = 1;
    }
    
    for(int i=0; i<skill_trees.size();i++){
        string x = skill_trees[i];
        bool did[30] = {0,};
        bool flag = 1;
        for(int j=0, k=0; j<x.length(); j++){
            if(chk[x[j]-65]) {
                if(skill[k]==x[j]){
                    k++;
                    did[x[j]-65]=1;
                    if(k>skill.size())  break;                    
                }
                else{
                    if(!did[x[j]-65]){
                         flag = 0;
                         break;                        
                    }
                }
            }
        }
    if(flag)  answer++;
    }
    return answer;
}
