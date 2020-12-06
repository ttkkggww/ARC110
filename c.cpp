#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i:a)cin >> i;
	vector<pair<int,int>> vp(n);
	BinaryIndexedTree<int> inv(n+1);
	for(int i = 0;i<n;i++){
		vp[i].second = inv.sum(n-a[i]);
		inv.add(n-a[i],1);
		vp[i].first=a[i];
	}
	vector<int> ans;
	int idx=1;
	vector<int> used(n,0);
	for(;idx<n;){
		if(vp[idx-1].second==0&&vp[idx].second==0){
			idx++;
		}else{
			if(used[idx]||idx==0){
				cout<<-1<<endl;
				return 0;
			}
			else{
				used[idx]++;
			}
			if(vp[idx-1].first>vp[idx].first)vp[idx].second--;
			swap(vp[idx-1],vp[idx]);
			ans.push_back(idx);
			idx--;
		}
	}
	if(ans.size()!=n-1){
		cout<<-1<<endl;
		return 0;
	}
	for(int i =0;i<n-1;i++){
		cout<<ans[i]<<endl;
	}

}
