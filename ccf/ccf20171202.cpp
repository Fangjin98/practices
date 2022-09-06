#include<iostream>
using namespace std;
int a[1001]={0};
int main(){
	int n,k;
	cin>>n>>k;
	int left=n;
	int i=0,pos=1;
	while(1){
		if(!a[i]){
			if(left==1) {
				printf("%d\n",i+1);
				break;
			}
			if((pos%10==k)||(pos%k==0)){
				a[i]=1;
				left--;
			} 
			pos++;
		}
		i=(i+1)%n;
	}
	return 0;
} 
