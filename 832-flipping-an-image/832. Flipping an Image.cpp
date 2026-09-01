class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &it:image) {
            for (auto &jt:it) {
                jt=1-jt;
            }
            reverse(it.begin(),it.end());
        }
        return image;
        
    }
};