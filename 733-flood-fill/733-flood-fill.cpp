class Solution {
public:
    
    int m=0,n=0,src=0;
    
    bool isValid(vector<vector<int>>& vec, int i, int j)
    {
        if(i>=0 && j>=0 && i<n && j<m && vec[i][j] == src)
            return true;
        
        return false;
    }
    
    void dfs(vector<vector<int>>& vec, int i, int j, int clr)
    {
        vec[i][j] = clr;
        
        if(isValid(vec, i+1, j))
            dfs(vec, i+1, j, clr);
        
        if(isValid(vec, i-1, j))
            dfs(vec, i-1, j, clr);
        
        if(isValid(vec, i, j+1))
            dfs(vec, i, j+1, clr);
        
        if(isValid(vec, i, j-1))
            dfs(vec, i, j-1, clr);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        n = image.size();
        m = image[0].size();
        src = image[sr][sc];
        
        if(src == color)
            return image;
        
        dfs(image, sr, sc, color);
        
        return image;
    }
};