//The solution can also be found at http://hihocoder.com/contest/msbop2015qual/solution/358691
#include <iostream>
#include<algorithm>
#include<cmath>
typedef long long LL;
#define LLB 0x6fffFFFFffffFFFF
using namespace std;
#define debug 0
LL __, n, m, A, B, bx, by;
class quadratic{
	//f(x)=a*x^2+b*x+c
public:LL a, b, c, lp, db, dc, limit;
	   void noexc(){ if (lp < 1)lp = 1; else if (lp >limit)lp = limit; }
	   void setlp(){ lp = -b / (2 * a); noexc(); }
	   LL calcvalue(LL j){
		   return  a*lp*lp + b * lp + c + abs(lp - j);
	   }
};
int main(){
	quadratic x, y;
	LL  r, t, ax, ay;
	cin >> __;
	for (int _ = 1; _ <= __; _++){
		r = LLB; x.b = x.c = y.b = y.c = 0;
		scanf("%lld%lld%lld%lld", &n, &m, &A, &B); x.a = y.a = A; x.limit = n; y.limit = m;
		while(A--){
			scanf("%lld%lld", &ax, &ay);
			x.b -= 2 * ax; x.c += ax*ax; y.b -= 2 * ay; y.c += ay*ay;
		}
		while(B--){
	        scanf("%lld%lld", &bx, &by);
			int testa = 20,testb=20; t = LLB;
			x.setlp();x.lp -= 10; x.noexc();
				while (testa--&&x.lp++){
					testb = 20; y.setlp();y.lp -=10; y.noexc();
					if (x.lp > x.limit)break;
					while (testb--&&y.lp++){
						if (y.lp > y.limit)break;
						t = min(x.calcvalue(bx) + y.calcvalue(by), t);}
				}
			if (t < r)r = t;//low cost
		}
		printf("Case #%d: %lld\n", _, r);
	}
	return 0;
}
