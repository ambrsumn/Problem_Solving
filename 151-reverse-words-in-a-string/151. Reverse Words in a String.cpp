class Solution {
public:
    string reverseWords(string s) {

        string rev = "";
        string temp = "";
        int i = 0;

        while (i <= s.length() - 1 && s[i] == ' ')
            i++;

        reverse(s.begin(), s.end());

        int j = 0;

        while (j <= s.length() - 1 && s[j] == ' ')
            j++;

        reverse(s.begin(), s.end());

        // cout<<i<<" "<<j<<" "<<s;

        for (int k = i; k <= s.length() - 1 - j; k++) {
            temp += s[k];
        }

        vector<string> vec;

        string word = "";
        // for(auto it : temp)
        // {
        //     if(it == ' ')
        //     {
        //         vec.push_back(word);
        //         word = "";
        //     }
        //     else
        //     {
        //         word += it;
        //     }
        // }

        for (int i = 0; i < temp.length(); i++) {

            while (i < temp.length() && temp[i] != ' ') {
                word += temp[i];
                i++;
            }

            if (temp[i] == ' ') {
                vec.push_back(word);
                word = "";

                while (i < temp.length() && temp[i] == ' ') {
                    i++;
                }
                i--;
            }
        }
        vec.push_back(word);

        for (int i = vec.size() - 1; i >= 0; i--) {
            rev += vec[i];

            if (i != 0)
                rev += ' ';
        }
        return rev;
    }
};