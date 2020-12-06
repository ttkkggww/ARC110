#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	ll res = 1;
	int n;
	cin >> n;
	for(ll i = 2;i<=n;i++){
		ll tmp = res;
		ll t2 = i;
		for(ll j = 2;j<=i;j++){
			while(tmp%j==0&&t2%j==0){
				tmp/=j;
				t2/=j;
			}
		}
		res *= t2;
	}
	res ++;
	cout<<res<<endl;
}
