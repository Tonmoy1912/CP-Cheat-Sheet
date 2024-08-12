#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define endl '\n'

// template<typename T1,typename T2>
class SegmentTree{
    vector<ll> seg,lazy;

    void build(vector<ll> &arr,int idx,int low,int high){
        if(low==high){
            seg[idx]=arr[low];
            return ;
        }
        int mid=(low+high)/2;
        build(arr,2*idx+1,low,mid);
        build(arr,2*idx+2,mid+1,high);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }

    public:
    void build(vector<ll> &arr){
        int n=arr.size();
        seg.resize(4*n);
        lazy.resize(4*n);
        build(arr,0,0,n-1);
    }

    void rangeUpdate(int idx,int low,int high,int left,int right,ll val){
        if(lazy[idx]!=0){
            seg[idx]+=((high-low+1)*lazy[idx]);
            if(low!=high){
                lazy[2*idx+1]+=lazy[idx];
                lazy[2*idx+2]+=lazy[idx];
            }
            lazy[idx]=0;
        }
        if(high<left || low>right){
            return ;
        }
        if(low>=left && high<=right){
            seg[idx]+=((high-low+1)*val);
            if(low!=high){
                lazy[2*idx+1]+=val;
                lazy[2*idx+2]+=val;
            }
            return ;
        }
        int mid=(low+high)/2;
        rangeUpdate(2*idx+1,low,mid,left,right,val);
        rangeUpdate(2*idx+2,mid+1,high,left,right,val);
        seg[idx]=(seg[2*idx+1]+seg[2*idx+2]);
    }

    ll rangeQuery(int idx,int low,int high,int left,int right){
        if(lazy[idx]!=0){
            seg[idx]+=((high-low+1)*lazy[idx]);
            if(low!=high){
                lazy[2*idx+1]+=lazy[idx];
                lazy[2*idx+2]+=lazy[idx];
            }
            lazy[idx]=0;
        }
        if(high<left || low>right){
            return 0;
        }
        if(low>=left && high<=right){
            return seg[idx];
        }
        int mid=(low+high)/2;
        return rangeQuery(2*idx+1,low,mid,left,right) +
            rangeQuery(2*idx+2,mid+1,high,left,right);
    }
};  


int main(){
    vector<ll> arr={1,2,3,4,5,6,7,8,9,10};
    SegmentTree tree;
    tree.build(arr);
    cout<<tree.rangeQuery(0,0,9,0,3)<<endl;
    cout<<tree.rangeQuery(0,0,9,4,7)<<endl;
    cout<<tree.rangeQuery(0,0,9,0,7)<<endl;
    cout<<endl;

    tree.rangeUpdate(0,0,9,2,2,1);

    cout<<tree.rangeQuery(0,0,9,0,3)<<endl;
    cout<<tree.rangeQuery(0,0,9,4,7)<<endl;
    cout<<tree.rangeQuery(0,0,9,0,7)<<endl;
    cout<<endl;

    tree.rangeUpdate(0,0,9,4,7,1);

    cout<<tree.rangeQuery(0,0,9,0,3)<<endl;
    cout<<tree.rangeQuery(0,0,9,4,7)<<endl;
    cout<<tree.rangeQuery(0,0,9,0,7)<<endl;
    cout<<endl;

    for(int i=0;i<10;i++){
        cout<<tree.rangeQuery(0,0,9,i,i)<<" ";
    }
    cout<<endl<<endl;

    tree.rangeUpdate(0,0,9,5,6,1);

    cout<<tree.rangeQuery(0,0,9,0,3)<<endl;
    cout<<tree.rangeQuery(0,0,9,4,7)<<endl;
    cout<<tree.rangeQuery(0,0,9,0,7)<<endl;
    cout<<endl;

    for(int i=0;i<10;i++){
        cout<<tree.rangeQuery(0,0,9,i,i)<<" ";
    }
    cout<<endl<<endl;
    return 0;
}