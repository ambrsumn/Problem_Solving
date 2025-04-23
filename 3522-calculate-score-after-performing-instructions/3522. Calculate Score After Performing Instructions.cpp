class Solution {
public:
    long long calculateScore(vector<string>& in, vector<int>& v) {
        long long n = in.size();
        vector<long long> visited(n+1, 0);
        long long score = 0;
        // cout<<n<<endl;

        for(long long i=0; i<n; i++)
        {
            if(i<0 || i>=n || visited[i] == 1)return score;
            
            visited[i] = 1;
            if(in[i] == "jump")
            {
                i += v[i]-1;
            }
            else
            {
                score += v[i];
            }
        } 

        return score;
    }
};