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
        ll n, m;
        cin>>n>>m;

        ll a[n],b[m];

        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        for(ll i=0;i<m;i++){
            cin>>b[i];
        }

        ll c[n+m];

        ll i=0,j=0,k=0;

        while(i<n||j<m){
            if(i>=n){
                c[k]=b[j++];
            }
            else if(j>=m){
                c[k]=a[i++];
            }
            else if(a[i]>=b[j]){
                c[k]=b[j++];
            }
            else{
                c[k]=a[i++];
            }
            k++;
        }

        for(ll i=0;i<n+m;i++){
            cout<<c[i]<<" ";
        }
        cout<<endl;   
    }
    return 0;
}