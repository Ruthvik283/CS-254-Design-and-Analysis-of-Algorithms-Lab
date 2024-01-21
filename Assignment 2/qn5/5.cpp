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
        ll n;cin>>n;
        ll a[n];

        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        ll min1=INT_MAX,min2=INT_MAX;
        for(ll i=0;i<n;i++){
            min1=min(min1,a[i]);
        }
    
        bool e=1;
        for(ll i=0;i<n;i++){
            if(a[i]==min1&&e){
                //ignoring the first occurance of minimum element 
                e=0;
            }
            else{
                min2=min(a[i],min2);
            }
        }

        //Time complexity: Here 2*n operations are conducted per calculation
        //Time complexity = O(N)

        cout<<min1<<" "<<min2<<endl;
    }
    return 0;
}