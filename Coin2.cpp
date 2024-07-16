#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
ll countWays(vector<int>& coins, int target_sum) {
    vector<ll> dp(target_sum + 1, 0);
    dp[0] = 1;
 
    // Iterate over each possible sum from 1 to target_sum
    for (ll coin : coins) {
        // Update the dp array for each sum that can be achieved using the current coin
        for (ll i = coin; i <= target_sum; ++i) {
            dp[i] += dp[i - coin];
            dp[i] %= 1000000007;
        }
    }
    
    return dp[target_sum]%1000000007;
}
 
int main() {
	int N,target_sum = 9;
	cin>>N>>target_sum;
	vector<int> coins (N);
	for(int i=0;i<N;i++) cin>>coins[i];
    sort(coins.begin(),coins.end());
    cout <<countWays(coins, target_sum) << endl;
    return 0;

