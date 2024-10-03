#include<bits/stdc++.h>

using namespace std;

bool reach(long long x, long long n){

    if(x==n) return true;
    if(x > n) return false;

    bool op1 = reach(x*10, n);
    bool op2 = reach(x*20, n);

    return op1 || op2;

}

int main(){

    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        if(reach(1,n)) 
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
    }


    return 0;
}