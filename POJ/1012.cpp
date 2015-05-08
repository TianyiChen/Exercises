#include <iostream>
using namespace std;
int main(){
	int k, r[] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };
	while (cin >> k) k ? printf("%d\n", r[k]) : exit(0);
}

/*
The following program can be used to calculate the table

#include <iostream>
using namespace std;
int main(){
int k,remain,st,t,m;
bool guy[27],*s=&guy[1],*good,*e,*p;
for (k = 2; k < 14;k++){
good = &guy[k]; e = &guy[2 * k];
m = k;
while (++m){
st = m % (2 * k); if (!st)st = 2 * k;
if (st <= k)continue;
for (short temp = 0; temp < 27; temp++) guy[temp] = true;
p = &guy[st];
*p = false; remain = 2 * k - 1;
while (remain > k){
t = m%remain; if (!t)t=remain;
//move p to next live guy
while (t--){
if (p < e)p++; else p = s;
while (*p == false)if (p < e)p++; else p = s;
}
if (p <= good) goto nextm;
*p = false; remain--;
}
//ok,remain=k && no good guy was killed
goto nextk;
nextm:;
}
nextk:cout <<k<<" "<<m<<endl;
}
}
*/
