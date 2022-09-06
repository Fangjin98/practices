#include<iostream>
#include<string>
#include<vector>
using namespace std;

string r[100];
string v[100]; 
bool match(string &a,string &b,bool flag){
	int len1=a.size();
	int len2=b.size();
	int p1=0,p2=0;
	while(a[p1]&&b[p2]){
		if(a[p1]==b[p2]){
			p1++;
			p2++;
		}
		else{
			if(b[p2++]=='<'){
				if(b[p2]=='i'){
					bool flag1=0;
					while(a[p1]&&isdigit(a[p1])){
						if(a[p1]!='0') flag1=1;
						if(flag&&flag1) cout<<a[p1];
						p1++;
					}
					if(flag) cout<<' ';
					if(!flag1) return false;
					p2+=4;
				}
				else if(b[p2]=='s'){
					bool flag1=0; 
					while(a[p1]&&a[p1]!='/'){
						flag1=1;
						if(flag) cout<<a[p1];
						p1++;
					}
					if(flag) cout<<' ';
					if(!flag1) return false;
					p2+=4;
				}
				else if(b[p2]=='p'){
					if(flag){
						while(a[p1]) {
							cout<<a[p1];
							p1++;
						}
					}
					return true;
				}
			}
			else return false;
		}
	}
	//if(flag) cout<<endl;
	return (p1>=len1)&&(p2>=len2);
}
int main(){
	int n,m;
	string a,b;
	cin>>n>>m;
	for(int i=0;i<n;i++)  cin>>r[i]>>v[i];
	for(int i=0;i<m;i++){
		cin>>a;
		bool flag=true;
		for(int j=0;flag&&j<n;j++){
			if(match(a,r[j],false)){
				flag=false;
				cout<<v[i]<<' ';
				match(a,r[j],true);
				cout<<endl;
			}
		} 
		if(flag) printf("404\n");
	}
	
	return 0;
} 
