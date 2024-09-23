#include<bits/stdc++.h>

using namespace std;

int main(){

    long long v, e;
    cin>>v>>e;
    long long adj[v+1][v+1];

    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i==j)
                adj[i][j] = 0;
            else{
                adj[i][j] = 1e18;
            }
        }
    }


    while(e--){
        long long a, b;
        long long w;
        cin>>a>>b>>w;

        if(w < adj[a][b])
            adj[a][b] = w;

    }

    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(adj[i][k]+adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }

    int q;
    cin>>q;

    while(q--){
        long long a, b;
        cin>>a>>b;

        if(adj[a][b]==1e18)
            cout<<"-1"<<endl;
        else{
            cout<<adj[a][b]<<endl;
        }
    }



    return 0;
}