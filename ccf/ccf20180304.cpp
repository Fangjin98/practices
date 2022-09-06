#include<iostream>
#include<algorithm>
using namespace std;

int a[3][3];

//int vis[10][3][3]={0};
int maxa,maxb;
void dfs(int lj,int lk,int p,int count){
	int cc=0; 
	for(int j=0;j<3;j++){
		for(int k=0;k<3;k++){
			if(a[j][k]==0) cc++;
		}
	}
	if(cc==9) return;
	for(int i=0;i<3;i++){
		if((a[i][0]==a[i][1])&&(a[i][1]==a[i][2])&&a[i][0]){
			if(a[i][0]==1) 	maxa=max(maxa,cc);
			if(a[i][0]==2)	maxb=max(maxb,cc);
			//a[lj][lk]=0;
			return;
		}
		else if((a[0][i]==a[1][i])&&(a[1][i]==a[2][i])&&a[0][i])	{
			if(a[0][i]==1) maxa=max(maxa,cc);
			if(a[0][i]==2) maxb=max(maxb,cc);
			//a[lj][lk]=0;
			return;
		}
	}
	if((a[0][0]==a[1][1])&&(a[1][1]==a[2][2])&&a[0][0]){
		if(a[0][0]==1) maxa=max(maxa,cc);
		if(a[0][0]==2) maxb=max(maxb,cc);
		//a[lj][lk]=0;
		return;
	}
	if((a[2][0]==a[1][1])&&(a[1][1]==a[0][2])&&a[2][0]) {
		if(a[2][0]==1) maxa=max(maxa,cc);
		if(a[2][0]==2) maxb=max(maxb,cc);
		//a[lj][lk]=0;
		return;
	}
	
	a[lj][lk]=p;
	//vis[count][lj][lk]=1;
	//cout<<lj<<' '<<lk<<' '<<count<<' '<<p<<endl;
	for(int j=0;j<3;j++){
		for(int k=0;k<3;k++){
			if(!a[j][k]) {
				if(p==1) dfs(j,k,2,count+1);
				else dfs(j,k,1,count+1);
				a[j][k]=0;
			}
		}
	}
	
	a[lj][lk]=0;
}
int main(){
	int n,count;
	cin>>n;
	for(int i=0;i<n;i++){
		count=0,maxa=0,maxb=0;
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++) cin>>a[j][k];
		}
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++) {
				if(!a[j][k]){
					dfs(j,k,1,count);
				}
			}
		}
		if(maxa>maxb) cout<<maxa+1<<endl;
		else if(maxa<maxb) cout<<-(maxb+1)<<endl;
		else if(maxa==0&&maxb==0) cout<<0<<endl;
	}
	return 0;
} 
