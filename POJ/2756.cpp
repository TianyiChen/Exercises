#include <iostream>
#include<string>
using namespace std;
string a, b;
string zeros(int z){string r; while (z--)r += "0"; return r; }
bool is_bigger_abs(string x, string y){
	for (short tmp = 1; tmp < x.length(); tmp++)
		if (x[tmp]>y[tmp])return 1; else if (x[tmp] < y[tmp])return 0;
	return 0;
}
int main(){ 
	int t,tt; cin >> t; while (t--){
		cin>>a>>b;
		if (a[0] != '+'&&a[0] != '-')a = "+" + a;
		if (b[0] != '+'&&b[0] != '-')b = "+" + b;
		if (a.length() > b.length())swap(a, b);
		a = a[0] + zeros(b.length() - a.length()) + a.substr(1);
		//cout << "Debug: " << a << "  " << b << endl;
		if (a[0] == b[0]){
			//both positive or negative
			for (tt = a.length()-1; tt; tt--)if ((a[tt] += b[tt]-0x30) > '9'&&tt>1) a[tt] -= 10, a[tt - 1]++;
			if (a[1] > '9' && (a[1] -= 10))a = a[0] + "1" + a.substr(1);
		}
		else{
			if (is_bigger_abs(b, a))swap(a, b);
			for (tt = a.length()-1; tt; tt--)if ((a[tt] -= b[tt]-0x30)<'0') a[tt] += 10, a[tt - 1]--;
		}
		while (a[1] == '0'&&a.length()>2)a = a[0] + a.substr(2);
		if (a == "+0" || a == "-0")a = "0";
		if (a[0]=='+')a = a.substr(1);
		cout << a << endl;
	}
	return 0;}
