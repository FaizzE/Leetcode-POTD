typedef pair<int,pair<int,int>> P;
class Solution{
public:
    vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
    int trapRainWater(vector<vector<int>>& hMap){
        int rows=hMap.size(),cols=hMap[0].size();
        priority_queue<P,vector<P>,greater<>> pq;
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        for(int x=0;x<rows;x++)
            for(int y:{0,cols-1}){
                pq.push({hMap[x][y],{x,y}});
                vis[x][y]=true;
            }
        for(int y=0;y<cols;y++)
            for(int x:{0,rows-1}){
                pq.push({hMap[x][y],{x,y}});
                vis[x][y]=true;
            }

        int water=0;
        while(!pq.empty()){
            auto [ht,cell]=pq.top();
            pq.pop();
            int i=cell.first,j=cell.second;
            for(vector<int>&d:dirs){
                int ni=i+d[0],nj=j+d[1];
                if(ni>=0&&ni<rows&&nj>=0&&nj<cols&&!vis[ni][nj]){
                    water+=max(0,ht-hMap[ni][nj]);
                    pq.push({max(ht,hMap[ni][nj]),{ni,nj}});
                    vis[ni][nj]=true;
                }
            }
        }
        return water;
    }
};
