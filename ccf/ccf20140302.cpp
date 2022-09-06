#include<iostream>
#include<vector>
using namespace std;
int a[2560][1440]={0};
struct node{
	int id,x1,x2,y1,y2;
	bool top;
	node(int k,int a,int b,int c,int d,bool t=0){
		id=k,x1=a,x2=b,y1=c,y2=d,top=t;
	}
};
vector<node> sh;
int tt=0;
int main(){
	int n,m,x1,x2,y1,y2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x1>>y1>>x2>>y2;
		sh.push_back(node(i,x1,x2,y1,y2));
		for(int j=x1;j<=x2;j++){
			for(int k=y1;k<=y2;k++){
				a[j][k]=i;
			}
		}
	}
	tt=n-1;
	for(int i=0;i<m;i++){
		cin>>x1>>y1;
		if(a[x1][y1]==0) printf("IGNORED\n");
		else {
			printf("%d\n",a[x1][y1]);
			if(!sh[a[x1][y1]-1].top){
				node tmp=sh[a[x1][y1]-1];
				sh[a[x1][y1]-1].top=1;
				sh[tt].top=0;
				tt=a[x1][y1]-1;
				for(int j=tmp.x1;j<=tmp.x2;j++){
					for(int k=tmp.y1;k<=tmp.y2;k++){
						a[j][k]=tmp.id;
					}
				}
			}
		}
	}
	
	return 0;
}

