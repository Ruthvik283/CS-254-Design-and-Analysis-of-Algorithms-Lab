#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
ll cnt=0;
ll n,m;
void rrr(string *s,ll x,ll y){
    if(x>=n||x<0||y>=m||y<0)return;
    if(s[x][y]=='0')return;

    //making a cell 0 after visiting it
    s[x][y]='0';
    //incrementing cnt as we have entered a cell with value 1
    cnt++;
    for(ll i=-1;i<=1;i++){
        for(ll j=-1;j<=1;j++){
            rrr(s,x+i,y+j);
        }
    }
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>m;
    string a[n];

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll mx=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){

            cnt=0;
            rrr(a,i,j);
            mx=max(mx,cnt);
        }
    }

    cout<<mx<<endl;

    return 0;
}