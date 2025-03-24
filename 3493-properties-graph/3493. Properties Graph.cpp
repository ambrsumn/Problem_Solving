class Solution {
public:

    vector<vector<int>> createAdjecencyList(vector<vector<int>>& p, int k)
    {
        int n = p.size();
        vector<vector<int>> adjList(n, vector<int>(n, 0));
        unordered_set<int> st1;
        unordered_set<int> st2;
        unordered_set<int> temp;


        for(int i=0; i<n; i++)
        {
            st1.clear();
            for(auto it : p[i])st1.insert(it);
            temp = st1;

            if(st1.size() < k)continue;

            for(int j=i+1; j<n; j++)
            {
                st1 = temp;
                st2.clear();
                int curr = 0;
                int n = st1.size();

                for(auto it : p[j]) st2.insert(it);
                
                for(auto it : st2)
                {
                    st1.insert(it);
                    if(st1.size() == n)curr++;
                    else n = st1.size();
                }

                if(curr >= k)
                {
                    adjList[i][j] = 1;
                    adjList[j][i] = 1;
                }
            }
        }

        return adjList;
    }

    void recur(int i, int n, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        if(i >= n)return;

        for(int j=0; j<n; j++)
        {
            if(!visited[j] && j != i && adjList[i][j] == 1)
            {
                visited[j] = true;
                recur(j, n, adjList, visited);
            }
        }

        return;
    }

    int numberOfComponents(vector<vector<int>>& p, int k) {

        int n = p.size(), ans=0;
        vector<vector<int>> adjList = createAdjecencyList(p, k);
        vector<bool> visited(n, false);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                ans++;
                recur(i, n, adjList, visited);
            }
        }

        // for(auto it : adjList)
        // {
        //     cout<<ans<<" : ";
        //     for(auto itt : it)cout<<itt<<" ";
        //     cout<<endl;

        //     ans++;
        // }

        return ans;
        
    }
};