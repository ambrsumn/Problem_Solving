class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1 == s2)return true;

        int found = 0;
        int n = s1.length();
        int m = s2.length();
        int i=0, j=0;

        if(m < n)return false;

        map<char, int> mpp, temp;
        for(auto it : s1)mpp[it]++;

        while(n--)
        {
            temp[s2[j]]++;
            j++;
        }

        if(temp == mpp)return true;

        while(j<m)
        {
            temp[s2[i]]--;
            if(temp[s2[i]] <= 0)temp.erase(s2[i]);

            temp[s2[j]]++;

            if(temp == mpp)return true;
            i++;
            j++;
        }

        return false;
    }
};