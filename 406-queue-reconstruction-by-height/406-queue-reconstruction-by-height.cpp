class Solution {
    
        
    static bool sortcol(vector<int>& v1, vector<int>& v2)
      {
        if(v1[0] == v2[0])
            return v1[1]<v2[1];
        
        return v1[0] < v2[0];
      }  
    
public:    
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        
        int n = people.size();
        sort(people.begin(), people.end(), sortcol);
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<2; j++)
        //         cout<<people[i][j]<<" ";
        //     cout<<endl;
        // }
        cout<<endl;
        vector<vector<int>> ans(n,vector<int>(2,-1));
        
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<2; j++)
        //         cout<<ans[i][j]<<" ";
        //     cout<<endl;
        // }
        
        for(int i=0; i<n; i++)
        {
            // cout<<endl;
            int count = people[i][1];
            // cout<<people[i][0]<<" "<<count;
            for(int j=0; j<n; j++)
            {
                if(ans[j][0]==-1 && count==0)
                {
                    // cout<<" "<<j<<endl;
                    ans[j][0] = people[i][0];
                    ans[j][1] = people[i][1];
                    
                    // cout<<ans[j][0];
                    break;
                }
                
                else if(ans[j][0] == -1 || ans[j][0]>=people[i][0])
                    count-=1;
                
            }
            
        }
        
        return ans;
    }
};