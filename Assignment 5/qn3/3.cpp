#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

//Disjoint Set Union
void make(ll x,ll *par){
    par[x]=x;
}
ll find_par(ll x,ll *par){
    if(par[x]!=x){
        return par[x]=find_par(par[x],par);
    }
    else return par[x];
}
void join(ll x,ll y,ll *par){
    ll px=find_par(x,par);
    ll py=find_par(y,par);
    par[py]=px;
}

// With the help of DSU checking whether a graph is bipartite or not
bool isBipartite(vector<vector<ll>>& graph) {
    ll n=graph.size();
    ll par[n];
    for(ll i=0;i<n;i++)par[i]=-1;
    for(ll i=0;i<n;i++){
        
        if(par[i]==-1){
            make(i,par);
        }
        if(graph[i].empty())continue;
        ll z=graph[i][0];
        if(par[z]==-1){
            make(z,par);
        }
        for(ll j=1;j<graph[i].size();j++){
            ll y=graph[i][j];
            if(par[y]==-1){
                make(y,par);
            }
            join(z,y,par);
        }
        if(find_par(i,par)==find_par(z,par))return false;

    }
    return true;
    //Time complexity = E log (V)
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //a graph can be divided in two cliques if its complement graph is Bipartitite
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a[n][n];
        // a[i][j] = 1 if there is a edge between i and j
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
            }
        }

        //a 2D vector v is created where v[u] is an vector of nodes that node u is adjacent to.
        vector<vector<ll>>v;

        for(ll i=0;i<n;i++){
            vector<ll>w;
            for(int j=0;j<n;j++){
                //Making a complement graph so places a edge between 2 vertices which arnt connected in the provided 2-D matrix
                if(a[i][j]==0&&i!=j){
                    w.push_back(j);
                }   
            }
            v.push_back(w);
        }

        if(isBipartite(v))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        // Space Complexity = O(v^2)
        // Time Complexity = O(max(v^2,Elog(V)))
    }


    return 0;
}