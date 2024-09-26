#include<bits/stdc++.h>

using namespace std;

class Edge{
    public:
        int u,v;
        long long w;

        Edge(int u, int v, int w){
            this->u = u;
            this->v = v;
            this->w = w;
        }
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int par[100001];
int level[100001];
bool vis[100001];

void init(int node){
    for(int i=1; i<=node; i++){
        par[i] = -1;
        level[i] = 0;
    }
}

int find(int x){
    if(par[x] == -1) return x;
    int leader = find(par[x]);
    par[x] = leader;
    return leader;
}

void union_by_Level(int x, int y){
    int leadX = find(x);
    int leadY = find(y);

    if(level[leadX] == level[leadY]){
        par[leadY] = leadX;
        level[leadX]++;
    }
    else if(level[leadX] > level[leadY]){
        par[leadY] = leadX;
    }
    else{
        par[leadX] = leadY;
    }

}

int main(){

    int n,e;
    long long cst = 0;
    bool ans = 1;
    cin>>n>>e;
    vector<Edge> edlist;
    init(n);

    while(e--){
        int u, v;
        long long w;
        cin>>u>>v>>w;

        edlist.push_back(Edge(u,v,w));

    }

    sort(edlist.begin() , edlist.end(), cmp);

    for(Edge e: edlist){

        int leadU = find(e.u);
        int leadV = find(e.v);

        if(leadU != leadV){
            cst += e.w;
            union_by_Level(e.u, e.v);
        }

    }
        for(int i=2; i<=n; i++){
            if(find(i-1) != find(i)){
                ans = 0;
                break;
            }
        }

        if(ans)
            cout<<cst<<endl;
        else
            cout<<"-1"<<endl;


    return 0;
}