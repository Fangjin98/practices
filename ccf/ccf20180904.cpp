#include<iostream>
#include<vector>
using namespace std;

int n;
int f[301];
int s[301];

void dfs(int l){
	int tmp;
	int i=1;
	if(l==n-1) {
		while(1){
			f[l]=i;
			tmp=(f[l]+f[l-1]+f[l-2])/3;
			int tmp2=(f[l]+f[l-1])/2;
			if(tmp>s[l-1]||tmp2>s[l]) return;
			if(tmp==s[l-1]&&tmp2==s[l]) {
				for(int i=0;i<n;i++) cout<<f[i]<<' ';
				cout<<endl;
				exit(0);
			}
			i++;
		}
	}
	while(1){
		f[l]=i;
		if(l==1) tmp=(f[l]+f[l-1])/2;
		else tmp=(f[l]+f[l-1]+f[l-2])/3;
		if(tmp>s[l-1]) return;
		if(tmp==s[l-1])	dfs(l+1);
		i++;
	}
} 
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>s[i];
	int i=1;
	while(1) {
		f[0]=i;
		dfs(1);
		i++;
	}
	return 0;
}
