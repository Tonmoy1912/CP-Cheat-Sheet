#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct dum{
    ll g,x,y;
};

dum exeuclid(ll a,ll b){
    dum ans;
    if(b==0){
        ans.g=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    dum next=exeuclid(b,a%b);
    ans.g=next.g;
    ans.x=next.y;
    ans.y=next.x-(a/b)*next.y;
    return ans;
}

ll mminverse(ll a,ll m){//return multiplicative inverse of a
    ll ans=exeuclid(a,m).x;
    ans=(ans%m+m)%m;
    return ans;
}