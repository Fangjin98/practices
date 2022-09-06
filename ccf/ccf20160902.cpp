#include<iostream>
using namespace std;
int a[20][5]={0};
int main(){
	int n,p,count;
	bool done;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p;
		done=0;
		if(p==1) {
			for(int j=0;j<20;j++) {
				for(int k=0;k<5;k++){
					if(!a[j][k]) {
						a[j][k]=1;
						printf("%d\n",j*5+k+1);
						done=1;
						break;
					}
				}
				if(done) break;
			}
		}
		else if(p>=2){
			for(int j=0;j<20;j++) {
				int k;
				for(k=0;k<=5-p;k++){
					if(!a[j][k]) break;	
				} 
				count=0;
				while(count<p&&(k+count)<5){
					if(a[j][k+count]) break;
					count++;
				}
				if(count==p){
					for(int kk=0;kk<p;kk++){
						a[j][k+kk]=1;
						printf("%d ",(j*5+k+kk+1));
					}
					printf("\n");
					done=1;
					break;
				}
			}
			if(!done){
				count=0;
				for(int j=0;j<20;j++){
					for(int k=0;k<5;k++){
						if(!a[j][k]){
							count++;
							a[j][k]=1;
							printf("%d ",j*5+k+1);
						}
						if(count==p) break;
					}
					if(count==p) break; 
				} 
				printf("\n");
			}
		}
	}
	return 0;
} 
