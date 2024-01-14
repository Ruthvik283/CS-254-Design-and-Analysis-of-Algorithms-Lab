#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

int main(){
		
		ll n;cin>>n;

		ll w[n],v[n];

		ll max_weight;
        cout<<"Enter weights"<<endl;
		for(ll i=0;i<n;i++){
			cin>>w[i];
		}
        cout<<"Enter corresponding values"<<endl;
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}

		cin>>max_weight;

		ll dp[max_weight+1]={0};
        //instead of creating a 2-D dp array, another 1-D dp array is created for the purpose of storing the previous row values and space complexity has been optimized
		ll dp1[max_weight+1]={0};
		for(ll j=0;j<n;j++){
            dp1[0]=dp[0];
			for(ll i=1;i<=max_weight;i++){
                dp1[i]=dp[i];
				if(w[j]<=i){                    
					dp[i]=max(dp[i],dp1[i-w[j]]+v[j]);
				}
			}
            for(ll i=1;i<=max_weight;i++){
                dp1[i]=dp[i];
			}
		}
		cout<<dp[max_weight]<<endl;
		
		




   
return 0;
}