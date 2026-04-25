#include <stdio.h>
int n, m, ans, cur, cur_n;
int main(){
	scanf("%d%d", &n, &m);
	cur=(1<<(n-1))-1;
	cur_n=n-1;
	while(cur_n){
		if(cur>m){
			cur>>=1;
			cur_n-=1;
		}else{
			ans+=m/cur*cur_n;
			m%=cur;
		}
	}
	printf("%d", ans);
}
