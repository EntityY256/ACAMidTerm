#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int diff(int P,int Q){
	return (P>Q?P-Q:Q-P);
}
int main() {
	int P,Q,R,N,K;
	ll Sum=0;
	cin>>N>>R;
	vector <int> A;
	ll B[N];
	for(int i=0;i<N;i++){
		cin>>K;
		Sum= (ll) Sum+K;
		A.push_back(K);
	}
	B[0]=Sum;
	for(int i=0;i<N-1;i++){
		
		if(i==0) make_heap(A.begin(),A.end()) ;
		else push_heap(A.begin(),A.end()) ;
		P=A[0];
		Q=A[N-1-i];
		A.erase(A.begin(),A.begin()+1);
		A.pop_back();
		Sum= (ll) Sum-P;
		Sum= (ll) Sum-Q;
		Sum= (ll) Sum+diff(P,Q);
		A.push_back(diff(P,Q));
		B[i+1]=Sum;		
	}
	for(int i=0;i<R;i++){
		cin>>K;
		cout<<B[K]<<" ";
	}
    return 0;
}