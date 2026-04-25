#include <bits/stdc++.h>
using namespace std;
int h[2000002];
long long a1[2000002], a2[2000002];
int main(){
	int r, n;
	scanf("%d%d", &r, &n);
	int len=0;
	for(int i=1;i<=2*r;i++){
		long long x=4*(long long)r*r+1-(long long)i*i;
		if(x%4)continue;
		long long a=x/4;
		if(a>=r+1){
			h[len]=i;
			a1[len]=(2*a-1-i)/2;
			a2[len++]=(2*a-1+i)/2;
		}
	}
	while(n--){
		int i;
		scanf("%d", &i);
		int k=lower_bound(h, h+len, i)-h;
		if(h[k]!=i)printf("-1\n");
		else printf("%d (v%lld+v%lld)%d\n", k+1, a1[k], a2[k], i);
	}
}
