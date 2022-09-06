#include<iostream>
#include<algorithm>
using namespace std;

int m[10]={0};
int a[15][10];
int b[4][4];


int main(){
	int sl;
	for(int i=0;i<15;i++){
		for(int j=0;j<10;j++){
			cin>>a[i][j];
			if(a[i][j]&&!m[j]) m[j]=i;
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>b[i][j];
		}
	}
	cin>>sl;
	int mh=20,bpos,lpos;
	for(int i=0;i<4;i++){
		if(mh>m[sl+i-1]&&m[sl+i-1]) mh=m[sl+i-1];
	}
	for(bpos=3;bpos>=0;bpos--){
		int i;
		for(i=0;i<4;i++){
			if(b[bpos][i]) break;
		}
		if(i!=4) break; 
	}
	for(lpos=0;lpos<4;lpos++){
		int i;
		for(i=0;i<4;i++){
			if(b[i][lpos])  break;
		}
		if(i!=4) break;
	}
	
	for(int i=bpos;i>=0;i--){
		for(int j=lpos;j<4;j++){
			if(b[i][j]) {
				a[mh+i][sl+j]=1;
			}
		}
	}
	printf("%d %d %d %d\n",sl,mh,bpos,lpos);
	for(int i=0;i<15;i++){
		for(int j=0;j<10;j++) 
			printf("%d ",a[i][j]);
		printf("\n");
	}
	
	return 0;
}
