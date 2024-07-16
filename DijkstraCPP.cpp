#include <bits/stdc++.h>
typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<ll, int> Pair;
void Dijkstra(vector<vector<Pair>> &Adjacent, vector<ll> &MinDist, int V) {
    MinDist[V] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> P;
    P.push(make_pair(0, V)); 

    vector<bool> processed(MinDist.size(), false);

    while (!P.empty()) {
        int Temp1 = P.top().second;
        ll currentDist = P.top().first;
        P.pop();

        if (processed[Temp1]) continue;
        processed[Temp1] = true;

        for (auto &i : Adjacent[Temp1]) {
            int Temp2 = i.second;
            ll Dist = i.first;
            if (MinDist[Temp2] > currentDist + Dist) {
                MinDist[Temp2] = currentDist + Dist;
                P.push(make_pair(MinDist[Temp2], Temp2));
            }
        }
    }
}

int main() {
	int N,M;
	cin>>N>>M;
	vector <vector <int>> Map(M,{0,0,0});
	vector <vector <Pair>> Adjacent(N);
	for (int i = 0; i < M; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> Map[i][j];
        }
        Adjacent[Map[i][0] - 1].push_back(make_pair(Map[i][2], Map[i][1] - 1));
    }
	vector <ll> MinDist(N,INF);
	Dijkstra(Adjacent,MinDist,0);
	//Ok
	for(auto i: MinDist) cout<<i<<" ";
    return 0;
}