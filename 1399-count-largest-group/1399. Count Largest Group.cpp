class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> mpp;
        int maxi = -1;
        int ans = 0;

        for(int i=1; i<=n; i++)
        {
            string a = to_string(i);
            int sum = 0;

            for(auto it : a)
            {
                sum += it-'0';
            }

            mpp[sum]++;

            if(mpp[sum] > maxi)
            {
                ans = 1;
                maxi = mpp[sum];
            }
            else if(mpp[sum] == maxi)ans++;
        }

        return ans;
        
    }
};