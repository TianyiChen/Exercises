#include <iostream>
#include <string>
using namespace std;
short smtemp[10]; short tmp, temp;
/*The following code block is required on POJ 
Because POJ does not support to_string.
However, on UVA, we do not need to define this function,
but the function memset will be said not defined and cause a CE
On my local environment which is Visual Studio 2013 with update 4,
No extra definition is needed to run the following code
→_→ Visual C++ 2013 is so good!*/
#define _TOSTRING(buf, fmt, val)	\
	sprintf_s(buf, sizeof (buf), fmt, val)
inline string to_string(int _Val)
{	// convert int to string
	char _Buf[2 * _MAX_INT_DIG];

	_CSTD _TOSTRING(_Buf, "%d", _Val);
	return (string(_Buf));
}
//End of extra function definition.
string sm(string fi){
	memset(smtemp, 0, sizeof(smtemp));
	string freturn;
	for (tmp = 0; tmp < fi.length(); tmp++)smtemp[fi[tmp] - 0x30]++;
	for (tmp = 0; tmp < 10; tmp++){
		if (smtemp[tmp])freturn += to_string(smtemp[tmp]) + to_string(tmp);
	}
	return freturn;
}
int main(){
	string input; string history[16]; int loop;
	while (cin >> input){
		if (input == "-1")return 0;
		if (sm(input) == input){ cout << input << " is self-inventorying" << endl; continue; }
		history[0] = input;
		for (loop = 1; loop <16; loop++){
			history[loop] = sm(history[loop - 1]);
			if (history[loop] == sm(history[loop])){
				cout << input << " is self-inventorying after " << loop << " steps" << endl;
				goto next;
			}
			for (temp = 0; temp < loop; temp++){
				if (history[loop] == history[temp]){
					cout << input << " enters an inventory loop of length " << loop - temp << endl;
					goto next;
				}
			}
		}
		cout << input << " can not be classified after 15 iterations" << endl;
	next:;
	}
}
