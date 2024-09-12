#include<bits/stdc++.h>

using namespace std;

vector<Edge> adj;
long long dis[1005];


class Edge{

    public:
        int u;
        int v;
        int wt;

        Edge(int u, int v, int wt){
            this->u = u;
            this->v = v;
            this->wt = wt;
        }
};

int main(){

    int v, e;
    cin>>v>>e;

    while(e--){
        int a, b;
        long long w;
        cin>>a>>b>>w;

        adj.push_back(Edge(a,b,w));
    }

    for(int i=1; i<=v; i++){
        dis[i] = 1e18;
    }

    int src;
    cin>>src;
    dis[src] = 0;

    for(int i=0; i<v-1; i++){
        for(Edge ed: adj){

            if(dis[ed.u]<1e18 && (dis[ed.u]+ed.wt < dis[ed.v])){
                dis[ed.v] = dis[ed.u]+ed.wt;
            }
        }
    }

    int q;
    cin>>q;

    while(q--){
        int d;

        if(dis[src]<0)
            cout<<"Negative Cycle Detected\n";
        else if(src==d)
            cout<<"0\n";
        else{
            if(dis[d]==1e18)
                cout<<"Not Possible";
            else{
                cout<<dis[d];
            }
        }
    }


    return 0;
}