#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<ll> prefix(n + 1, 0);    
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    deque<int> D;
    int MIN = n + 1;
    for (int i = 0; i <= n; ++i) {
        while (!D.empty() && prefix[i] - prefix[D.front()] >= k) {
            MIN = min(MIN, i - D.front());
            D.pop_front();
        }
        while (!D.empty() && prefix[i] <= prefix[D.back()]) {
            D.pop_back();
        }
        D.push_back(i);
    }
    return MIN == n + 1 ? -1 : MIN;
}
int main() {
    vector<int> nums;
    int N,K,M;
    cin>>N>>M;
    for(int i=0;i<N;i++) {cin>>K;nums.push_back(K);}
    int result = shortestSubarray(nums, M);
    cout<<result;
}