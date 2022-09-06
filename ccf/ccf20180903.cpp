#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node{
	int level;
	int id;
	string name;
	string pp;
	node();
	node(int l,int i,string a,string b){
		level=l;
		id=i;
		name=a;
		pp=b;
	}
};


string strlower(string a){
	int len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]>='A'&&a[i]<='Z') a[i]=('a'+a[i]-'A');
	}
	return a;
}

vector<node> ele;
vector<int> ans;
vector<string> demand;

int main(){
	int n,m,level;
	string a,b,c;
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++){
		getline(cin,a);
		b="",c="";
		int j=0,len=a.length();
		while(1){
			if(a[j]!='.') break;
			j++;
		}
		level=j;
		while(j<len&&a[j]!=' ')	j++;
		b=a.substr(level,j-level);
		if(j!=len) j++;
		c=a.substr(j,len-j);
		//cout<<b<<c<<endl;
		ele.push_back(node(level/2,i,strlower(b),c));
	}
	//getchar();
	for(int i=0;i<m;i++){
		getline(cin,a);
		demand.clear();
		ans.clear(); 
		int len=a.length();
		int j,count=0,pos=0;
		for(j=0;j<len;j++) {
			if(a[j]==' ') {
				demand.push_back(a.substr(pos,j-pos));
				pos=j+1;
				count++;
			}
		}
		if(count==0){
			if(a[0]!='#'){
				a=strlower(a);
				for(j=0;j<n;j++){
					if(ele[j].name==a) ans.push_back(ele[j].id);
				}
			}
			else{
				for(j=0;j<n;j++){
					if(ele[j].pp==a) ans.push_back(ele[j].id);
				}
			} 
			len=ans.size();
			cout<<len<<' ';
			for(j=0;j<len;j++) cout<<ans[j]<<' ';
			cout<<endl; 
		}
		else{
			
		}
	}
	
	return 0;
}
