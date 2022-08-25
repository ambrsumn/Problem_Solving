class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int sp = n, t = 1, top = 0, bottom = sp - 1, left = 0, right = sp - 1;
        vector<vector<int>> vec(sp, vector<int>(sp, 0));

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                vec[top][i] = t;
                t++;
            }
            top++;

            for (int i = top; i <= bottom; i++)
            {
                vec[i][right] = t;
                t++;
            }
            right--;

            if (top <= bottom && left <= right)
            {
                for (int i = right; i >= left; i--)
                {
                    vec[bottom][i] = t;
                    t++;
                }
                bottom--;

                for (int i = bottom; i >= top; i--)
                {
                    vec[i][left] = t;
                    t++;
                }
                left++;
            }
        }
        
        return vec;
    }
};