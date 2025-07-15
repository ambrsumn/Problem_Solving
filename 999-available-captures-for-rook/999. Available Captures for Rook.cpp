class Solution {
public:
    int numRookCaptures(vector<vector<char>>& b) {

        int r, c, ans=0;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(b[i][j] == 'R')
                {
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        //left
        for(int k=c-1; k>=0; k--)
        {
            if(b[r][k] == 'p')
            {
                ans++;
                break;
            }
            else if(b[r][k] == 'B')break;
        }
        // right
        for(int k=c+1; k<8; k++)
        {
            if(b[r][k] == 'p')
            {
                ans++;
                break;
            }
            else if(b[r][k] == 'B')break;
        }        
        //top
        for(int k=r-1; k>=0; k--)
        {
            if(b[k][c] == 'p')
            {
                ans++;
                break;
            }
            else if(b[k][c] == 'B')break;
        }
        // right
        for(int k=r+1; k<8; k++)
        {
            if(b[k][c] == 'p')
            {
                ans++;
                break;
            }
            else if(b[k][c] == 'B')break;
        }

        return ans;
    }
};