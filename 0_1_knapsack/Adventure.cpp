#include<bits/stdc++.h>

using namespace std;

int wt[1005];
int val[1005];

int dp[1005][1005];

int knapsack(int n, int sum){

    if(n==0) return 0;

    if(dp[n][sum] != -1) return dp[n][sum];

    if(wt[n-1] <= sum){

        int take = knapsack(n-1, sum-wt[n-1]) + val[n-1];
        int notTake = knapsack(n-1, sum);

        return dp[n][sum] = max(take, notTake);
    }
    else{

        int notTake = knapsack(n-1, sum);

        return dp[n][sum] =  notTake;  
    }

    
}

int main(){

    int t;
    cin>>t;


    while(t--){
        int n, s;
        cin>>n>>s;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=s; j++){
                dp[i][j] = -1;
            }
        }

        for(int i=0; i<n; i++){
            cin>>wt[i];
        }
        for(int i=0; i<n; i++){
            cin>>val[i];
        }

        cout<<knapsack(n,s)<<endl;

    }


    return 0;
}