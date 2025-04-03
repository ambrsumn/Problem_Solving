class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int diagonal =  grid.size()*2 - 1;
        int temp = 0;
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> mq;

        int i=0, j=0;
        while(temp < diagonal)
        {
            if(temp <= diagonal/2)
            {
                i = temp;
                j=0;


                int k = i, l = j;

                // storing by order

                while(k < grid.size())
                {
                    pq.push(grid[k][l]);
                    
                    k++;
                    l++;
                }

                k = i, l = j;

                while(k < grid.size())
                {
                    grid[k][l] = pq.top();
                    pq.pop();
                    k++;
                    l++;
                }
            }

            else
            {
                i = 0;
                j = (diagonal - temp);

                
                int k = i, l = j;

                // storing by order

                while(l < grid.size())
                {
                    mq.push(grid[k][l]);
                    
                    k++;
                    l++;
                }

                k = i, l = j;

                while(l < grid.size())
                {
                    grid[k][l] = mq.top();
                    mq.pop();
                    k++;
                    l++;
                }
            }

            temp++;
        }

        return grid;
        
    }
};