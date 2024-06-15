#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll max(ll P, ll Q){
	if(P>Q) return P;
	else return Q;
}
ll Fun(int P, int Q){
	ll R = (ll) P*(P+1)-Q*(Q+1);
	R/=2;
	return R;
}
int main() {
	ll T,N,K;
	cin>>T;
	while(T--){
	    cin>>N>>K;
	    ll A[N];
	    for(int i=0;i<N;i++) cin>>A[i];
	    sort(A,A+N,greater<ll>());
	    ll token=1;
	    bool pass=true;
	    // if(T==1) cout<<K<<endl;
	    int i;
	    for( i=1;i<N;i++){
	    	if(  A[i]<A[0]){	    		
	    		if(token*Fun(A[0],A[i])<K){
	    			K-=token*Fun(A[0],A[i]);
	    			A[0]=A[i];
	    		}
	    		else{
	    			while(K>0){
	    				if(K-(A[0]*token)<0) {pass=false;break;}
	    				
	    				K-=(A[0]*token);
	    				A[0]--;
	    				// if(T==1)cout<<K<<endl;
	    			}
	    		}
	    	}
	    	token++;
	    	if(K<=0 ) break;
	    }
	    if(i==N && pass){
	    		while((K-A[0]*N)>=0 && A[0]>0){
	    			K-=A[0]*N;
	    			A[0]--;
	    		}
	    	}
	    cout<<A[0]<<endl;
        }
    return 0;
}