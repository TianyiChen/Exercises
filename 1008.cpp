#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void output(int day,int month,int year){
	char opm[20][10]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac","ahau"};
	cout<<day<<" "<<opm[month]<<" "<<year<<endl;
}
int main(){
	char Haabmonths[20][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet" };
char inputm[6];int inputd;int inputy;double d;int total;
int opyear;int opmi;int opdi;int temp;
cin>>total;
cout<<total<<endl;
while(total){
	opmi=0;opdi=1;
scanf("%d. %s %d",&inputd,inputm,&inputy);
d=inputy*365;
for (temp=0;;temp++){if(strcmp(inputm,Haabmonths[temp])==0){d+=temp*20;break;}}
d+=inputd;
opyear=(int)floor(d/260);
d-=opyear*260;
while(d>0){
if(opmi<19)opmi++;else opmi=0;
if(opdi<13)opdi++;else opdi=1;
--d;}
output(opdi,opmi,opyear);
total--;

}
return 0;
}
