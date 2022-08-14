class Solution {
public:
    int firstMissingPositive(vector<int>& arr) 
    {
       unordered_map<int,int>mpp;
        
       for(int i=0;i<arr.size();i++)
       {
           mpp[arr[i]]++;
       }
       
       int p=1, n = arr.size()+1;
       
       while(n--)
       {
           if(mpp[p]>0)
           {
               p++;
           }
           else
           {
               return p;
           }
       }
        
        return p;
    }
};