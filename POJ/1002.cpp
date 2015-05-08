#include <iostream>
#include <algorithm>
using namespace std;
char input[200]; int total, to; bool isdup = false;
int tp[100000];
int c[7] = { 0 }; int cp, op, oplen = 0, q = 0;
int z; short tt;
int main()
{
	cin >> total;
	to = total;
	while (total--)
	{
		scanf("%s", input);
		cp = 0;
		for (tt = 0; input[tt] != '\0'; tt++)
		{
			switch (input[tt]){
			case '0':c[cp++] = 0; break; case '1':c[cp++] = 1; break;
			case 'A':case 'B':case 'C':case '2':c[cp++] = 2; break;
			case 'D':case 'E':case 'F':case '3':c[cp++] = 3; break;
			case 'G':case 'H':case 'I':case '4':c[cp++] = 4; break;
			case 'J':case 'K':case 'L':case '5':c[cp++] = 5; break;
			case 'M':case 'N':case 'O':case '6':c[cp++] = 6; break;
			case 'P':case 'R':case 'S':case '7':c[cp++] = 7; break;
			case 'T':case 'U':case 'V':case '8':c[cp++] = 8; break;
			case 'W':case 'X':case 'Y':case '9':c[cp++] = 9; break;
			default:;
			}
		}
		z = c[6] + c[5] * 10 + c[4] * 100 + c[3] * 1000 + c[2] * 10000 + c[1] * 100000 + c[0] * 1000000;
		tp[q++] = z;
	}

	sort(tp, tp + to);
	op = tp[0]; oplen = 1;
	for (int i = 1; i <to; i++)
		if (tp[i] == op)oplen++;
		else{
			if (oplen>1){ isdup = true; printf("%03d-%04d %d\n", op / 10000, op % 10000, oplen); }
			op = tp[i]; oplen = 1;
		}if (oplen>1){
			isdup = true; printf("%03d-%04d %d\n", op / 10000, op % 10000, oplen);
		}
		if (!isdup)printf("No duplicates.\n");
		return 0;
}
