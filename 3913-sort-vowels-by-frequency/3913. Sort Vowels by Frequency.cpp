class Solution {
public:
    bool vovel(char c)
    {
        return c=='a'|| c=='e'||c=='i'||c=='o'||c=='u';
    }
    string sortVowels(string s) 
    {
    int n=s.size();
        map<char,int>mpp;
        vector<char>vec;
        for(auto it:s)
            {
                if(vovel(it))
                {
                    mpp[it]++;
                }
            }
        for(auto it:s)
            {
                if(vovel(it))
                {
                    vec.push_back(it);
                }
            }
        map<char,int>position;
        for(int i=0;i<n;i++)
            {
                if(vovel(s[i]) && position.find(s[i])==position.end())
                    {
                    position[s[i]]=i;
                    }
                    
            }
        sort(vec.begin(),vec.end(),[&](char a,char b)
        {
            if(mpp[a]!=mpp[b])
                return mpp[a]>mpp[b];
            return position[a]<position[b];
            
        });

        int j=0;
        for(int i=0;i<n;i++)
            {
                if(vovel(s[i]))
                {
                    s[i]=vec[j++];
                }
            }
        return s;
    }
};