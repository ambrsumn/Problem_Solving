class Solution {
public:

// s = v*t
// t = s/v

// s = 6
// v = 2

// t = s/v = 6/2 = 3

    bool canEat(vector<int>& piles, int h, int mid)
    {
        // nikalna hai total time to eat all kelas with this speed(mid)

        long long time = 0;
        for(auto it : piles)
        {
            time += ceil((it*1.0)/mid);
        }

        if(time <= h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        sort(piles.begin(), piles.end());

        int low = 1;
        int high = piles.back();
        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(canEat(piles, h, mid))
            {
                ans = min(ans, mid);
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};