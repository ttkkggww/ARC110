#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	ll n;
	string t;
	cin >> n >> t;
	ll ans = 1;
	for(int i = 0;i<10;i++)ans *=10;
	if(t=="1"){
		cout<<ans*2<<endl;
		return 0;
	}
	if(t=="0"){
		cout<<ans<<endl;
		return 0;
	}

	string s;
	for(int i = 0;i<n;i++){
		s.push_back('1');
		s.push_back('1');
		s.push_back('0');
	}
	int st = -1;
	if(t==s.substr(0,n))st = 0;
	if(t==s.substr(1,n))st = 1;
	if(t==s.substr(2,n))st = 2;

	if(st==-1){
		cout<<0<<endl;
		return 0;
	}

	cout<< ans - ((n-3+st+2)/(3)) << endl;
	
	

}
