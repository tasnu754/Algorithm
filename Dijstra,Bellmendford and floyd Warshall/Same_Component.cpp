#include<bits/stdc++.h>

using namespace std;

int row, col;
char mt[1003][1003];
bool vis[1003][1003];
vector<pair<int, int>> d = {{0,1},{0,-1},{-1,0},{1,0}};

bool isInvalid(int i, int j){

    return(i<0 || i>=row || j<0 || j>=col);
}

void dfs(int si, int sj){

    vis[si][sj] = true;

    for(int i=0; i<4; i++){

        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(!vis[ci][cj] && !isInvalid(ci, cj) && mt[ci][cj]=='.'){
            dfs(ci, cj);
        }
    }

}

int main(){

    cin>>row>>col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>mt[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int si, sj, di, dj;
    cin>>si>>sj>>di>>dj;

    dfs(si, sj);

    if(vis[di][dj])
        cout<<"YES";
    else
        cout<<"NO";



    return 0;
}