#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct node{
	int id;
	int t;
	int jh;
	node(int a,int b,int c){
		id=a,t=b,jh=c;
	}
	bool operator < (const node& a)const{
		return (t<a.t)||((t==a.t)&&(jh<a.jh))||((t==a.t)&&(jh==a.jh)&&(id<a.id));
	}
};
int N,K;
int a[10001];
vector<node> list;

int main(){
	int w,s,k;
	cin>>N>>K;
	for(int i=1;i<=N;i++) a[i]=i;
	for(int i=0;i<K;i++){
		cin>>w>>s>>k;
		list.push_back(node(w,s,1));
		list.push_back(node(w,s+k,0));
	}
	sort(list.begin(),list.end());
	K=2*K;
	for(int i=0;i<K;i++){
		if(list[i].jh==0){
			for(int j=1;j<=N;j++) {
				if(a[j]==0) {
					a[j]=list[i].id;
					break;
				}
			}
		}
		else if(list[i].jh==1){
			for(int j=1;j<=N;j++) {
				if(a[j]==list[i].id) {
					a[j]=0;
					break;
				}
			}
		}
	}
	for(int i=1;i<=N;i++) printf("%d ",a[i]);
	
	return 0;
} 
