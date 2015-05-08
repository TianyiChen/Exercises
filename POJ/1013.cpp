#include <iostream>
#include <string>
using namespace std;
bool exists(char nn[], char tt){
	for (short tmp = 0; tmp < strlen(nn); tmp++) if (tt == nn[tmp])return true;
	return false;
}
bool logiccmp(short x, short y)
{
	return(x == y) || x == 2 || y == 2;
}
int main(){
	int n; cin >> n;
	short temp, s[3];
	char a[3][7], b[3][7], c[3][5], t;
	while (n--){
		temp = 3; while (temp--)cin >> a[temp] >> b[temp] >> c[temp];
		for (t = 'A'; t <= 'L'; t++){
			if (!(exists(a[0], t) || exists(a[1], t) || exists(a[2], t) || exists(b[0], t) || exists(b[1], t) || exists(b[0], t)))continue;
			temp = 3; while (temp--)s[temp] = 2;
			temp = 3; while (temp--)if ((exists(a[temp], t) || exists(b[temp], t)) && !strcmp(c[temp], "even"))goto nextguess;
			temp = 3; while (temp--){
				if (exists(a[temp], t) && !strcmp(c[temp], "up") || exists(b[temp], t) && !strcmp(c[temp], "down"))s[temp] = 1;
				else if (exists(a[temp], t) || exists(b[temp], t))s[temp] = -1;
			}
			if (logiccmp(s[0], s[1]) && logiccmp(s[1], s[2]))
			{
				if (s[0] == 1 || s[1] == 1 || s[2] == 1)
					printf("%c is the counterfeit coin and it is heavy.\n", t); else
					printf("%c is the counterfeit coin and it is light.\n", t); break;
			}
		nextguess:;
		}
	}
	return 0;
}
