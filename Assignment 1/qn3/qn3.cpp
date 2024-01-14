#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

//2-D vectors are globally defined and resized to make it easier access within functions
vector<vector<ll>> d;
//2-D dp vector is used with dp(j,states) states->set(in binary representation) and the vertex j->(the ending point)
vector<vector<ll>> dp;

ll n;

ll find_dp(ll i,ll s){
    if(dp[i][s] != 0){
        return dp[i][s];
    }

    if(__builtin_popcount(s) == 2){
        return dp[i][s] = d[0][i];
    }

    int ans = INT_MAX;
    for(ll j=1;j<n;j++){
        if((s&(1<<j)) && j!=i){
            ans=min((ll)ans,(find_dp(j,(s^(1<<i)))+d[j][i]));
        }
    }
    return dp[i][s]=ans;
}


void solve(){
    cin>>n;
    d.resize(n);
    dp.resize(n);

    for(ll i=0;i<n;i++){
        d[i].resize(n);
        for(ll j=0;j<n;j++){
            cin>>d[i][j];
        }
        dp[i].resize(1<<n);
        for(ll j=0;j<(1<<n);j++){
            dp[i][j]=0;
        }
    }
    ll d_min=INT_MAX;

    for(ll j=1;j<n;j++){
  
        d_min=min(d_min, find_dp(j,((1<<n)-1)) + d[j][0]);
    }

    cout<<d_min<<endl;

}




int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll t;cin>>t;
    while(t--){
        solve();
    }

return 0;
}