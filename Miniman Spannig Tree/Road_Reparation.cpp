#include<bits/stdc++.h>

using namespace std;

class Edge{
    public:
        int u,v,w;

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

    int city, rd;
    long long total = 0;
    cin>>city>>rd;
    vector<Edge> edlist;
    init(city);

    while(rd--){
        int a, b;
        long long cst;
        cin>>a>>b>>cst;

        edlist.push_back(Edge(a,b,cst));

    }

    sort(edlist.begin(), edlist.end(), cmp);

    for(Edge e: edlist){
        int leadU = find(e.u);
        int leadV = find(e.v);

        if(leadU != leadV){
            total += e.w;
            union_by_Level(e.u, e.v);
        }
    }


        cout<<total<<endl;




    return 0;
}