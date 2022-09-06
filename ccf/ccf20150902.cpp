#include<iostream>
using namespace std;

int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int y,d;
	cin>>y>>d;
	if((y%400==0)||((y%4==0)&&(y%100!=0))) a[1]++;
	int i=0;
	while(d>a[i]) {
		d-=a[i];
		i++;
	}
	printf("%d\n%d",i+1,d);
	return 0;
}
