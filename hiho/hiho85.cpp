#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define llt long long int 

//vector<int> g[1000];
//vector<bool> vis(1000, 0);
//vector<int> d(1000, 0);
//queue<int> ls;
//int N;
//llt mincost= 500001;

vector<string> m;
int vis[1000][1000];

//void dfs(int i,llt &cost) {
//	if (i == N - 1) {
//		mincost = min(mincost, cost);
//		return;
//	}
//	if (cost > mincost) return;  //ºÙ÷¶
//	int len = g[i].size();
//	for (int j = 0; j < len; j++) {
//		if (!vis[g[i][j]]) {
//			vis[g[i][j]] = 1;
//			cost++;
//			dfs(g[i][j], cost);
//			cost--;
//			vis[g[i][j]] = 0;
//		}
//	}
//}
//
//
//void bfs(int i) {
//	ls.push(i);
//	d[i] = 0;
//	while (!ls.empty()) {
//		int tmp = ls.front();
//		vis[tmp] = 1;
//		ls.pop();
//		int len = g[tmp].size();
//		for (int j = 0; j < len; j++) {
//			if (!vis[g[tmp][j]]) {
//				ls.push(g[tmp][j]);
//				if (d[g[tmp][j]] == 0)  d[g[tmp][j]] = d[tmp] + 1;
//				else  d[g[tmp][j]] = min(d[g[tmp][j]], d[tmp] + 1);
//			}
//		}
//	}
//	if (d[N - 1] == 0) printf("-1\n");
//	else printf("%d\n", d[N - 1]);
//}

//vector<string> ele;
//
//string getVec(string a, int &i) {
//	int pair = 1;
//	i++;
//	string tmp = "[";
//	while (pair) {
//		tmp += a[i];
//		if (a[i] == ']') pair--;
//		else if (a[i] == '[') pair++;
//		i++;
//	}
//
//	return tmp;
//}
//
//string getNumele(string a, int &i) {
//	string tmp = "";
//	while ((a[i] != ',')&&(a[i]!=']')) {
//		tmp += a[i];
//		i++;
//	}
//	return tmp;
//}
//int getNum(string a, int &i) {
//	int tmp = 0;
//	i++;
//	while (a[i] != ']') {
//		tmp *= 10;
//		tmp += a[i]-'0';
//		i++;
//	}
//	return tmp;
//}

int main() {
	//1
	//int M, W, a, b, l;
	//cin >> N >> M >> W;
	//for (int i = 0; i < M; i++) {
	//	cin >> a >> b >> l;
	//	if(l>=W) {
	//		g[a - 1].push_back(b - 1);
	//		g[b - 1].push_back(a - 1);
	//	}
	//}
	//llt cost = 0;
	//vis[0] = 1;
	////dfs(0, cost);
	////printf("%lld\n", (mincost == 500001) ? -1 : mincost);
	//bfs(0);

	int N, ans = 0;
	string a;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		m.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] == 'B') {
				ans = max(ans,dfs(i, j));
			}
		}
	}

	//3
	/*string a;
	cin >> a;
	int i = 1, len = a.length();
	bool com = 0;
	while (i < len) {
		if (a[i] == '['&&!com) {
			string tmp = getVec(a,i);
			ele.push_back(tmp);
		}
		else if (a[i] == ']' && !com) i++,com = 1;
		else if (a[i] >= '0'&&a[i] <= '9') {
			string tmp = getNumele(a, i);
			ele.push_back(tmp);
		}
		else if (a[i] == '['&& com) {
			int pos = getNum(a, i);
			if (pos > ele.size() || pos < 0) cout << "ERROR" << endl;
			else cout << ele[pos] << endl;
			break;
		}
		else i++;
	}*/

	return 0;
}