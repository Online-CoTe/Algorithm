class Solution {
public:
    bool validPalindrome(string s) {
        return helper(s, 0, s.size()-1, true);
    }
private:
    bool helper(string s, int i, int j, bool cond) {
        // i부터 j까지 valid palindrome인지 확인
        // cond는 이미 문자를 하나 제거했으면 false, 그렇지 않으면 true
        while (i<j) {
            if (s[i]!=s[j]) { // 만약 i번째 문자와 j번째 문자가 다르다면,
                if (!cond) return false; // 이미 문자를 하나 제거했다면, false 반환
                return helper(s, i+1, j, false)||helper(s, i, j-1, false); // 문자를 하나 제거하고 다시 확인
            }
            i++;
            j--;
            // i는 한 칸 뒤로, j는 한 칸 앞으로 이동
        }
        return true;
    }
};