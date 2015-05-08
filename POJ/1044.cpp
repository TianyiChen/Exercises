#include <iostream>
using namespace std;
int n, ci = 0;
int y[20] = { -1 }, a[20] = { -1 }, b[20] = { -1 }, ad[20];
int mi;			int op;
bool ats(){
	for (short tmp = 1; tmp < n; tmp++)
	{
		if (y[0] != y[tmp]) return false;
	}return true;
}
int main(){
	while (cin >> n){
		if (!n)return 0;
		printf("Case #%d:\n", ++ci);
		for (short tmp = 0; tmp < n; tmp++)
		{
			cin >> y[tmp] >> a[tmp] >> b[tmp];
			ad[tmp] = b[tmp] - a[tmp];
		}
		if (n == 1||ats())	{
			printf("The actual year is %d.\n\n", y[0]);
			goto nxcase;
		}
		op = 0;
		while (op<10000){
			op = 10001;
			for (short ti = 0; ti < n; ti++)
				if (y[ti] < op){ op = y[ti]; mi = ti; }
			if ((y[mi] += ad[mi]) >= 10000){ printf("Unknown bugs detected.\n\n"); goto nxcase; }
			if (!ats())goto nx;
			printf("The actual year is %d.\n\n", y[0]); goto nxcase;
		nx:;
		}
		printf("Unknown bugs detected.\n\n");
	nxcase:;
	}
}
