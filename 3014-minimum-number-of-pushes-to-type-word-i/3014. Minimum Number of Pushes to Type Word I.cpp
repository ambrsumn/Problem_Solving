class Solution {
public:
    int minimumPushes(string word) {

        int ans = 0;

        map<char, int> mpp;

        for(auto it : word)mpp[it]++;
        priority_queue<int> pq;
        for(auto it : mpp)pq.push(it.second);


        int count = 0;
        while(!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            if(count < 8)ans += 1*top;
            else ans += (count/8 + 1)*top;

            count++;
        }

        return ans;
    }
};