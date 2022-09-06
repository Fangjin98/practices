#include<iostream>
using namespace std;
double a[6]={ 45,345,1245,7745,13745,22495 };
int main(){
	double T,i;
	cin>>T;
	int j=T/100;
	while(1){
		i=j*100;
		if(i<=3500) i=i;
		else if(i<=5000) i=(i-3500)*0.03;
		else if(i<=8000) i=a[0]+(i-5000)*0.1;
		else if(i<=12500)i=a[1]+(i-8000)*0.2;
		else if(i<=38500)i=(a[2]+(i-12500)*0.25);
		else if(i<=58500)i=(a[3]+(i-38500)*0.3);
		else if(i<=83500)i=(a[4]+(i-58500)*0.35);
		else i= a[5]+(i-83500)*0.45;	
		if(j*100-i==T) break;
		j++;
	}
	printf("%d",j*100);
	return 0;
}
