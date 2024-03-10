#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,e;cin>>n>>e;
    vector<pair<int,int>>v[n];
    
    for(int i=0;i<e;i++){
        int x,y,wt;
        cin>>x>>y;
        x--,y--;
        //taking weight 1 as unweighted graph has been provided in the question
        wt=1;
        v[x].pb({y,wt});
    }

    vector<int>indeg(n,0);
    for(int i=0;i<n;i++){
        for(auto x:v[i]){
            indeg[x.first]++;
        }
    }
    vector<int>dis(n,-1);

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){q.push(i);dis[i]=0;}
    }
    int max_dist=0;
    while(!q.empty()){
        int sz=q.size();
        int y=q.front();
        q.pop();
        max_dist=max(dis[y],max_dist);
        for(auto x:v[y]){
            indeg[x.first]--;
            if(indeg[x.first]==0){q.push(x.first);}
            dis[x.first]=max(dis[x.first],x.second+dis[y]);
        }
    }
    cout<<max_dist<<endl;

    return 0;
}