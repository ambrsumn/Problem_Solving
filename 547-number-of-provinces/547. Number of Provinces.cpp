class Solution {
public:

    vector<int> parent;
    vector<int> rankDSU;

    int findUltimateParent(int u)
    {
        if(parent[u] == u)return u;

        return parent[u] = findUltimateParent(parent[u]);
    }

    void createDsu(int u, int v)
    {
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if(parentU == parentV)return;


        if(rankDSU[parentU] > rankDSU[parentV])
        {
            parent[parentV] = parentU;
        }
        else if(rankDSU[parentU] < rankDSU[parentV])
        {
            parent[parentU] = parentV;
        }
        else
        {
            parent[parentV] = parentU;
            rankDSU[parentU]++;
        }
    }

    int findCircleNum(vector<vector<int>>& g) {

        int n = g.size();

        for(int i=0; i<n; i++)
        {
            parent.push_back(i);
            rankDSU.push_back(1);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)if(g[i][j] == 1)createDsu(i, j);
        }

        set<int> st;

        for(int i=0; i<n; i++)if(parent[i] != i)int d = findUltimateParent(i);

        for(auto it : parent)st.insert(it);

        return st.size();
    }
};