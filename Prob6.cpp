#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int M,N;
	cin>>N>>M;
	//M-1 rows and N-1 cols : (M-1)+i(N-1) in steps (1+i), (i-1), (-1-i), (-i+1), 1, -1, i, -i
	int P= (M>N)?M:N;
	if(P%2==0) cout<<2*P-3;
	else cout<<2*P-2;
    return 0;
}