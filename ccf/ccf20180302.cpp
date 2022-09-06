#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int id;
	int pos;
	int dir;
	node(int a=-1,int b=0,int c=0){
		id=a,pos=b,dir=c;
	}
};


bool cmp1(node a,node b){
	return a.pos<b.pos;
}

bool cmp2(node a,node b){
	return a.id<b.id;
}

node a[100];

int main(){
	int n,L,t,tmp;
	cin>>n>>L>>t;
	for(int i=0;i<n;i++){
		cin>>tmp;
		a[i]=node(i,tmp,1);
	}
	sort(a,a+n,cmp1);
	for(int i=1;i<=t;i++){
		for(int j=0;j<n;j++){
			a[j].pos+=a[j].dir;
			if(a[j].pos<=0){
				a[j].pos=0;
				a[j].dir=-a[j].dir;
			}
			if(a[j].pos>=L) {
				a[j].pos=L;
				a[j].dir=-a[j].dir;
			}
		}
		for(int j=0;j<n-1;j++){
			if(a[j].pos>a[j+1].pos) {
				a[j].pos-=a[j].dir;
				a[j+1].pos-=a[j+1].dir;
				a[j].dir=-a[j].dir;
				a[j+1].dir=-a[j+1].dir;
			}
			else if(a[j].pos==a[j+1].pos){
				a[j].dir=-a[j].dir;
				a[j+1].dir=-a[j+1].dir;
			}
		}
	}
	sort(a,a+n,cmp2);
	for(int i=0;i<n;i++) cout<<a[i].pos<<' ';
	
	
	return 0;
} 
