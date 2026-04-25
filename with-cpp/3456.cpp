#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=200005;
int n;
ll k, a[maxn], ls[maxn], rs[maxn], ln[maxn], rn[maxn];

ll solve(int l, int r){
	if(l==r){
		return a[1]==k?1LL:0LL);
	}
	
	int mid=(l+r)/2;
	ll ans=0;
	
	ans+=solve(l, mid);
	ans+=solve(mid+1, r);
	
	lm[mid]=a[mid];
	ls[mid]=a[mid];
	for(int i=mid-1;i>=1;i--){
		lm[i]=max(a[i], lm[i+1]);
		ls[i]=ls[i+1]+a[i];
	}
	
	rm[mid+1]=a[mid+1];
	rs[mid+1]=a[mid+1];
	for(int j=mid+2;j<=r;j++){
		rm[j]=max(a[j], 
	}
}