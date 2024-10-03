#include<bits/stdc++.h>

using namespace std;

long long mat[15][15];

int n,m;

long long max_paths(int si, int sj){

    if(si==n && sj==m) return mat[n][m];

    if(si>n || sj>m) return 0;


    long long right = max_paths(si, sj+1);
    long long down = max_paths(si+1, sj);

    return mat[si][sj] + max(right, down);
}

int main(){

    cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }

    long long ans = max_paths(1,1);

    cout<<ans<<endl;


    return 0;
}

