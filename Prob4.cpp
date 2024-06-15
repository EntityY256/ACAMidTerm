#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll max(ll P, ll Q){
	if(P>Q) return P;
	else return Q;
}
ll possible(int NUM[], int COST[], int N, int token, ll  maxpos){
	if(N==0){
		if(token>=COST[N]) return NUM[N];
		else return 0;
	}
	else return max(NUM[N]+possible(NUM,COST,N-1,token-COST[N],maxpos+NUM[N]),possible(NUM,COST,N-1,token,maxpos));
	
}
int main() {
	int T,N,K;
	cin>>T;
	while(T--){
	    cin>>N>>K;
	    int cost[N],num[N];
	    for(int i=0;i<N;i++) cin>>cost[i]>>num[i];
	    ll S=possible(num,cost,N-1,K,0);
	    cout<<S<<endl;
        }
    return 0;
}