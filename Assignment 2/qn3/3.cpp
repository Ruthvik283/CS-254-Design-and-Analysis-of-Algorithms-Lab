#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

void inplace_merge(ll *a,ll start,ll end,ll m){


    // using the same code of qn2.cpp and creating a void function
    ll i=start,j=start+m;

    while(j<=end){
        if(i<j){
            if(a[i]<=a[j]){
                i++;
            }
            else{
                ll y=a[j];
                //minimising the use swaps by following this method
                for(ll k=j;k>i;k--){
                    a[k]=a[k-1];
                }
                a[i]=y;
                i++;
                j++;
            }
        }
        else break;
    }
    //Time complexity = O(n^2) as we are using a inplace merge algorithm

}

void merge_sort(ll *a,ll start,ll end){

    if(start==end)return;

    ll mid=(start+end)/2;

    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    //we get 2 sorted arrays so using the inplace merge function
    inplace_merge(a,start,end,mid-start+1);
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;

        ll a[n];

        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        merge_sort(a,0,n-1);

        for(ll i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}