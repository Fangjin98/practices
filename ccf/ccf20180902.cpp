#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int s,e;
	node(int a,int b){
		s=a,e=b;
	}
	bool operator < (const node& a)const{
		return s<a.s;
	}
};

vector<node> H;
vector<node> W;

int main(){
	int n,a,b,c,d;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		H.push_back(node(a,b));
	}
	sort(H.begin(),H.end());
	
	for(int i=0;i<n;i++){
		cin>>c>>d;
		W.push_back(node(c,d));
	}
	sort(W.begin(),W.end());
	
	int i=0,j=0;
	long long int count=0;
	
	
	while(i<n&&j<n){
		if(H[i].s>=W[j].e){
			j++;
			continue;
		}
		if(W[j].s>=H[i].e){
			i++;
			continue;
		}
		
		count+=(min(H[i].e,W[j].e)-max(H[i].s,W[j].s));
		
		if(H[i].e>W[j].e)  j++;
		else i++;
	}
	
	cout<<count<<endl;
	
	
	return 0;
}
