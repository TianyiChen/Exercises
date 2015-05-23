#include<bits/stdc++.h>
using namespace std;
long long N,ten[18];
int n[18],i,_;
int main(){
	cin>>N;ten[0]=1;
	for (int _=1;_<18;++_)ten[_]=10*ten[_-1];
	for (i=0;N;++i)n[i]=N%10,N/=10;//i invalid
	sort(n,n+i);
	do{
		N=0;
		for (_=0;_<i;_++)N+=ten[_]*n[_];
		if (!(N%17)){
			cout<<N<<endl;return 0;
		}
	} while (next_permutation(n,n+i));
	puts("-1");
}