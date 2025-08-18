class Solution {
public:
  
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                } 
            }
        }
        vector<int> delrow={1,0,-1,0};
        vector<int> delcol={0,1,0,-1};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int count=q.front().second;
            q.pop();
            dis[i][j]=count;
            for(int k=0;k<4;k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},count+1});
                }
            }
            

        }
        return dis;

        //for bfs i need queue
        
        
    }
};