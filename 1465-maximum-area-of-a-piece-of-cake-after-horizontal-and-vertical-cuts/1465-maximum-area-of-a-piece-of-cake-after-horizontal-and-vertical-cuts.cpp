class Solution {
public:
    
    int max(int a, int b)
    {
        if(a>=b)
            return a;
        
        return b;
    }
    
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) 
    {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int m = 1000000007;
        long long max_h = -1, max_w = -1;
        
        for(int i=0; i<hc.size()-1; i++)
        {
            int curr = hc[i+1] - hc[i];
            max_h = max(curr, max_h);
        }
        
        max_h = max((hc[0]-0), max(max_h, (h-hc.back())))%m;
        
        
        for(int i=0; i<vc.size()-1; i++)
        {
            int curr = vc[i+1]-vc[i];
            max_w = max(curr, max_w);
        }
        
        max_w = max((vc[0]-0), max(max_w, (w-vc.back())))%m;
        
        long long ans = (max_h*max_w)%m;
        
        return ans;
    }
};