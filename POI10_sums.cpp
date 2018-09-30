/*

*/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
int n;
int a[5005];
int mn;

void dijkstra(int s, vector<int>&d){
	d.assign(mn, INF);

	d[s] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
	q.push({0, s});

	while(!q.empty()){
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if(d_v != d[v])
			continue;

		for(int i = 0; i < n; ++i){
			int to = (v + a[i]) % mn;
			int len = a[i];
			if(d[v] + len < d[to]){
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}


	}
}

int main(){
	int i, j, b, q;
	cin >> n;
	mn = 100000000;
	for(i = 0; i < n; ++i){
		cin >> a[i];
		mn = min(mn, a[i]);
	}

	vector<int>d(n);

	dijkstra(0, d);

	cin >> q;
	while(q--){
		cin >> b;
		if(b >= d[b % mn])cout << "TAK" << endl;
		else cout << "NIE" << endl;
	}

	return 0;
}
