#include<bits/stdc++.h>

using namespace std;

int par[100001];
int level[100001];

void init(int n){
    for(int i=0; i<n; i++){
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

void union_by_level(int a , int b){
    int leadA = find(a);
    int leadB = find(b);

    if(level[leadA] > level[leadB]){
        par[leadB] = leadA;
    }
    else if(level[leadA] < level[leadB]){
        par[leadA] = leadB;
    }
    else{
        par[leadB] = leadA;
        level[leadA]++;
    }
}

int main(){

    int n,e, cnt = 0;
    cin>>n>>e;
    init(n);

    while(e--){
        int a, b;
        cin>>a>>b;

        int leadA = find(a);
        int leadB = find(b);

        if(leadA == leadB){
            cnt++;
        }
        else{
            union_by_level(a,b);
        }
    }

    cout<<cnt<<endl;


    return 0;
}