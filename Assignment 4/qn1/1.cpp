#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
ll inv=0;
ll n;

// modifying the existing merge sort algorithm to count the number of inversions
void merge_sort(ll *a,ll l,ll r){
    if(l==r)return;

    ll mid=(l+r)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);

    //counting the number of inversions while merging 
    ll merged_arr[r-l+1];
    ll i=l,j=mid+1,k=0;
    while(k<r-l+1){
        if(j>r||(i<=mid&&a[i]<a[j])){
            merged_arr[k]=a[i];
            i++;
        }
        else{
            merged_arr[k]=a[j];
            // remaining elements in the first half from [i,mid]
            inv+=mid+1-i;
            j++;
        }

        k++;
    }
    for(ll i=0;i<r-l+1;i++){
        a[l+i]=merged_arr[i];
    }
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;cin>>t;
    while(t--){
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        inv=0;
        merge_sort(a,0,n-1);
        cout<<inv<<endl;
    }



    return 0;
}