class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mpp;
        mpp[5]=0;
        mpp[10]=0;
        mpp[20]=0;

        for(auto it : bills)
        {
            mpp[it]++;
            int rem = it - 5;

            if(rem == 5)
            {
                if(mpp[5] > 0)
                {
                    mpp[5]--;
                }
                else return false;
            }

            if(rem == 15)
            {

                if(mpp[10] > 0 && mpp[5] > 0)
                {
                    mpp[10]--;
                    mpp[5]--;
                }
                else if(mpp[5] >= 3)
                {
                    mpp[5] -= 3;
                }
                else return false;
            }
        }

        return true;
    }
};