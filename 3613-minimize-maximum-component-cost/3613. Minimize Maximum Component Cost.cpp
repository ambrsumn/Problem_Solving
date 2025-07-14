class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int findUltimateParent(int i) {
        if (parent[i] == i) return i;
        return parent[i] = findUltimateParent(parent[i]);  
    }

    void createDSU(int i, int j) {
        int parentI = findUltimateParent(i);
        int parentJ = findUltimateParent(j);

        if (parentI == parentJ) return;

        if (rank[parentJ] > rank[parentI]) 
        {
            parent[parentI] = parentJ;
        } 
        else if (rank[parentJ] < rank[parentI]) 
        {
            parent[parentJ] = parentI;
        } 
        else 
        {
            parent[parentI] = parentJ;
            rank[parentJ]++;
        }
    }

    int countComponents() {
        unordered_set<int> counter;
        for (int i = 0; i < parent.size(); ++i) {
            counter.insert(findUltimateParent(i));
        }
        return counter.size();
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {

        int low = 0, high = -1;
        int ans = 0;

        for(auto it : edges)high = max(high, it[2]);

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            parent.resize(n);
            rank.resize(n);
            for (int i = 0; i < n; ++i) 
            {
                parent[i] = i;
                rank[i] = 0;
            }

            for(auto it : edges)if(it[2] <= mid)createDSU(it[0], it[1]);

            int cc = countComponents();

            if(cc <= k)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
        
    }
};