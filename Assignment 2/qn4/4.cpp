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
    return i;
}


ll e=INT_MAX;

ll find_median(ll *a,ll l,ll r,ll m){
    ll p=loc_pivot(a,l,r);
    if(p==m){
        return a[p];
    }
    else if(p>m){
        return find_median(a,l,p-1,m);
    }
    else{
        //checking for the even case here itself to reduce the number of operations
        if(p==m-1)e=a[p];
        return find_median(a,p+1,r,m);
    }
}


int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //naive approach: Sort the array in O(NlogN) and select the median in O(1). Total time complexity is O(NlogN)

    //using quick select algorithm so that best and average case time complexity can be improved

    ll t;cin>>t;

    while(t--){
        ll n;cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        //assigning INT_MAX to the local variable e which keeps a track whether median-1 element has been already found while searching for median element
        e=INT_MAX;

        ll y=find_median(a,0,n-1,n/2);
        if(n%2){
            cout<<y<<endl;
        }
        else{
            if(e!=INT_MAX){
                cout<<fixed<<setprecision(1)<<(ld)(y+e)/2<<endl;
            }
            else{
                e=find_median(a,0,(n/2)-1,(n/2)-1);

                cout<<fixed<<setprecision(1)<<(ld)(y+e)/2<<endl;
            }
        }

    }

    //Average case time complexity is O(N)
    //Worst case time complexity is O(N^2)
    
    return 0;
}