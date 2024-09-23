#include<bits/stdc++.h>

using namespace std;


int n, m;
bool vis[100][100];
int dis[100][100];
vector<pair<int, int>> d = {{-2,1},{-2,-1},{2,1},{2,-1}, {-1,2}, {1,2}, {-1,-2}, {1,-2}};

bool isInvalid(int i, int j){

    return(i<0 || i>=n|| j<0 || j>=m);
}

void bfs(int si, int sj){

    queue<pair<int, int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;

        for(int i=0; i<8; i++){
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if(!vis[ci][cj] && !isInvalid(ci,cj)){
                q.push({ci,cj});
                dis[ci][cj] = dis[pi][pj] + 1;
                vis[ci][cj] = true;
            }
        }
    }

}

int main(){

    int t;
    cin>>t;
    while(t--){
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));

        int si, sj, di, dj;
        cin>>n>>m>>si>>sj>>di>>dj;

        bfs(si, sj);


        cout<<dis[di][dj]<<endl;

    }

    return 0;
}