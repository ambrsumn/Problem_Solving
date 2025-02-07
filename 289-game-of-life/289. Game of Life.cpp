class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        for(int i=0; i<temp.size(); i++)
        {
            for(int j=0; j<temp[0].size(); j++)
            {
                bool living = temp[i][j];
                int liveN = 0;
                int deadN = 0;

                if(i>0)
                {
                    if(temp[i-1][j] == 1)liveN++;
                    else deadN++;
                }
                if(i < temp.size()-1)
                {
                    if(temp[i+1][j] == 1)liveN++;
                    else deadN++;


                }
                if(j>0)
                {
                    if(temp[i][j-1])liveN++;
                    else deadN++;
                }
                if(j < temp[0].size()-1)
                {
                    if(temp[i][j+1] == 1)liveN++;
                    else deadN++;
                }

                if(i>0 && j>0)
                {
                    if(temp[i-1][j-1] == 1)liveN++;
                    else deadN++;
                }
                if(i<temp.size()-1 && j<temp[0].size()-1)
                {
                    if(temp[i+1][j+1] == 1)liveN++;
                    else deadN++;

                }
                if(i>0 && j<temp[0].size()-1)
                {
                    if(temp[i-1][j+1] == 1)liveN++;
                    else deadN++;
                }
                if(i<temp.size()-1 && j>0)
                {
                    if(temp[i+1][j-1])liveN++;
                    else deadN++;
                }


                if(living)
                {
                    if(liveN < 2)board[i][j] = 0;
                    if(liveN > 3)board[i][j] = 0;
                    if(liveN == 2 || liveN == 3)board[i][j] = 1;
                }
                if(!living)
                {
                    if(liveN == 3)board[i][j] = 1;
                }

            }
        }
        
    }
};