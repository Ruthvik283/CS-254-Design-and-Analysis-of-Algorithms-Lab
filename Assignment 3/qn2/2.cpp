# include <bits/stdc++.h>
using namespace std;
# define ll long long
# define ld long double
# define pb push_back

//all corresponding values are stored in struct to reduce recalculations
struct arr_data{
    ll prefix_sum;//storing max prefix sum
    ll suffix_sum;//storing max suffix sum
    ll total_sum;//storing the total sum
    ll max_subarr_sum;//storing the max subarray sum
};


arr_data find(ll l,ll r,ll *a){
    arr_data ans;
    if(l==r){
        
        ans.prefix_sum=a[l];
        ans.suffix_sum=a[r];
        ans.total_sum=a[l];
        ans.max_subarr_sum=a[l];
        return ans;

    }
    ll mid=(l+r)/2;
    arr_data left=find(l,mid,a);
    arr_data right=find(mid+1,r,a);

    ans.prefix_sum=max(left.prefix_sum,left.total_sum+right.prefix_sum);

    ans.suffix_sum=max(right.suffix_sum,right.total_sum+left.suffix_sum);

    ans.total_sum=left.total_sum+right.total_sum;

    //from the left and right data the max subarray sum is returned in the form of struct
    ans.max_subarr_sum=max(max(left.max_subarr_sum,right.max_subarr_sum),left.suffix_sum+right.prefix_sum);
    return ans;
//this approach is similar to segment tree construction as the max_subarr_sum calculated by taking the precalculated values from its left and right branches
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

        arr_data ans = find(0,n-1,a);

        cout<<ans.max_subarr_sum<<endl;
        //Time complexity = O(N)
    }





    return 0;
}


