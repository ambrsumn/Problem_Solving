class Solution {
public:

    vector<vector<int>> chosenIndexes;

    bool isPalindrome(string &s)
    {
        int i=0, j=s.length()-1;

        while(i<=j)
        {
            if(s[i] != s[j])return false;
            i++;
            j--;
        }

        return true;
    }

    int recur(int i, string temp1, string temp2, string &s)
    {
        if(i >= s.length())
        {
            if(isPalindrome(temp1) && isPalindrome(temp2))
            {
                return temp1.length()*temp2.length();
            }
            return 0;
        }

        temp1 += s[i];
        int ans1 = recur(i+1, temp1, temp2, s);
        temp1.pop_back();

        temp2 += s[i];
        int ans2 = recur(i+1, temp1, temp2, s);
        temp2.pop_back();

        int ans3 = recur(i+1, temp1, temp2, s);

        return max({ans1, ans2, ans3});
    }

    int maxProduct(string s) {

        string temp1 = "", temp2 = "";

        return recur(0, "", "", s);
    }
};