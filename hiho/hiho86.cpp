#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

map<string, vector<int>> b;

int main() {
	int N;
	string a,num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		num = "";
		int len1 = a.length();
		int len = len1;
		len--;
		while (a[len] >= '0'&&a[len] <= '9') len--;
		a = a.substr(0, len);
		num = a.substr(len, len1 - len);
		if (num == "") {
			if (b[a].size() == 0) cout << a << endl;
		}
	}
	return 0;
}