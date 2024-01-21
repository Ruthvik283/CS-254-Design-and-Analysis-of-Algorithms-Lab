#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;cin>>t;
    while(t--){
        ll n,m;

        cin>>n>>m;

        ll a[n];

        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        ll i=0,j=m;

        while(j<n){
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

        for(ll i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;

    }



    return 0;
}