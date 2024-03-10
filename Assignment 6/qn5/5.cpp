#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

//time counter variable
int timer=0;

void findAP(int u,vector<int>&disc,vector<int>&low,vector<int>&par,vector<bool>&AP,vector<pair<int,int>> &bridges,vector<int>*v){
    int children=0;
    timer++;
    disc[u]=timer;
    low[u]=timer;
    for(auto y:v[u]){
        if(disc[y]==0){
            //if not visited
            children++;
            par[y]=u;
            findAP(y,disc,low,par,AP,bridges,v);
            
            low[u]=min(low[u],low[y]);

            if(disc[u] < low[y]) bridges.push_back({u,y}); 
            if(par[u]!=-1&&low[y]>=disc[u]){
                AP[u]=true;
            }
            else if(par[u]==-1&&children>1){
                //root node has 2 children then its AP
                AP[u]=true;
            }

        }
        else if(y!=par[u]){
            low[u]=min(low[u],disc[y]);
        }
    }

}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;cin>>n;
    int e;cin>>e;
    vector<int>v[n];
    vector<int>disc(n,0),low(n,INT_MAX);
    vector<bool>AP(n,0);
    vector<pair<int,int>>bridges;
    vector<int>par(n,-1);

    for(int i=0;i<e;i++){
        int x,y;cin>>x>>y;
        x--,y--;
        v[x].pb(y);
        v[y].pb(x);
    }

    findAP(0,disc,low,par,AP,bridges,v);

    cout<<"Articulation Points: ";
    for(int i=0;i<n;i++){
        if(AP[i])cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Bridges: ";
    for(auto x:bridges){
        cout<<"{"<<x.first<<", "<<x.second<<" }"<<" ";
    }
    cout<<endl;

    return 0;
}