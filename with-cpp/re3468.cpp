#include <bits/stdc++.h>
using namespace std;
int n, d, l, r, diff[2][31], cnt;
vector<int> vec;
void leftsum(int idx, int end, int sum){
	if(idx==end){
		vec.push_back(sum);
		return;
	}
	leftsum(idx+1, end, sum+(n-idx)*(diff[0][idx]-d));
	leftsum(idx+1, end, sum+(n-idx)*(diff[1][idx]-d));
}
void rightsum(int idx, int end, int sum){
	if(idx==end){
		int c1=upper_bound(vec.begin(), vec.end(), r-sum)-lower_bound(vec.begin(), vec.end(), -r-sum);
		int c2=upper_bound(vec.begin(), vec.end(), l-1-sum)-lower_bound(vec.begin(), vec.end(), -l+1-sum);
		cnt+=c1-max(c2, 0);
		return;
	}
	rightsum(idx+1, end, sum+(n-idx)*(diff[0][idx]-d));
	rightsum(idx+1, end, sum+(n-idx)*(diff[1][idx]-d));
}
int main(){
	scanf("%d%d%d%d", &n, &d, &l, &r);
	for(int i=1;i<=n;i++)scanf("%d", &diff[0][i]);
	for(int i=1;i<=n;i++)scanf("%d", &diff[1][i]);
	int mid=(n+1)/2;
	leftsum(1, mid, 0);
	sort(vec.begin(), vec.end());
	rightsum(mid, n, 0);
	printf("%d", cnt);
}
