class Solution {
public:
    int n,m;
    vector<vector<char>> grid;
    using state = pair<int,int>;
    vector<vector<int>> vis,compo;
    #define F first
    #define S second
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<state> neighbours(state cur){
        vector<state> neigh;
        for(int d = 0;d<4;d++){
            int nx = cur.F + dx[d];
            int ny = cur.S + dy[d];
            if(nx>=0 && nx<n && ny>=0 && ny < m && vis[nx][ny] == 0 && grid[nx][ny] == '1'){
                neigh.push_back({nx,ny});
            }
        }
        return neigh;
    }
    void dfs(state st , int compo_no){
        vis[st.F][st.S] = 1;
        compo[st.F][st.S] = compo_no;
        for(auto v : neighbours(st)){
            if(!vis[v.F][v.S]){
                dfs(v,compo_no);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        vis.assign(n+1,vector<int>(m+1,0));
        compo.assign(n+1,vector<int>(m+1,0));
        int compo_no = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j < m ;j++){
                    if(!vis[i][j] && grid[i][j] == '1'){
                    compo_no++;
                    state st = {i,j};
                    dfs(st,compo_no);
                }
            }
        }
        return compo_no;
    }
};
