#include<bits/stdc++.h>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        int n, total = 0;
        cin>>n;


        int box[n];

        for(int i=0; i<n; i++){
            cin>>box[i];
            total += box[i];
        }

        if(total%2 == 1){
            cout<<"NO"<<endl;
        }
        else{
            int sum = total/2;
            bool dp[n+1][sum+1];

            for(int i=1; i<=sum; i++){
                dp[0][i] = false;
            }
            for(int i=0; i<=n; i++){
                dp[i][0] = true;
            }

            for(int i=1; i<=n; i++){
                for(int j=1; j<=sum; j++){
                    if(box[i-1] <= j){
                        dp[i][j] = dp[i-1][j-box[i-1]] || dp[i-1][j];
                    }
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }

            if(dp[n][sum])
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

        }

    }


    return 0;
}