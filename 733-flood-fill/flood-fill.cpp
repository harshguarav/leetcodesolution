class Solution {
public:
    void dfs(vector<vector<int>>& image,int x,int y,int color,int ori){
    int n=image.size();
    int m=image[0].size();
    if(x<0 || y<0 || x>=n ||y>=m || image[x][y]!=ori) return;
    image[x][y]=color;

    dfs(image,x-1,y,color,ori);
    dfs(image,x,y-1,color,ori);

    dfs(image,x+1,y,color,ori);

    dfs(image,x,y+1,color,ori);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ori=image[sr][sc];
        if(ori==color){
            return image;
        }
        
        dfs(image,sr,sc,color,ori);
        return image;
        
    }
};