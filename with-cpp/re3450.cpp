#include <bits/stdc++.h>
using namespace std;
int a[100005], lgcd[100005], rgcd[100005], dist[100005], l, k, q;
int gcd(int a, int b){
	while(b){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	scanf("%d", &l);
	for(int i=0;i<l;i++)scanf("%d", a+i);
	scanf("%d", &k);
	k--;
	for(int i=0;i<l;i++){
		int cur=(k+i)%l;
		int pre=(k+i-1+l)%l;
		dist[cur]=i;
		if(!i)lgcd[cur]=a[cur];
		else lgcd[cur]=gcd(lgcd[pre], a[cur]);
	}
	for(int i=0;i<l;i++){
		int cur=(k-i+l)%l;
		int pre=(k-i+l+1)%l;
		if(!i)rgcd[cur]=a[cur];
		else rgcd[cur]=gcd(rgcd[pre], a[cur]);
	}
	scanf("%d", &q);
	int mx=-1, mxa=-1, mxb=-1;
	for(int i=0;i<q;i++){
		int a, b, g;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if(dist[a]<dist[b]){
			g=gcd(lgcd[a], rgcd[b]);
		}else{
			g=gcd(rgcd[a], lgcd[b]);
		}
		if(g>mx){
			mx=g;
			mxa=a;
			mxb=b;
		}
	}
	printf("%d %d\n%d", mxa+1, mxb+1, mx);
}
