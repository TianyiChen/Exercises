#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct figure{
	char ty;
	double ccx,ccy,r,ulx,uly,lrx,lry;
	bool isin(double const& x,double const& y){
		if (ty=='c')return (x-ccx)*(x-ccx)+(y-ccy)*(y-ccy)<r;
		else if(ty=='r')return x>ulx&&y<uly&&x<lrx&&y>lry;
		else
	}
}f[10];
int main(){
	char i;int _=0,p=0;double px,py;bool I;
	while (i=getchar()){
		if (i=='\n')continue;
		if (i=='*')break;
		if ((_[f].ty=i)=='c')scanf("%lf%lf%lf",&_[f].ccx,&_[f].ccy,&_[f].r);
		else if (i=='r') scanf("%lf%lf%lf%lf",&_[f].ulx,&_[f].uly,&_[f].lrx,&_[f].lry);
		else;
		_[f].r*=_[f].r;
		_++;
	}
	while (scanf("%lf%lf",&px,&py)&&++p&&!(I=0)){
		if (px==9999.9&&py==9999.9)return 0;
		for (int __=0;__<_;__++)if (__[f].isin(px,py))
			I=1,printf("Point %d is contained in figure %d\n",p,__+1);
		if (!I)printf("Point %d is not contained in any figure\n",p);
	}
}
