#include <iostream>
using namespace std;

int main()
{
	int p,e,i,d,c,cas=1;
	while (cin >> p >> e >> i >> d)
	{
		if (e == -1) return 0; c = (d == 0) ? 1 : d;
		while (c > p) p += 23;	while (c > e)e += 28;  while (c > i) i += 33;
		for (;; c++){
			if (c > p) p += 23;	if (c > e)e += 28;  if (c > i) i += 33;
			if (c == p&&c == e&&c == i){
				if (c - d > 21252)c -= 21252;
				printf("Case %d: the next triple peak occurs in %d days.\n", cas++,c-d);
				goto le;
			}
		}
	le:;
	}
	return 0;
}
