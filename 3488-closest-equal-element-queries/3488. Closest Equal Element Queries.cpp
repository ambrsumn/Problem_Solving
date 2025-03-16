class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        
        map<int, vector<int>> mpp;
        vector<int> ans;
        int n = nums.size();

        for(int i=0; i<nums.size(); i++)mpp[nums[i]].push_back(i);

        if(mpp.size() == nums.size())
        {
            for(auto it : queries)ans.push_back(-1);
            return ans;
        }

        if(mpp.size() == 1)
        {
            for(auto it : queries)ans.push_back(1);
            return ans;
        }

        for(auto it : queries)
        {
            int num = nums[it];

            if(mpp[num].size() == 1)ans.push_back(-1);
            
            else
            {
                vector<int> idxVector = mpp[num];

                //FIRST ELEMENT
                if(idxVector[0] == it)
                {
                    int nextElement = idxVector[1];
                    int lastElement = idxVector.back();

                    if(nextElement == lastElement)
                    {
                        ans.push_back(min(abs(nextElement-it), (n- abs(nextElement-it))));
                    }
                    else
                    {
                        ans.push_back( min(min(abs(nextElement-it), (n- abs(nextElement-it))), min(abs(lastElement-it), (n- abs(lastElement-it)))));
                    }
                }

                //LAST ELEMENT
                else if(idxVector.back() == it)
                {
                    
                    int prevElement = idxVector[idxVector.size()-2];
                    int firstElement = idxVector[0];

                    if(prevElement == firstElement)
                    {
                        ans.push_back(min(abs(it-prevElement), (n-abs(it-prevElement))));
                    }
                    else
                    {
                        ans.push_back( min(min(abs(it-prevElement), (n-abs(it-prevElement))), min(abs(it-firstElement), (n-abs(it-firstElement)))));
                    }
                } 

                else 
                {
                    auto curr = find(idxVector.begin(), idxVector.end(), it);
                    int currPosition = *curr;

                    auto next = curr+1;
                    int nextPosition = *next;

                    auto prev = curr-1;
                    int prevPosition = *prev;

                    ans.push_back(min( min(abs(nextPosition-currPosition), (n- abs(nextPosition-currPosition))), min(abs(prevPosition-currPosition), (n- abs(prevPosition-currPosition)))));
                }

            }
        }


        return ans;
    }
};