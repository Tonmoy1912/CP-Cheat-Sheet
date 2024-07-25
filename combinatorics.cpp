#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define endl '\n'

ll combinatorics(ll n, ll r){
    if(r==0 || r==n){
        return 1;
    }
    if(n-r<r){
        r=n-r;
    }
    ll ans=1;
    ll u=n-r+1;
    for(ll i=1;i<=r;i++){
        ans*=u;
        ans/=i;
        u++;
    }
    return ans;
}

int main(){
    int n=5;
    for(int i=0;i<=n;i++){
        cout<<combinatorics(n,i)<<endl;
    }
    return 0;
}