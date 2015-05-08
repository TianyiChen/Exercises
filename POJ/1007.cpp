#include <iostream>
using namespace std;

int main()
{
	int n, m;
	char dna[500][1000]; int nx[1000] = { 0 };
	/*This line was originally defined as a smaller combination.
	But errors were encountered, following a related advice, I expanded them.
	*/
	char *ha, *hb;
	int i = 0, j;
	cin >> n >> m;
	for (; i < m; i++)
	{
		cin >> dna[i];
		for (int p = 0; p < n - 1; p++)
			for (int k = p + 1; k <= n - 1; k++)
				if (dna[i][p] > dna[i][k]) nx[i]++;
	}
	for (i = 0; i < m - 1; i++)
		for (j = 0; j < m - 1 - i; j++)
			if (nx[j] > nx[j + 1]){
				swap(nx[j], nx[j + 1]);
				//The folling line goes well with Visual Studio 2013, but faild on POJ.
				//swap(dna[j], dna[j + 1]);
				ha = &dna[j][0]; hb = &dna[j + 1][0];
				for (int temp = 0; temp < n; temp++)
					swap(*(ha + temp), *(hb + temp));
			}
	for (i = 0; i <= m - 1; i++)
		cout << dna[i] << endl;
	return 0;
}
