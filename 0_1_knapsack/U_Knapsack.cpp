#include<bits/stdc++.h>

using namespace std;
int wt[1001];
int val[1001];

int knapsack(int n, int w){

    if(n == 0 || w == 0) return 0;

    if(wt[n-1] <= w){
        int op1 = knapsack(n-1, w-wt[n-1]) + val[n-1];
        int op2 = knapsack(n-1, w);

        return max(op1, op2);
    }
    else{
        int op2 = knapsack(n-1, w);

        return op2;
    }
}

int main(){

    int n, w;
    cin>>n>>w;

    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;

        wt[i] = a;
        val[i] = b;
    }

    int v = knapsack(n, w);
    cout<<v<<endl;




    return 0;
}