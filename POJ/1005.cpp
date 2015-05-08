#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int total; double x, y;
	cin >> total;
	for (int pro = 1; pro <= total; pro++){
		cin >> x >> y;
		printf("Property %d: This property will begin eroding in year %d.\n", pro, (int)ceil((x*x + y*y)*0.031415926));
	}printf("END OF OUTPUT.");
	return 0;
}
