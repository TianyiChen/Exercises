#include <iostream>
#include <cstring>
using namespace std;
inline bool islegalchar(char i){
	return i == '>' || i == '<' || i == '+' || i == '-' || i == '.' || i == '[' || i == ']';
}
int main(){ 
	int N,t,ci=1,deep; cin >> N;
	char ws[32768],op[128000],*p,*c,*e,*o,*tmp;//workspace
	char ui[128000], cp[128000];//user input,code place
	while (N--){
		printf("PROGRAM #%d:\n", ci++);
		memset(op, 0, sizeof(op)); o = op;
		memset(ws, 0, sizeof(ws)); memset(cp, 0, sizeof(ws));		
		c = cp;
		while (1){
			cin.getline(ui, 128000);
			if (!strcmp("end", ui))break;
			for (t = 0; ui[t] != '%'&&ui[t] != '\0'; t++)if (islegalchar(ui[t]))*c++ = ui[t];
		}
		//for (int temp = 0; temp < strlen(cp); temp++)printf("%c", cp[temp]);
		p = ws; e = c; c = cp;
		while (c < e){
			switch (*c){
			case '+':++*p; break;
			case '-':--*p; break;
			case '>':if (p == ws + 32767)p == ws; else p++; break;
			case '<':if (p == ws)p == ws + 32767; else p--; break;
			case '.':*o++=*p; break;
			case '[':deep = 1; if (!*p){
				        while (deep){ c++;
				        if (c == e) {printf("COMPILE ERROR\n"); goto nextcode; }
					    if (*c == ']')deep--; else if (*c == '[')deep++;}}
					 else{//execute COMPILE ERROR check
						 tmp = c; while (deep){tmp++;
						if (tmp== e) { printf("COMPILE ERROR\n"); goto nextcode; }
						if (*tmp == ']')deep--; else if (*tmp == '[')deep++;
						 }}break;
			case ']':deep = 1; if (*p){
				while (deep){
					c--; if (c <cp) { printf("COMPILE ERROR\n"); goto nextcode; }
					if (*c == '[')deep--; else if (*c == ']')deep++;
				}
			}else{tmp = c; 
				while (deep){tmp--;
					if (tmp <cp) { printf("COMPILE ERROR\n"); goto nextcode; }
					if (*tmp == '[')deep--; else if (*tmp == ']')deep++;
				}}break;
			}
			c++;
		}
		cout << op << endl;
		nextcode:;
	}
	return 0; }
