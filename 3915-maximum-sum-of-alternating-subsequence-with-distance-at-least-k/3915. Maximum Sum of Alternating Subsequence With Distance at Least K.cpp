class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> up(n), down(n);
        
       
        int sz = 1;
        while (sz < n) sz <<= 1;
        vector<long long> segUp(2*sz, LLONG_MIN/2), segDown(2*sz, LLONG_MIN/2);
        
        auto update = [&](vector<long long>& seg, int pos, long long val) {
            pos += sz;
            seg[pos] = max(seg[pos], val);
            for (pos >>= 1; pos >= 1; pos >>= 1)
                seg[pos] = max(seg[2*pos], seg[2*pos+1]);
        };
        
        auto query = [&](vector<long long>& seg, int l, int r) -> long long {
            long long res = LLONG_MIN/2;
            for (l += sz, r += sz + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = max(res, seg[l++]);
                if (r & 1) res = max(res, seg[--r]);
            }
            return res;
        };
        
        
        
        int maxVal = *max_element(nums.begin(), nums.end()) + 2;
        vector<long long> bitUp(maxVal+1, LLONG_MIN/2), bitDown(maxVal+1, LLONG_MIN/2);
        
      
        auto bitUpdate = [&](vector<long long>& bit, int pos, long long val) {
            for (; pos < (int)bit.size(); pos += pos & (-pos))
                bit[pos] = max(bit[pos], val);
        };
        
        auto bitQuery = [&](vector<long long>& bit, int pos) -> long long {
            long long res = LLONG_MIN/2;
            for (; pos > 0; pos -= pos & (-pos))
                res = max(res, bit[pos]);
            return res;
        };
        
        
        vector<long long> bitUpSuf(maxVal+2, LLONG_MIN/2), bitDownSuf(maxVal+2, LLONG_MIN/2);
        
        auto bitUpdateSuf = [&](vector<long long>& bit, int pos, long long val, int MX) {
            pos = MX - pos + 1;
            for (; pos < (int)bit.size(); pos += pos & (-pos))
                bit[pos] = max(bit[pos], val);
        };
        
        auto bitQuerySuf = [&](vector<long long>& bit, int pos, int MX) -> long long {
            pos = MX - pos + 1;
            long long res = LLONG_MIN/2;
            for (; pos > 0; pos -= pos & (-pos))
                res = max(res, bit[pos]);
            return res;
        };
        
        
        
        for (int i = 0; i < n; i++) {
            int j = i - k;
            if (j >= 0) {
                
                int v = nums[j];
               
                if (down[j] > LLONG_MIN/2 || j == 0) {
                    long long dj = (j == 0 && down[j] == 0) ? nums[j] : down[j];
                   
                    bitUpdate(bitDown, v, down[j]);
                    bitUpdateSuf(bitDownSuf, v, down[j], maxVal);
                }
                bitUpdate(bitUp, v, up[j]);
                bitUpdateSuf(bitUpSuf, v, up[j], maxVal);
            }
            
            long long bestFromDown = bitQuery(bitDown, nums[i] - 1); 
            long long bestFromUp = bitQuerySuf(bitUpSuf, nums[i] + 1, maxVal); 
            
            up[i] = nums[i];
            if (bestFromDown > LLONG_MIN/2) up[i] = max(up[i], bestFromDown + nums[i]);
            
            down[i] = nums[i];
            if (bestFromUp > LLONG_MIN/2) down[i] = max(down[i], bestFromUp + nums[i]);
        }
        
        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, max(up[i], down[i]));
        return ans;
    }
};