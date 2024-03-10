#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

ll timer=0;

void dfs(ll u, vector<ll> *adj, vector<ll> &disc, vector<ll> &low, stack<ll> &s, vector<bool> &stackMember){
    timer++;
    disc[u]=timer;
    low[u]=timer;
    s.push(u); 
    stackMember[u]=1; 
    for(auto v : adj[u]){
        if(disc[v]==0){
            //disc=0 for an unvisited vertex
            dfs(v,adj,disc,low,s,stackMember); 
            low[u]=min(low[u],low[v]);  
        }
        else if(stackMember[v]){
            //back-edge case
            low[u]=min(low[u],disc[v]); 
        }
    }
    // condition for SCC
    if(low[u]==disc[u]){
        while(s.top() != u){
            cout<<s.top()<<" "; 
            stackMember[s.top()]=0; 
            s.pop(); 
        }
        cout<<s.top()<<" "; 
        stackMember[s.top()]=0; 
        s.pop(); 
        cout<<endl; 
    }
}


int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll n,e;cin>>n>>e;
    vector<ll>adj[n];
    while(e--){
        ll x,y;cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll>disc(n,0),low(n);
    stack<ll>s;

    vector<bool>stackMember(n,0);

    //for loop to tackle with disconnected components
    for(int i=0;i<n;i++){
        if(disc[i]==0){
            dfs(i,adj,disc,low,s,stackMember);
        }
    }

    return 0;
}