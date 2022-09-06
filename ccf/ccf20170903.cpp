#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node{
	int level;
	string name;
	string str;
	node(int l,string a,string b){
		level=l,name=a,str=b;
	}
};


vector<node> l;
string a="";

void solve(){
	int count=0;
	int len=a.size();
	int pos=0;
	while(pos<len){
		if(a[pos]=='{') {
			count++;
			pos++;
			while(a[pos]==' ')	pos++;
		}
		else if(a[pos]=='}'){
			count--;
			pos++;
			while ((pos<len)&&a[pos] == ' ')	pos++;
		}
		else if(a[pos]=='"'){
			int pf=pos+1;
			string nametmp="";
			while(1) {
				if (a[pf] == '"') break;
				if(a[pf]=='\\') {
					pf++;
					nametmp+=a[pf];
				}
				else nametmp+=a[pf];
				pf++;
			}
			while (a[pf] != ':') pf++;
			pf++;
			while (a[pf] == ' ')pf++;
			pos=pf;
			if (a[pos] == '{') {
				l.push_back(node(count, nametmp, ""));
				continue;
			}
			pos++;
			while (a[pos] == ' ') pos++;
			string strtmp="";
			pf = pos;
			while(1) {
				if (a[pf] == '"' ) break;
				if(a[pf]=='\\') {
					pf++;
					strtmp+=a[pf];
				}
				else strtmp+=a[pf];
				pf++;
			}
			pos=pf+1;
			l.push_back(node(count,nametmp,strtmp));
		}
		else  pos++;
	}
} 
int main(){
	int n,m;
	string tmp;
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++){
		getline(cin, tmp);
		a+=tmp;
	} 
	solve();
	int s=l.size();
	for(int i=0;i<m;i++){
		cin>>tmp;
		vector<string> need;
		int len=tmp.length();
		int count=0;
		string tmp1 = "";
		for(int j=0;j<len;j++){
			if (tmp[j] == '.') {
				count++;
				need.push_back(tmp1);
				tmp1 = "";
			}
			else tmp1 += tmp[j];
		}
		need.push_back(tmp1);
		bool flag=0;
		if(count==0) {
			for (int j = 0; (j < s) && (!flag); j++) {
				if(l[j].name==tmp) {
					flag=1;
					if(l[j].str!="")  cout << "STRING " << l[j].str << endl;
					else cout<<"OBJECT"<<endl;
				}
			}
			if(!flag) cout<<"NOTEXIST"<<endl;
		} 
		else{
			int j = 0, k = 0;
			while (j < s && !flag) {
				if (k == count+1) {
					flag = 1;
					if (l[j].str != "")  cout << "STRING " << l[j].str << endl;
					else cout << "OBJECT" << endl;
					break;
				}
				if (l[j].name == need[k]) {
					if (k!=count&&l[j].str != "") break;
					k++;
				}
				else j++;
			}
			if (!flag) cout << "NOTEXIST" << endl;
		}
	}
	
	return 0;
} 
