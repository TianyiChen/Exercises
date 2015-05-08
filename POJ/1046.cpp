#include <iostream>
using namespace std;

int main(){
double tgc[16][3];int temp;
double min;int mini;double distance;
for(temp=0;temp<16;temp++)cin>>tgc[temp][0]>>tgc[temp][1]>>tgc[temp][2];
double r,g,b;
while(cin>>r>>g>>b)
{if(r==-1)return 0;
min=66666;mini=16;
for (temp=0;temp<16;temp++){
distance=(r-tgc[temp][0])*(r-tgc[temp][0])+(g-tgc[temp][1])*(g-tgc[temp][1])+(b-tgc[temp][2])*(b-tgc[temp][2]);
if(distance<min){min=distance;mini=temp;}}
printf("(%d,%d,%d) maps to (%d,%d,%d)\n",(int)r,(int)g,(int)b,(int)tgc[mini][0],(int)tgc[mini][1],(int)tgc[mini][2]);
}
}
