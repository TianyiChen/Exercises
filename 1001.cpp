#include <iostream>
using namespace std;
int main()
{
	char R[6]; int n;
	int a[300] = { 0 }, b[300] = { 0 }, r[300] = { 0 };
	//[0....99].[100...299]
	while (cin >> R >> n){
		int aleft, aright, bleft = 0, bright = 299;
		aleft = 0, aright = 299;
		for (int xx = 1; xx < 300; xx++) a[xx] = 0;
		for (int tempvar = 0; tempvar < 6; ++tempvar) if (R[tempvar] != '.') R[tempvar] -= 48;
		int tmpvar = 0; while (R[tmpvar] != '.')tmpvar++;
		int tv = --tmpvar, loc = 99;
		while (tv >= 0) a[loc--] = R[tv--]; loc = 100; tv = tmpvar + 2;
		while (tv < 6) a[loc++] = R[tv++];
		for (int xx = 1; xx < 300; xx++) b[xx] = a[xx];
		for (int temp = 1; temp < n; temp++){
			aleft = 0, aright = 299; bleft = 0, bright = 299;
			while (a[aleft] == 0) aleft++; while (b[bleft] == 0) bleft++;
			while (a[aright] == 0) aright--; while (b[bright] == 0) bright--;
			for (int ttt = aright; ttt >= aleft; ttt--)
				for (int tt = bright; tt >= bleft; tt--)
					r[tt + ttt - 99] += a[ttt] * b[tt];
			for (int tmp = 299; tmp >= 0; tmp--)
				while (r[tmp]>9) { r[tmp] -= 10; r[tmp - 1]++; }
			for (int xx = 1; xx < 300; xx++){ a[xx] = r[xx]; r[xx] = 0; }
		}aleft = 0, aright = 299; while (a[aleft] == 0) aleft++; while (a[aright] == 0) aright--;
		if (aleft > 99){
			printf("."); for (int temp = 100; temp <= aright; temp++)printf("%d", a[temp]);
		}
		else{
			for (int temp = aleft; temp <= (aright<100?99:aright); temp++)
			{
				printf("%d", a[temp]); if (temp == 99&&aright>99) printf(".");
			}
		}printf("\n");
	}
	return 0;
}
