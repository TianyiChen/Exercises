int main()
{
	float c, t;
	while (cin >> c){
		if (c == 0) return 0;
		float i = 2;
		for (t = 0; t < c; i++)
			t += 1 / i;
		cout << i - 2 << " card(s)" << endl;
	}
}
