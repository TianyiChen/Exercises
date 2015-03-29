#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	stack <string> back, forward;
	string cmd, inurl, url = "http://www.acm.org/";
	while (cin >> cmd)
	{
		if (cmd == "QUIT") return 0;
		if (cmd == "BACK"){
			if (back.empty())printf("Ignored\n"); else{
				forward.push(url); url = back.top(); back.pop();
				cout << url << endl;
			}
		}
		else if (cmd == "FORWARD"){
			if (forward.empty())printf("Ignored\n"); else{
				back.push(url); url = forward.top(); forward.pop();
				cout << url << endl;
			}
		}
		else {
			back.push(url);
			cin >> inurl;
			url = inurl;
			cout << url << endl;
			while (!forward.empty())forward.pop();
		}
	}
}
