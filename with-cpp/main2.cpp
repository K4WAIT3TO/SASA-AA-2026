//실제 퀴즈에 사용한 파일
//퀴즈 규칙상 한 파일 안에 풀면서 기존의 코드를 주석 처리

////////#include <bits/stdc++.h>
////////using namespace std;
////////int n, m, k, a[2020];
////////int main(){
////////	scanf("%d%d%d", &n, &m, &k);
////////	for(int i=1;i<=n;i++)scanf("%d", &a[i]);
////////	int l=1, r=n;
////////	while(l<n&&a[l]<a[l+1]&&a[l+1]-a[l]<=m)l++;
////////	while(r>1&&a[r-1]<a[r]&&a[r]-a[r-1]<=m)r--;
////////	int s=max(l, n-r+1);
////////	for(int i=1;i<=l;i++){
////////		int j=r;
////////		while(j<n&&a[j]<=a[i])j++;
////////		if(a[i]<a[j]&&a[j]-a[i]<=m)s=max(s, n-j+i+1);
////////	}
////////	printf("%d\n", s);
////////	printf(s<k?"FAIL":"PASS");
////////}
////////
////////#include <bits/stdc++.h>
////////using namespace std;
////////int n, k;
////////int p[100005], cnt;
////////pair<int, int> a[100005], t[100005], ans[100005];
////////int find(int x){
////////	if(p[x]==x)return x;
////////	else return p[x]=find(p[x]);
////////}
////////int main(){
////////	scanf("%d%d", &n, &k);
////////	for(int i=0;i<n;i++){
////////		scanf("%d%d", &a[i].second, &a[i].first);
////////	}
////////	for(int i=0;i<k;i++){
////////		scanf("%d%d", &t[i].second, &t[i].first);
////////		p[i]=i;
////////	}p[k]=k;
////////	sort(a, a+n);
////////	sort(t, t+k);
////////	for(int i=n;i>0;i--){
////////		pair<int, int> target={a[i-1].second, 0};
////////		int ti=lower_bound(t, t+k, target)-t;
////////		if((ti=find(ti))==k)continue;
////////		ans[cnt++]={t[ti].second, a[i-1].first};
////////		p[ti]++;
////////	}
////////	sort(ans, ans+cnt);
////////	for(int i=0;i<cnt;i++){
////////		printf("%d %d\n", ans[i].first, ans[i].second);
////////	}
////////}
//////////
//////////#include <bits/stdc++.h>
//////////using namespace std;
//////////int n, m, s;
//////////int size[100005], p[100005], odd[100005], deg[100005], isroot[100005];
//////////int find(int x){
//////////	if(p[x]==x)return x;
//////////	return p[x]=find(p[x]);
//////////}
//////////void uni(int x, int y){
//////////	x=find(x);
//////////	y=find(y);
//////////	if(x==y)return;
//////////	if(size[x]<size[y]){
//////////		int temp=x;
//////////		x=y;
//////////		y=temp;
//////////	}
//////////	p[y]=x;
//////////	size[x]+=size[y];
//////////}
//////////int main(){
//////////	scanf("%d%d", &n, &m);
//////////	for(int i=0;i<n;i++)p[i]=i;
//////////	p[n]=n;
//////////	for(int i=0;i<m;i++){
//////////		int u, v;
//////////		scanf("%d%d", &u, &v);
//////////		deg[v]++;
//////////		deg[u]++;
//////////		uni(u, v);
//////////	}
//////////	for(int i=1;i<=n;i++){
//////////		if(deg[i]==0)continue;
//////////		int r=find(i);
//////////		isroot[r]=1;
//////////		if(deg[i]%2)odd[r]++;
//////////	}
//////////	for(int i=1;i<=n;i++){
//////////		if(!isroot[i])continue;
//////////		if(odd[i]==0)s+=2;
//////////		else s+=odd[i];
//////////	}
//////////	if(s==0)printf("0");
//////////	else printf("%d", s-2);
//////////}
//////////
//////////
//////#include <bits/stdc++.h>
//////using namespace std;
//////int n, m;
//////struct Trie{
//////	Trie *child[26];
//////	int cnt;
//////	Trie(){
//////		cnt=0;
//////		for(int i=0;i<26;i++)child[i]=nullptr;
//////	}
//////};
//////Trie *root=new Trie();
//////int bestp, point;
//////char best[30], word[30];
//////int main(){
//////	scanf("%d%d", &n, &m);
//////	for(int i=0;i<n;i++){
//////		scanf("%s", word);
//////		Trie *cur=root;
//////		for(int j=0;word[j];j++){
//////			int c=word[j]-'a';
//////			if(!cur->child[c])new Trie();
//////			cur=cur->child[c];
//////			cur->cnt++;
//////		}
//////	}
//////	
//////	for(int i=0;i<m;i++){
//////		point=0;
//////		scanf(" %s", word);
//////		Trie *cur=root;
//////		for(int j=0;word[j];j++){
//////			int c=word[j]='a';
//////			if(!cur->child[c])break;
//////			cur=cur->child[c];
//////			point+=cur->cnt;
//////		}
//////		if(point>bestp||(point==bestp&&strcmp(word, best)<0)){
//////			bestp=point;
//////			strcpy(best, word);
//////		}
//////	}
//////	printf("%s", best);
//////}
//////
////////#include <stdio.h>
////////int n, m, cur, cur_n, ans;
////////int main(){
////////	scanf("%d%d", &n, &m);
////////	cur=(1<<(n-1))-1;
////////	cur_n=n-1;
////////	while(cur_n){
////////		if(cur>m){
////////			cur>>=1;
////////			cur_n--;
////////		}else{
////////			ans+=(m/cur)*cur_n;
////////			m%=cur;
////////		}
////////	}
////////	printf("%d", ans);
////////}
//////
////////#include <bits/stdc++.h>
////////using namespace std;
////////int n, k, p[100005], a[100005];
////////int find(int x){
////////	if(p[x]==x)return x;
////////	return p[x]=find(p[x]);
////////}
////////int main(){
////////	scanf("%d%d", &n, &k);
////////	for(int i=0;i<n;i++){
////////		scanf("%d", a+i);
////////		p[i]=i;
////////	}p[n]=n;
////////	sort(a, a+n);
////////	
////////	for(int i=0;i<k;i++){
////////		int b, target;
////////		scanf("%d", &b);
////////		target=find(lower_bound(a, a+n, b+1)-a);
////////		if(target>=n){
////////			printf("%d", i);
////////			return 0;
////////		}
////////		p[target]=target+1;
////////	}
////////	printf("%d", k);
////////}
////
//#include <bits/stdc++.h>
//using namespace std;
//int n, m, point, bestp=-1;
//struct Trie{
//	Trie *child[26];
//	int cnt;
//	Trie(){
//		cnt=0;
//		for(int i=0;i<26;i++)child[i]=nullptr;
//	}
//};
//char word[30], best[30];
//Trie *root=new Trie();
//int main(){
//	scanf("%d%d", &n, &m);
//	for(int i=0;i<n;i++){
//		Trie *cur=root;
//		scanf(" %s", word);
//		for(int j=0;word[j];j++){
//			int c=word[j]-'a';
//			if(!cur->child[c])cur->child[c]=new Trie();
//			cur=cur->child[c];
//			cur->cnt++;
//		}
//	}
//	for(int i=0;i<m;i++){
//		Trie *cur=root;
//		point=0;
//		scanf(" %s", word);
//		for(int j=0;word[j];j++){
//			int c=word[j]-'a';
//			if(!cur->child[c])break;
//			cur=cur->child[c];
//			point+=cur->cnt;
//		}
//		if(point>bestp||(point==bestp&&strcmp(word, best)<0)){
//			bestp=point;
//			strcpy(best, word);
//		}
//	}
//	printf("%s", best);
//}
//










#include <bits/stdc++.h>
using namespace std;
int n, k, m, a[5000005], cnt;
int main(){
	scanf("%d%d%d", &n, &k, &m);
	for(int i=0;i<m;i++)scanf("%d", a+i);
	sort(a, a+m);
	int i=0, j=m-1;
	while(i<j){
		if(a[i]+a[j]<=k){
			cnt++;
			i++;
			j--;
		}else{
			j--;
		}
	}
	printf("%d", cnt);
}




















