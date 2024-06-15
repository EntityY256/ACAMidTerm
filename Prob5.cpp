#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll max(ll P, ll Q){
	if(P>Q) return P;
	else return Q;
}
int Sum(string S){
	int p=0;
	for(int i=0;i<S.length();i++){
		p+= (int) (S[i]-'0');
	}
	return p;
}
int main() {
	ll Answer=0;
	int A[11][51];
	for(int i=0;i<10;i++) for(int j=0;j<51;j++) A[i][j]=0;
	int N;
	cin>>N;
	while(N--){
	    string S;
	    cin>>S;
	    A[(S.length()-1)][Sum(S)]++;
        }
    for(int i=0;i<10;i++) for(int j=0;j<51;j++) Answer+= (ll) A[i][j]*A[10-i][50-j];
    cout<<Answer; 
    return 0;
}