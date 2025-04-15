class Solution {
public:

    int visited[51][51];

    void dfs(vector<vector<int>> &image, int i, int j, int color)
    {
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size())return;

        visited[i][j] = 1;
        int originalColor = image[i][j];
        image[i][j] = color;

        if(i+1 < image.size() && image[i+1][j] == originalColor && visited[i+1][j] == -1) dfs(image, i+1, j, color);
        if(i-1 >= 0 && image[i-1][j] == originalColor && visited[i-1][j] == -1) dfs(image, i-1, j, color);
        if(j+1 < image[0].size() && image[i][j+1] == originalColor && visited[i][j+1] == -1) dfs(image, i, j+1, color);
        if(j-1 >= 0 && image[i][j-1] == originalColor && visited[i][j-1] == -1) dfs(image, i, j-1, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        memset(visited, -1, sizeof(visited));
        dfs(image, sr, sc, color);

        return image;
    }
};