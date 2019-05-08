class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor==newColor) return image;
        dfs(image, sr, sc, newColor, oldColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor){
        int m = image.size(), n = image[0].size();
        if(sr>=0 && sc>=0 && sr<m && sc<n && image[sr][sc]==oldColor){
            image[sr][sc] = newColor;
            dfs(image, sr+1, sc, newColor, oldColor);
            dfs(image, sr, sc+1, newColor, oldColor);
            dfs(image, sr-1, sc, newColor, oldColor);
            dfs(image, sr, sc-1, newColor, oldColor);
        }
    }
};