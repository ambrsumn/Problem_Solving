class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int i=0,j=0;
        while(i>=0 && j>=0 && i<m && j<n) // should not go aout of bound
        {
		// we set -1 if we go out of bound for any direction
            int up = i-1<0?-1:mat[i-1][j];
            int right = j+1>=n?-1:mat[i][j+1];
            int down = i+1>=m?-1:mat[i+1][j];
            int left = j-1<0?-1:mat[i][j-1];
            
		//as soon we get any peak element we return it's coordinates
            if(mat[i][j]>up && mat[i][j]>left && mat[i][j]>down && mat[i][j]>right)
                return {i,j};
            
		//else we take max of all 4 directions
            int maxi=max(up,max(right,max(down,left)));
            
		// max was present in whichever direction we go to that respective coordinate
            if(up==maxi)
                i--;
            else if(right==maxi)
                j++;
            else if(down==maxi)
                i++;
            else
                j--;
        }
        return {}; // this case will never happen but as return type is vector we nned to return empty
    }
};