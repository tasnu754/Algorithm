#include<bits/stdc++.h>

using namespace std;

int n, m;
char mat[1001][1001];
pair<int, int> par[1001][1001];
bool vis[1001][1001];
vector<pair<int, int>> d = {{0,-1}, {0,1},{-1,0}, {1,0}};

bool valid(int i , int j){
    return (i>=1 && i<=n && j>=1 && j<=m);
}


void bfs(int si, int sj){

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int ci = p.first + d[i].first;
            int cj = p.second + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && mat[ci][cj]!='#'){
                q.push({ci, cj});
                vis[ci][cj] = true;
                par[ci][cj] = {p.first, p.second};
            }
        }
    }
}

int main(){

    int si, sj, di, dj;
    cin>>n>>m;

    memset(vis, false, sizeof(vis));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){    

            par[i][j] = {-1, -1};
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>mat[i][j];
            if(mat[i][j] == 'R'){
                si = i;
                sj = j;
            }
            else if(mat[i][j] == 'D'){
                di = i;
                dj = j;
            }
        }
    }

    bfs(si,sj);
    

    if(vis[di][dj]){
        
        int pi = di , pj = dj;

        while(mat[pi][pj]!='R'){

            mat[pi][pj] = 'X';

            pair<int, int> prev = par[pi][pj];

            pi = prev.first;
            pj = prev.second;

        }
        mat[di][dj] = 'D';

    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){    

            cout<<mat[i][j];
        }
        cout<<endl;
    }

    return 0;
}