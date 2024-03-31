#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

/*
A greedy approach for this problem is to sort the items based on their value-to-weight ratio in non-increasing order and then select items greedily until the weight limit is reached.
The greedy approach for the knapsack problem isn't always optimal because making decisions based solely on the current best local choice (i.e., the highest value-to-weight ratio) will not necessarily lead to the global optimal solution.
So solving the given problem using dp.
*/

int main(){

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
		
		ll n;cin>>n;

		ll w[n],v[n];

		ll max_weight;
        cin>>max_weight;
        //cout<<"Enter weights"<<endl;
		for(ll i=0;i<n;i++){
			cin>>w[i];
		}
        //cout<<"Enter corresponding values"<<endl;
		for(ll i=0;i<n;i++){
			cin>>v[i];
		}

		

		ll dp[max_weight+1]={0};
        //instead of creating a 2-D dp array, another 1-D dp array is created for the purpose of storing the previous row values and space complexity has been optimized
        vector<ll>seq[max_weight+1];//for getting the values included as it has been asked in the question
		for(ll j=0;j<n;j++){
			for(ll i=max_weight;i>0;i--){
				if(w[j]<=i){                    		
                    if(dp[i]<dp[i-w[j]]+v[j]){
                        seq[i].assign(seq[i-w[j]].begin(),seq[i-w[j]].end());
                        seq[i].pb(j);
                        dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
                    }
				}
			}
		}
        cout<<"total cost: ";
		cout<<dp[max_weight]<<endl;
        cout<<"included items: ";
        for(auto x:seq[max_weight]){
            cout<<x+1<<" ";
        }
        cout<<endl;
        //Time Complexity:O(n^2*w) n^2 coz we have to store the sequence also as it has been mentioned in the question
return 0;
}