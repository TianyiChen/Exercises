#include <iostream>
#include <iomanip>
using namespace std;
int main(){
float s=0,i;
cout<<fixed;
cout.precision(2);
for (int t=1;t<13;t++)
{cin>>i;s+=i;}
s/=12;
cout<<"$"<<s<<endl;
}
