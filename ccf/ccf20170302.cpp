#include<iostream>
using namespace std;
int stu[1001];
int main(){
	int n,m,p,q,pos,j;
	cin>>n>>m;
	for(int i=1;i<=n;i++) stu[i]=i;
	for(int i=0;i<m;i++){
		cin>>p>>q;
		for(pos=1;pos<=n;pos++){
			if(stu[pos]==p) break;
		}
		if(q>0){
			j=pos+1;
			while(j<=pos+q&&j<=n){
				stu[j-1]=stu[j];
				j++; 
			}
			stu[j-1]=p;
		}
		if(q<0){
			j=pos-1;
			while(j>=pos+q&&j>=1){
				stu[j+1]=stu[j];
				j--;
			}
			stu[j+1]=p;
		}
		//for(int k=1;k<=n;k++) printf("%d ",stu[k]);
	}
	for(int i=1;i<=n;i++) printf("%d ",stu[i]);
	
	return 0;
}
