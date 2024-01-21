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

        vector<ll>v;

        ll i=0,j=0,k=0;

        while(i<n&&j<m){
            if(a[i]<b[j]){
                i++;
            }
            else if(b[j]<a[i]){
                j++;
            }
            else{
                //when both are equal
                v.push_back(a[i]);
                i++;
                j++;
            }
        }

        for(ll i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}