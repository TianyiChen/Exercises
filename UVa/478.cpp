#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
inline double sign(double a,double s,double d,double f,double g,double h){
	return (a-g)*(f-h)-(d-g)*(s-h);
}
bool PointInTriangle(double a,double s,double d,double f,double g,double h,double j,double k)
{
	bool temp;
	return sign(a,s,d,f,g,h)<0==(temp=sign(a,s,g,h,j,k)<0)&&temp==sign(a,s,j,k,d,f)<0;
}
struct figure{
	char ty;
	double ccx,ccy,r,ulx,uly,lrx,lry,q,w,e,fuck,t,u;
	bool isin(double const& x,double const& y){
		if (ty=='c')return (x-ccx)*(x-ccx)+(y-ccy)*(y-ccy)<r;
		else if (ty=='r')return x>ulx&&y<uly&&x<lrx&&y>lry;
		else return PointInTriangle(x,y,q,w,e,fuck,t,u);
	}
}f[10];
int main(){
	char i;int _=0,p=0;double px,py;bool I;
	while (i=getchar()){
		if (i=='\n')continue;
		if (i=='*')break;
		if ((_[f].ty=i)=='c')scanf("%lf%lf%lf",&_[f].ccx,&_[f].ccy,&_[f].r);
		else if (i=='r')scanf("%lf%lf%lf%lf",&_[f].ulx,&_[f].uly,&_[f].lrx,&_[f].lry);
		else scanf("%lf%lf%lf%lf%lf%lf",&_[f].q,&_[f].w,&_[f].e,&_[f].fuck,&_[f].t,&_[f].u);
		_[f].r*=_[f].r;_++;
	}
	while (scanf("%lf%lf",&px,&py)&&++p&&!(I=0)){
		if (px==9999.9&&py==9999.9)return 0;
		for (int __=0;__<_;__++)if (__[f].isin(px,py))
			I=1,printf("Point %d is contained in figure %d\n",p,__+1);
		if (!I)printf("Point %d is not contained in any figure\n",p);
	}
}
