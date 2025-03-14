class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {

        char dir = 'R';
        int top=0, bottom = m.size()-1, left = 0, right = m[0].size()-1;
        vector<int> ans;

        // cout<<top<<" "<<bottom<<" "<<right<<" "<<left<<" "<<dir<<endl;

        while(top <= bottom && left <= right)
        {
            if(dir == 'R')
            {
                for(int i=left; i<=right; i++)
                {
                    ans.push_back(m[top][i]);
                }

                top++;
                dir = 'B';

                // cout<<top<<" "<<bottom<<" "<<right<<" "<<left<<" "<<dir<<endl;

            }
            else if(dir == 'L')
            {
                for(int i=right; i>=left; i--)
                {
                    ans.push_back(m[bottom][i]);
                }

                bottom--;
                dir = 'T';

                // cout<<top<<" "<<bottom<<" "<<right<<" "<<left<<" "<<dir<<endl;

            }
            else if(dir == 'T')
            {
                for(int i=bottom; i>=top; i--)
                {
                    ans.push_back(m[i][left]);
                }

                left++;
                dir = 'R';

                // cout<<top<<" "<<bottom<<" "<<right<<" "<<left<<" "<<dir<<endl;

            }
            else if(dir == 'B')
            {
                for(int i=top; i<=bottom; i++)
                {
                    ans.push_back(m[i][right]);
                }

                right--;
                dir = 'L';

                // cout<<top<<" "<<bottom<<" "<<right<<" "<<left<<" "<<dir<<endl;

            }
        }

        return ans; 


        
    }
};