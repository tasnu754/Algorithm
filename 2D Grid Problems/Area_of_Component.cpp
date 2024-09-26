#include<bits/stdc++.h>

using namespace std;

int n, m;
char mat[1001][1001];
bool vis[1001][1001];
vector<pair<int, int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
int minCost = INT_MAX;
int ans = 0;

bool valid(int i , int j){
    return (i>=1 && i<=n && j>=1 && j<=m);
}

void dfs(int si , int sj){
    
    vis[si][sj] = true;
    ans++;
    
    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci,cj) && !vis[ci][cj] && mat[ci][cj]=='.'){
            dfs(ci, cj);
        }
    }
}

int main(){

    cin>>n>>m;
    memset(vis, false, sizeof(vis));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m;j++){
            cin>>mat[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m;j++){

            if(!vis[i][j] && mat[i][j]=='.'){
                ans = 0;
                dfs(i, j);
                if(ans < minCost)
                    minCost = ans;
                }
        }
    }

    if(ans==0)
        cout<<"-1"<<endl;
    else
        cout<<minCost<<endl;


    return 0;
}