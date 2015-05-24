#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define LEN_LIMIT 60
#define EXL(_) if(_.toString().length()>LEN_LIMIT)break;
using namespace std;
#include<biginteger>
BigNumber up[150],down[150];
int main(){
	up[0]=BigNumber("1");puts("1");
	for (int i=0;;){
		//the right most index
		for (int j=i;~j;--j)cout<<(down[j]=up[j]+up[j+1]).toString()<<" ";
		for (int j=0;j<i;++j)cout<<down[j].toString()<<" ";
		cout<<down[i].toString()<<'\n';
		EXL(down[0])
			++i;
		for (int j=i;j;--j)cout<<(up[j]=down[j]+down[j-1]).toString()<<" ";
		cout<<(up[0]=down[0]*2).toString()<<' ';
		for (int j=1;j<i;++j)cout<<up[j].toString()<<" ";
		cout<<up[i].toString()<<'\n';
		EXL(up[0])
	}
}