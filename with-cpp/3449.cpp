#include <bits/stdc++.h>
#define inf 214748364
using namespace std;

int cost[110][110][110];
int dp[110][110][110];

int solve(int a, int b, int c){
	if(a<1||b<1||c<1)return -inf;
	if(a==1&&b==1&&c==1)return cost[1][1][1];
	if(dp[a][b][c]!=-inf)return dp[a][b][c];
	dp[a][b][c]=max({solve(a-1, b, c), solve(a, b-1, c), solve(a, b, c-1)})+cost[a][b][c];
	return dp[a][b][c];
}
int main(){
	int p, q, r;
	scanf("%d%d%d", &p, &q, &r);
	for(int a=0;a<=p;a++){
		for(int b=0;b<=q;b++){
			for(int c=0;c<=r;c++){
				dp[a][b][c]=-inf;
			}
		}
	}
	for(int c=1;c<=r;c++){
		for(int b=1;b<=q;b++){
			for(int a=1;a<=p;a++){
				scanf("%d", &cost[a][b][c]);
			}
		}
	}
	printf("%d", solve(p, q, r));
}