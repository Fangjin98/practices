#include<iostream>
#include<algorithm>
using namespace std;
int a[100][100];
int main(){
	int n,x1,x2,y1,y2,max1=0,max2=0,count=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1;j<x2;j++){
			for(int k=y1;k<y2;k++) a[j][k]=1;
		}
		max1=max(x2,max1);
		max2=max(y2,max2);
	}
	for(int i=0;i<max1;i++){
		for(int j=0;j<max2;j++){
			count+=a[i][j];
		}
	}
	printf("%d",count);
	return 0;
} 
