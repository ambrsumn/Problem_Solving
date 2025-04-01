class Solution {
public:

    int isPalindrome(int i, int j, string &s)
    {
        while(i<=j)
        {
            if(s[i] != s[j])
            {
                return 0;
            }

            i++;
            j--;
        }

        return 1;
    }

    int countSubstrings(string s) {

        // cout<<s.length()<<endl;

        int ans = 0;

        for(int i=0; i<s.length(); i++)
        {
            for(int j=s.length()-1; j>=i; j--)
            {
                ans += isPalindrome(i, j, s);
            }
        }

        return ans;
    }
};