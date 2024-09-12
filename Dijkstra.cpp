#include<bits/stdc++.h>

using namespace std;

vector<pair<long long, int>> adj[1005];
long long dis[1005];

void dijkstra(int src){

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty()){
        pair<long long, int> p = pq.top();
        pq.pop();

        long long d = p.first;
        int par = p.second;

        for(pair<long long, int> pr: adj[par]){
            long long cost = d + pr.first;

            if(dis[pr.second] > cost){
                dis[pr.second] = cost;
                pq.push({cost, pr.second});
            }
        }
    }
}

int main(){

    int v, e;
    cin>>v>>e;

    while(e--){
        int a, b;
        long long w;
        cin>>a>>b>>w;

        adj[a].push_back({w,b});

    }

    for(int i=1; i<=v; i++){
        dis[i] = 1e18;
    }

    int src, qr;
    cin>>src>>qr;

    dijkstra(src);

    while(qr--){
        int d;
        long long dw;
        cin>>d>>dw;

        if(dis[d] <= dw)
            cout<<"YES\n";
        else    
            cout<<"NO\n";

    }
    


    return 0;
}