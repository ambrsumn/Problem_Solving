class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> ans;
        int i=0,j=0,k=0,n=nums.size();
        
        
            //PUSHING SMALLER ELEMENTS
            do
            {
                int flag=0;
                
                if(nums[i]<pivot)
                {
                    ans.push_back(nums[i]);
                    i++; 
                    flag=1;
                }
                
                if(!flag)
                i++;
                
            }while(i<n);
        
        
            //PUSHING EQUAL ELEMENTS
            do
            {
                int flag=0;
                
                if(nums[j]==pivot)
                {
                    ans.push_back(nums[j]);
                    j++; 
                    flag=1;
                }
                
                if(!flag)
                j++;
                
            }while(j<n);
            
        
            //PUSHING GREATER ELEMENTS
            do
            {
                int flag=0;
                
                if(nums[k]>pivot)
                {
                    ans.push_back(nums[k]);
                    k++; 
                    flag=1;
                }
                
                if(!flag)
                k++;
                
            }while(k<n);
        
        
        return ans;
    }
};