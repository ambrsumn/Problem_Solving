class Solution {
public:

// bool recur(int i, int j, string s, string t) {

//     if(i >= s.length() && j <= t.size())return true;
//     if(j >= t.length())return false;

//     if(s[i] == t[j])return recur(i+1, j+1, s, t);
//     else return recur(i, j+1, s, t);
// }

    bool isSubsequence(string s, string t) {

        // return recur(0, 0, s, t);

        queue<char> sub;
        queue<char> str;

        for(auto it : s)sub.push(it);

        for(auto it : t)str.push(it);

        while(!str.empty() && !sub.empty())
        {
            while(!str.empty() && str.front() != sub.front())
            {
                str.pop();
            }

            if(str.empty() && !sub.empty())return false;

            if(sub.empty())return true;

            str.pop();
            sub.pop();

        }
            if(sub.empty())return true;

            return false;
    }
};