class Solution {
public:
    int minSteps(string s, string t) 
    {
		vector<int> cnt(26);
		for(int i=0;i<s.size();i++){
			cnt[s[i]-'a']+=1; 
            cnt[t[i]-'a']-=1;
        }
		int ans=0;
		for(int i=0;i<26;i++) 
            if(cnt[i]>0) 
                ans+=cnt[i];
		return ans;
    }
};