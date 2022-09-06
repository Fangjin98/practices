#include<iostream>
using namespace std;
int n,m;
int a[31][31];
int p[31][31]={0};
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=m-3;j++){
			int count=0;
			while(1){
				if((j+count>=m)||(a[i][j+count]!=a[i][j+count+1])) break;
				count++;
			}
			count++;
			//cout<<i<<' '<<j<<' '<<count<<endl;
			//if(j+count==m) count--;
			if(count>=3){
				for(int k=0;k<count;k++){
					p[i][j+k]=a[i][j+k];
				}
			}
		}
	}
	for(int i=0;i<=n-3;i++){
		for(int j=0;j<m;j++){
			int count=0;
			while(1){
				if((i+count>=n)||(a[i+count][j]!=a[i+count+1][j])) break;
				count++;
			}
			count++;
			//cout<<i<<' '<<j<<' '<<count<<endl;
			//if(i+count==n) count--;
			if(count>=3){
				for(int k=0;k<count;k++){
					p[i+k][j]=a[i+k][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(p[i][j]) a[i][j]=0;
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 
