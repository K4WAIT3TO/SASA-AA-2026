#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[100005];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)scanf("%lld", a+i);
	sort(a, a+n);
	long long s=0, e=(a[n-1]-a[0]+1)/2;
	while(s<e){
		long long r=s+(e-s)/2, start=a[0];
		int cnt=1;
		for(int i=1;i<n;i++){
			if(a[i]-start>r*2){
				cnt++;
				start=a[i];
			}
		}
		if(cnt>m)s=r+1;
		else e=r;
	}
	printf("%lld", e);
}
