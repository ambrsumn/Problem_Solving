class Solution {
public:

bool recur(int i, int j, string s, string t) {

    if(i >= s.length() && j <= t.size())return true;
    if(j >= t.length())return false;
    // if(i<s.length()-1 && j>=t.length())return false;

    if(s[i] == t[j])return recur(i+1, j+1, s, t);
    else return recur(i, j+1, s, t);
}

    bool isSubsequence(string s, string t) {

        return recur(0, 0, s, t);
    }
};