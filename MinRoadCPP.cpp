
#include <bits/stdc++.h>
typedef long long ll; 
using namespace std;
void Group(vector <vector <int>> &Adjacent, vector <int> &Visited, vector <vector <int>> &Solulu, int Curr, int Start, vector<int> &group){
	if(Visited[Curr]==1) return;
	if(Curr==Start) group={};
	Visited[Curr]=1;
	group.push_back(Curr);
	for(auto i : Adjacent[Curr]) Group(Adjacent,Visited,Solulu,i,Start, group);
    if(Curr==Start) Solulu.push_back(group);
    return ;
	
}
void walk(vector <vector <int>> &Adjacent, vector <int> &Visited, vector <vector <int>> &Solulu){
	int N= Visited.size();
	for(int i=0;i<N;i++){
		if(Visited[i]==1) continue;
		else{
			vector <int> group;
			Group(Adjacent,Visited,Solulu,i,i,group);
		}
	}
}
 
int main() {
 int N,M,A,B;
 cin>>N>>M;
 vector <int> Visited(N,0);
 vector <vector <int>> Adjacent(N);
 for (int i = 0; i < M; i++) {
        cin>>A>>B;
        Adjacent[A-1].push_back(B-1);
        Adjacent[B-1].push_back(A-1);
 }
 vector <vector <int>> Solulu;
 walk(Adjacent,Visited,Solulu);
 int V = Solulu.size();
 cout<< V-1<<endl;
 for(int i=0;i<V-1;i++) cout<< Solulu[i][0]+1<<" "<<Solulu[i+1][0]+1<<endl; 
 return 0;
}
