#include <stdio.h>
int num[100005], dist[100005], lgcd[100005], rgcd[100005];
int gcd(int a, int b){
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main(){
	int l, k, q;
	scanf("%d", &l);
	for(int i=0;i<l;i++){
		scanf("%d", num+i);
	}
	scanf("%d", &k);
	k--;
	
	for(int i=0;i<l;i++){
		int cur=(k+i)%l;
		int prev=(K+i-1+l)%l;
		
		dist[cur]=i;
		if(i==0){
			lgcd[cur]=num[cur];
		}else{
			lgcd[cur]=gcd(lgcd[prev], num[cur]);
		}
	}
	
	for(int i=0;i<l;i++){
		int cur=(k-i+l)%l;
		int prev=(k-i+1+l)%l;
		
		if(i==0){
			rgcd[cur]=num[cur];
		}else{
			rgcd[cur]=gcd(rgcd[prev], num[cur]);
		}
	}
	
	int mx=-1, mxa=-1, mxb=-1;
	scanf("%d", &q);
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
	printf("%d%d\n%d\n", mxa+1, mxb+1, mx);
}
