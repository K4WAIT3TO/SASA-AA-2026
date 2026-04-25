#include <bits/stdc++.h>
using namespace std;
vector<int> edge[300001];
int n, m, deg[300001], visited[300001];
int s, oddcount;

void dfs(int v){
	visited[v]=1;
	if(deg[v]%2)oddcount++;
	for(int i=0;i<(int)edge[v].size();i++){
		int u=edge[v][i];
		if(!visited[u]){
			dfs(u);
		}
	}
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int Va, Vb;
		scanf("%d%d", &Va, &Vb);
		edge[Va].push_back(Vb);
		edge[Vb].push_back(Va);
		deg[Va]++;
		deg[Vb]++;
	}
	
	for(int i=1;i<=n;i++){
		if(!deg[i]||visited[i])continue;
		oddcount=0;
		dfs(i);
		if(!oddcount)s+=2;
		else s+=oddcount;
	}
	if(!s)printf("0");
	else printf("%d", s-2);
}
