#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

int main(){

    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll mx1=-INT32_MAX,mx2=-INT32_MAX;
    ll sum=0;
    for(ll i=0;i<n;i++){
        mx1=max(mx1,a[i]);
    }
    //mx1 is the largest element in the array so its added to the sum
    sum+=mx1;

    for(ll i=0;i<n;i++){
        if(a[i]==mx1){
            //this step is taken to deal with the case where there are multiple occurances of mx1
            mx1=-INT32_MAX;
        }
        else{
            //maximum array in the array excluding the largest element is calculated
            mx2=max(mx2,a[i]);
        }
    }
    //second largest element is added to the sum
    sum+=mx2;

    cout<<sum<<endl;
    //Time complexity of this solution is O(N)
      
return 0;
}