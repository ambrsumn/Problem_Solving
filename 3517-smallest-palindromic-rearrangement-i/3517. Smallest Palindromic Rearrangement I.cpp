class Solution {
public:
    string smallestPalindrome(string s) {

        map<char, int> mpp;
        for(auto it : s)mpp[it]++;

        vector<char> ans(s.length(), '0');
        int stIdx=0, endIdx=s.length()-1;

        for(auto it : mpp)
        {
            char c = it.first;
            int total = it.second;

            int singleSid = total/2;

            while(singleSid--)
            {
                ans[stIdx] = c;
                stIdx++;
            }

            singleSid = total/2;

            while(singleSid--)
            {
                ans[endIdx] = c;
                endIdx--;
            }

            if(total%2 != 0)ans[s.length()/2] = c;
        }

        string answer = "";
        for(auto it : ans)answer += it;

        return answer;
    }
};