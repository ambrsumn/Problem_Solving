class Solution {
public:
    bool uniformArray(vector<int>& nums1){
        int n=nums1.size();
        int n1=nums1[0];
        for(int i=1;i<n;i++){
            n1=min(n1,nums1[i]);
        }
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=n1%2){
                if(n1%2==0)
                    return false;
            }
        }
        return true;
    }
};
