#include<bits/stdc++.h>

using namespace std;

int dp[100005];

bool isPossible(int x, int n){

    if(x == n) return true;

    if(x > n) return false;

    if(dp[x] != -1) return dp[x];

    bool add = isPossible(x+3, n);
    bool multy = isPossible(x*2, n);

    return (dp[x] = add || multy);
}

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        memset(dp, -1, sizeof(dp));
        if(isPossible(1,n))
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }


    return 0;
}