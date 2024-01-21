# include <bits/stdc++.h>
using namespace std;
#define ll long long

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

//this function returns the index of the median and sends the median to its right position
ll find_median(ll *a,ll l,ll r,ll m){
    ll p=loc_pivot(a,l,r);
    if(p==m){
        return p;
    }
    else if(p>m){
        return find_median(a,l,p-1,m);
    }
    else{
        return find_median(a,p+1,r,m);
    }
}

//creating a recursive quick sort function
void quick_sort(ll *a,ll left,ll right){

    if(left>=right)return;

    //taking the median element as the pivot
    ll pivot=find_median(a,left,right,(left+right)/2);
    //as the find_median function automatically places the pivot in its right position,so now proceeding to sort left and right halves of the array

    //now calling the recursive quick-sort function to left and right sides of the pivot
    quick_sort(a,left,pivot-1);
    quick_sort(a,pivot+1,right);
    
}


int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a[n];

        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        quick_sort(a,0,n-1);

        for(ll i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
    //Average case time complexity = O(NlogN)

}