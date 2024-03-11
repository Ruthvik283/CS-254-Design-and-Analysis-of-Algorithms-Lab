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
    vector<int>v[n];
    for(int i=0;i<e;i++){
        int x,y;cin>>x>>y;
        x--,y--;
        v[x].pb(y);
    }
    vector<int>indeg(n,0);
    for(int i=0;i<n;i++){
        for(auto x:v[i]){
            indeg[x]++;
        }
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0)q.push(i);
    }

    while(!q.empty()){
        int y=q.front();
        cout<<y<<" ";
        q.pop();
        for(auto x:v[y]){
            indeg[x]--;
            if(indeg[x]==0){q.push(x);}
        }
    }
    cout<<endl;

    return 0;
}