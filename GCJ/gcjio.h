#include<string>
using namespace std;
void setio(){
	string filename;cin>>filename;
	FILE *fin=freopen((filename+".in").c_str(),"r",stdin);
	FILE *fout=freopen((filename+".out").c_str(),"w",stdout);
}