#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000000
int trie[SIZE][26]={0},e=2,children[SIZE]={0};
int main(){
	char i[11];
	int p,n;cin>>n;
	while (n--){
		scanf("%s",i);p=1;//p: the node we are visiting
		for (int _=0;_<strlen(i);_++){
			if (trie[p][i[_]-'a']){
				//found
				p=trie[p][i[_]-'a'];
				children[p]++;
			}
			else{
				trie[p][i[_]-'a']=e;
				children[p=e++]++;
			}
		}
	}
	cin>>n;while (n--){
		p=1;scanf("%s",i);
		for (int _=0;_<strlen(i);_++){
			if (trie[p][i[_]-'a'])
				p=trie[p][i[_]-'a'];
			else{
				puts("0");goto nc;
			}
		}printf("%d\n",children[p]);
	nc:;
	}
}