#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
//1
//int s[100001];


//2
//int N, c = 0;
//int A[100001];
//vector<int> P[100001];
//void dfs(int i, int mx=0,int mi=1000000000) {
//	if (i != 1) {
//		c = max(c, max(abs(A[i] - mx), abs(A[i] - mi)));
//	}
//	mx = max(mx, A[i]);
//	mi = min(mi, A[i]);
//	for (int j = 0; j < P[i].size(); j++)
//		dfs(P[i][j], mx, mi);
//}


int main() {
	//1
	/*int N, M, dis, x, y;
	cin >> N >> M;
	s[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> dis;
		s[i] = s[i - 1] + dis;
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		cout << min(s[N] - abs(s[x-1] - s[y-1]), abs(s[x-1] - s[y-1])) << endl;
	}*/


	//2
	/*int tmp;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 2; i <= N; i++) {
		cin >> tmp;
		P[tmp].push_back(i);
	}
	dfs(1);
	cout << c << endl;*/
	return 0;
}
