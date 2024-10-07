#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int a[n];

        int max1 = INT_MIN;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(max1 < a[i])
                max1 = a[i];
        }

        int max2 = INT_MIN;
        for(int i=0; i<n; i++){
            if((max2 < a[i]) && (a[i] < max1))
                max2 = a[i];
        }

        int idx1, idx2;
        for(int i=0; i<n; i++){
            if(max1==a[i])
                idx1 = i;
            else if(max2==a[i])
                idx2 = i;
        }

        cout<<min(idx1, idx2)<<" "<<max(idx1, idx2)<<endl;

    }


    return 0;
}