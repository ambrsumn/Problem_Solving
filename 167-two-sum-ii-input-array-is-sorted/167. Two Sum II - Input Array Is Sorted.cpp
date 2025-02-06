class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        multimap<int, int> mpp;
        vector<int> vec;

        int i = 0;
        for (auto it : numbers) {
            mpp.insert(pair<int, int>(it, i));
            i++;
        }

        for (auto it : mpp) {
            cout << it.first << " " << it.second << endl;
        }

        for (auto it : mpp) {
            int rem = target - it.first;

            if (rem != it.first) {
                auto itr = mpp.find(rem);
                if (itr != mpp.end()) {
                    vec.push_back(it.second+1);
                    vec.push_back(itr->second+1);
                    return vec;
                }
            }
        }

        int ans = target/2;

        auto range = mpp.equal_range(ans);

        for(auto it=range.first; it!=range.second; it++)
        {
            vec.push_back(it->second+1);
            if(vec.size() == 2)return vec;
        }

        
        return vec;
    }
};