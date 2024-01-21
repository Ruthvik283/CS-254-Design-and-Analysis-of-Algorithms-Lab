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

        //first merging the 2 arrays as done in the previous question and removing the duplicates from the merged array and storing them in a vector

        //here c is the merged array

        vector<ll>v;

        for(ll i=0;i<n+m;i++){
            ll y=c[i];
            v.push_back(y);
            while(i<n+m&&c[i]==y){
                i++;
            }
            i--;
        }

        for(ll i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}