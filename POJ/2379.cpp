#include<iostream>
#include<algorithm>
using namespace std;
struct sm{
	int ci, pi, ti, ri;
};
struct team{
	bool pa[21]; int wa[21];//if a problem is accepted , wrong times
	int time, correct, tn;
};
bool cos_(sm const& a, sm const& b){
	return a.ti < b.ti;
}
bool compa(team const& a, team const& b){
	if (a.correct>b.correct)return 1; if (a.correct < b.correct)return 0;
	if (a.time<b.time)return 1; if (a.time>b.time)return 0;
	if (a.tn<b.tn)return 1; return 0;
}
int main(){
	int C, N;
	cin >> C >> N;
	team f[1001]; sm submit[1000];
	for (int t = 1000; t >= 0; t--){
		f[t].tn = t; f[t].time = f[t].correct = 0;
		memset(f[t].pa, 0, 21 * sizeof(bool));
		memset(f[t].wa, 0, 21 * sizeof(int));
	}
	for (int _ = 0; _ < N; _++)scanf("%d%d%d%d", &submit[_].ci, &submit[_].pi, &submit[_].ti, &submit[_].ri);
	sort(submit, submit + N, cos_);
	for (int _ = 0; _ < N; _++){
		if (submit[_].ri){
			if (!f[submit[_].ci].pa[submit[_].pi]){
				f[submit[_].ci].correct++; f[submit[_].ci].pa[submit[_].pi] = 1;
				f[submit[_].ci].time += submit[_].ti + 1200 * f[submit[_].ci].wa[submit[_].pi];
			}
		}
		else{
			if (!f[submit[_].ci].pa[submit[_].pi])f[submit[_].ci].wa[submit[_].pi]++;
		}
	}
	sort(f + 1, f + C + 1, compa);
	for (int t = 1; t<C + 1; t++)printf("%d ", f[t].tn);
	return 0;
}
