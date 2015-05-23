#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
using namespace std;
int n,a,b,z=0,o=0,t=0,rc;
pair<int,int>w[3];//delta,from
char pw[201];
void rp(char source,char dst,int n){
	int pos=0;
	while (n--){ while (pw[pos]!=source)++pos;pw[pos++]=dst; }
}
int main(){
	cin>>n>>a>>b;scanf("%s",pw);
	if (a+b>n){puts("-1");return 0;}
	for (int _=0;_<n;++_)switch (_[pw]){ case '0':++z;break;case '1':++o;break;case '2':++t;}
	w[0]=mp(a-z,0);w[1]=mp(b-o,1);w[2]=mp((n-a-b)-t,2);
	sort(w,w+3);printf("%d\n",rc=max(abs(w[0].first),abs(w[2].first)));
	//for (int _=0;_<3;++_)cout<<w[_].first<<"  "<<w[_].second<<endl;
	int tmp=min(abs(w[0].first),abs(w[2].first));
	rp(w[0].second+'0',w[2].second+'0',tmp);
	w[0].first+=tmp;w[2].first-=tmp;
	if (w[1].first>0)rp(w[0].second+'0',w[1].second+'0',w[1].first);
	else if (w[1].first<0)rp(w[1].second+'0',w[2].second+'0',w[2].first);
	printf("%s",pw);
}