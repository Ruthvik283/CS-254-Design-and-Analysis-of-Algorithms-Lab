#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

//This function returns the value at the provided number (snake,ladder or none) by searching in the input vector
ll rrr(vector<vector<ll>>& v,ll y){
    ll n=v.size();
    ll val = y;
    y=(val+n-1)/n;
    ll x=val-(y-1)*n;
    if(y%2==0){
        x=n+1-x;
    }
    if(v[n-y][x-1]==-1){
        // if none then the same number is returned
        return val;
    }   
    return v[n-y][x-1];
    //Time complexity = O(1)
}

// This function returns the min number of required throws
ll solve(vector<vector<ll>>& v) {
    ll n=v.size();
    priority_queue<pair<ll,ll>>q;
    //level = number of throws
    //storing {-level,number} in pq so that the one with lowest level comes at the top
    q.push({0,1});
    ll u = n*n;
    //storing the minimum level in the visited array
    vector<ll>vis(u,INT_MAX);
    while(!q.empty()){
        auto p=q.top();
        q.pop();
        if(p.second==n*n){
            return -p.first;
        }
        ll r=p.second,lev=-p.first;
        for(ll i=1;r+i<=(min(n*n,r+6));i++){
            if(vis[rrr(v,r+i)-1]>lev+1){
            q.push({-lev-1,rrr(v,r+i)});
            vis[rrr(v,r+i)-1]=lev+1;
            }
        }
    }
    //if its impossible to reach the end then returning -1
    return -1;



}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<vector<ll>>v(n);
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
            ll x;cin>>x;
            v[i].pb(x);
            }
        }
        cout<<solve(v)<<endl;
        //Time complexity = O(n*n log (n))
        //Space complexity = O(n*n)
    }
    return 0;
}