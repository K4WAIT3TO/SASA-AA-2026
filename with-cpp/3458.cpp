#include <bits/stdc++.h>
using namespace std;

int main(){
	stack<pair<int, int>> stk;
	int time=0;
	int cmd;
	int n;scanf("%d", &n);
	
	while(n>0){
		n--;
		scanf("%d", &cmd);
		
		if(cmd==1){
			int t;
			scanf("%d", &t);
			time+=t;
		}else if(cmd==2){
			int k;
			scanf("%d", &k);
			stk.push({time, k});
			time=0;
		}else if(cmd==3){
			int prev_time=stk.top().first;
			int k=stk.top().second;
			stk.pop();
			time=prev_time+time*k;
		}else if(cmd==4 and !stk.empty()){
			time=stk.top().first;
			stk.pop();
		}else time=0;
	}
	printf("%d", time);
}