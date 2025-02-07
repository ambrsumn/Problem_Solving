class Solution {
public:
    string oddString(vector<string>& words) {

        vector<vector<int>> diff;

        for(auto it : words)
        {
            vector<int> temp;
            for(int i=1; i<it.length(); i++)
            {
                temp.push_back(it[i]-it[i-1]);
            }

            diff.push_back(temp);
        }


        for(auto it : diff)
        {
            for(auto itt : it)
            {
                cout<<itt<<" ";
            }
            cout<<endl;
        }
        int ans = -1;

        for(int i=0; i<diff.size()-1; i++)
        {

            if(i == 0)
            {
                if(diff[i] != diff[i+1])
                {
                ans = i;
                // break;
                }
            }
            else
            {
                if(diff[i] != diff[i+1] && diff[i] != diff[i-1])
                {
                    ans = i;
                    // break;
                }
            }
        }

        if(ans == -1)ans = diff.size()-1;

        cout<<ans<<endl;

        // cout<<endl;

        return words[ans];
        
    }
};