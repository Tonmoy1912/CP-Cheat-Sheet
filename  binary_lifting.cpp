// Problem Url : https://cses.fi/problemset/task/1687

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define endl '\n'

void build(vector<vector<int>> &dp,vector<int> &parent,int n){
    for(int i=1;i<=n;i++){
        dp[i][0]=parent[i];
    }
    for(int l=1;l<=20;l++){
        for(int i=1;i<=n;i++){
            if(dp[i][l-1]!=-1){
                dp[i][l]= dp[dp[i][l-1]][l-1];
            }
            else{
                dp[i][l]=-1;
            }
        }
    }
}

int getAns(vector<vector<int>> &dp,int x,int k){
    int node=x;
    for(int i=20;i>=0;i--){
        if((k>>i)&1){
            if(dp[node][i]!=-1){
                node=dp[node][i];
            }
            else{
                return -1;
            }
        }
    }
    return node;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> parent(n+1,-1);    
    for(int i=2;i<=n;i++){
        cin>>parent[i];
    }
    vector<vector<int>> dp(n+1,vector<int> (21,-1)); // dp[node_x][l] --> ancestor node 2^l level up from node_x;
    build(dp,parent,n);
    vector<int> ans;
    while(q){
        int x,k;
        cin>>x>>k;
        ans.push_back(getAns(dp,x,k));
        q--;
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cout<<fixed;
    cout<<setprecision(10);
    // ll t;cin>>t;
    // for(ll i=0;i<t;i++){
        solve();
    // }
    
    return 0;
}