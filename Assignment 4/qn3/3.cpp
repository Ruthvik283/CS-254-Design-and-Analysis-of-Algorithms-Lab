#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

ll loc_pivot(ll *a ,ll l ,ll r){
    //choosing a random pivot using rand() function to minimize the occurance of worst case
    ll p=(rand()%(r-l+1));
    swap(a[r],a[l+p]);
    ll y=a[r];    

    ll i=l,j=l;
    while(j<r){
        if(a[j]<y){
            swap(a[i],a[j]);
            i++;
        }
        j++;
    }
    swap(a[i],a[r]);
    //pivot is placed at its right index and its position is returned
    return i;
}


ll find_element(ll *a,ll l,ll r,ll m){
    ll p=loc_pivot(a,l,r);
    if(p==m){
        return a[p];
    }
    else if(p>m){
        return find_element(a,l,p-1,m);
    }
    else{
        return find_element(a,p+1,r,m);
    }
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++)cin>>a[i];
        //k th largest is at (n-k)th index in the array
        cout<<find_element(a,0,n-1,n-k)<<endl;
        
        //Average case time complexity is O(N)
        //Worst case time complexity is O(N^2)
    }


    return 0;
}