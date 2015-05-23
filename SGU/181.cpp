#include<bits/stdc++.h>
using namespace std;
long long x[10005],A,alpha,beta,gamma,M,k,T,t,_;
int main(){
	cin>>A>>alpha>>beta>>gamma>>M>>k;
	if (k<10000){//brute force
		while (k--)A=(alpha*A*A+beta*A+gamma)%M;
		printf("%d",A);
	}
	else{
		x[0]=A;
		for (t=1;;++t)
		{
			x[t]=(alpha*x[t-1]*x[t-1]+beta*x[t-1]+gamma)%M;
			for (_=0;_<t;++_)if (x[t]==x[_]){
				T=t-_;goto out;
			}
		}
	out:printf("%d",x[_+(k-t)%T]);
	}
}