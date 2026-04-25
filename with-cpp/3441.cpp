#include <stdio.h>
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int cur=(1<<(n-1))-1, cur_n=n-1, ans=0;
	while(cur_n){
		if(cur>m){
			cur>>1;
			cur_n-=1;
		}else{
			ans+=m/cur*cur_n;
			m%=cur;
		}
	}
	printf("%d", ans);
}
