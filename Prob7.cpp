#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

 

int main() {
	int T,N,K;
	cin>>T;
	ll F[20];
	F[0]=1;
	for(int i=1;i<20;i++) F[i]=2*F[i-1];
	while(T--){
	      cin>>N>>K;
	      if(N<=K) cout<<F[N-1]<<endl;
	      else{
	      	int S=N-K;
	      	ll Matrix1[K][1];
	      	ll A[K][K];
	      	ll B[K][K];
	      	for (int i = 0; i < K; i++) {
               for (int j = 0; j < K; j++) {
                  if(i==0 || j+1==i) A[i][j]=1;
                  else A[i][j]=0;
                  }
            }
            // for (int i = 0; i < K; i++){
        // for (int j = 0; j < K; j++)
            // cout<< (*(*(A+i)+j))<<" ";
            // cout<<endl;
            // } 
            for (int j = 0; j < K; j++) {
                Matrix1[j][0]=F[K-1-j];
                  }
            for (int i = 0; i < K; i++) {
               for (int j = 0; j < K; j++) {
                B[i][j]=A[i][j];
                  }
            }
            // cout<<S<<endl;
            S--;
            while (S) {
              if (S & 1) {
            ll mul[K][K];
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            mul[i][j] = 0;
            for (int p = 0; p < K; p++)
                mul[i][j] +=(ll) (*(*(A+i)+p)) * (*(*(B+p)+j)) % 998244353;
        }
    }
    
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            (*(*(A+i)+j)) = mul[i][j]; // Updating our matrix
              }
              else{
            ll mul[K][K];
            for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            mul[i][j] = 0;
            for (int p = 0; p < K; p++)
                mul[i][j] +=(ll) (*(*(A+i)+p)) * (*(*(A+p)+j)) % 998244353;
        }
    }
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            (*(*(A+i)+j)) = mul[i][j]; // Updating our matrix
            }
            S= S>> 1;
    }
    ll possibility=0;
    // for (int i = 0; i < K; i++){
        // for (int j = 0; j < K; j++)
            // cout<< (*(*(A+i)+j))<<" ";
            // cout<<endl;
            // } 
    for (int p = 0; p < K; p++)
                possibility +=(ll) (*(*(A)+p)) * (*(*(Matrix1+p))) % 998244353;
    cout<<possibility % 998244353<<endl;    
             
	      }
        }
    return 0;
}