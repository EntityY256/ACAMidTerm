#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
ll countWays(vector<int>& coins, int target_sum) {
    vector<ll> dp(target_sum + 1, 0);
    dp[0] = 1;
    for (ll coin : coins) {
        for (ll i = coin; i <= target_sum; ++i) {
            dp[i] += dp[i - coin];
            dp[i] %= 1000000007;
            // We consider coins greater than moving (increasing) values so that combinations gets counted ONLY ONCE
            // Without this constraint, we can over count different permutations
        }
    }
    
    return dp[target_sum]%1000000007;
}
 
int main() {
	int N,target_sum;
	cin>>N>>target_sum;
	vector<int> coins (N);
	for(int i=0;i<N;i++) cin>>coins[i];
    sort(coins.begin(),coins.end());
    cout <<countWays(coins, target_sum) << endl;
    return 0;
}
