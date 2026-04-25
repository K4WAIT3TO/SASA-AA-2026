////#include <bits/stdc++.h>
////using namespace std;
////
////int n, k, arr[31], cnt;
////vector<int> vec;
////
////void leftSum(int idx, int end, int sum){
////	if(idx==end){
////		vec.push_back(sum);
////		return;
////	}
////	leftSum(idx+1, end, sum);
////	leftSum(idx+1, end, sum+arr[idx]);
////}
////
////void rightSum(int idx, int end, int sum){
////	if(idx==end){
////		cnt+=upper_bound(vec.begin(), vec.end(), k-sum)-lower_bound(vec.begin(), vec.end(), k-sum);
////		return;
////	}
////	
////	rightSum(idx+1, end, sum);
////	rightSum(idx+1, end, sum+arr[idx]);
////}
////
////int main(){
////	scanf("%d%d", &n, &k);
////	for(int i=0;i<n;i++)scanf("%d", &arr[i]);
////	int m=n/2;
////	
////	leftSum(0, m, 0);
////	sort(vec.begin(), vec.end());
////	rightSum(m, n, 0);
////	printf("%d", cnt);
////}
//
//#include <bits/stdc++.h>
//using namespace std;
//int n, d, l, r, diff[2][31], cnt;
//vector<int> vec;
//
//void leftSum(int idx, int end, int sum){
//	if(idx==end){
//		vec.push_back(sum);
//		return;
//	}
//	leftSum(idx+1, end, sum+(n-idx)*(diff[0][idx]-d));
//	leftSum(idx+1, end, sum+(n-idx)*(diff[1][idx]-d));
//}
//
//void rightSum(int idx, int end, int sum){
//	if(idx==end){
//		int c1=upper_bound(vec.begin(), vec.end(), r-sum)-lower_bound(vec.begin(), vec.end(), -r-sum);
//		int c2=upper_bound(vec.begin(), vec.end(), l-1-sum)-lower_bound(vec.begin(), vec.end(), -(l-1)-sum);
//		cnt+=c1-max(c2, 0);
//		return;
//	}
//	rightSum(idx+1, end, sum+(n-idx)*(diff[0][idx]-d));
//	rightSum(idx+1, end, sum+(n-idx)*(diff[1][idx]-d));
//}
//
//int main(){
//	scanf("%d%d%d%d", &n, &d, &l, &r);
//	for(int i=1;i<n;i++)scanf("%d", &diff[0][i]);
//	for(int i=1;i<n;i++)scanf("%d", &diff[1][i]);
//	
//	int mid=(n+1)/2;
//	leftSum(1, mid, 0);
//	sort(vec.begin(), vec.end());
//	rightSum(mid, n, 0);
//	
//	printf("%d", cnt);
//}
//






















#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n, d, l, r, diff[2][31], cnt;
void leftsum(int idx, int end, int sum){
	if(idx==end){
		vec.push_back(sum);
		return;
	}
	leftsum(idx+1, end, sum+(n-1-idx)*(diff[0][idx]-d));
	leftsum(idx+1, end, sum+(n-1-idx)*(diff[1][idx]-d));
	
}
void rightsum(int idx, int end, int sum){
	if(idx==end){
		int c1=upper_bound(vec.begin(), vec.end(), r-sum)-lower_bound(vec.begin(), vec.end(), -r-sum);
		int c2=upper_bound(vec.begin(), vec.end(), l-sum-1)-lower_bound(vec.begin(), vec.end(), -l-sum+1);
		cnt+=c1-max(c2, 0);
		return;
	}
	rightsum(idx+1, end, sum+(n-1-idx)*(diff[0][idx]-d));
	rightsum(idx+1, end, sum+(n-1-idx)*(diff[1][idx]-d));
}
int main(){
	scanf("%d%d%d%d", &n, &d, &l, &r);
	for(int i=0;i<n-1;i++)scanf("%d", &diff[0][i]);
	for(int i=0;i<n-1;i++)scanf("%d", &diff[1][i]);
	int mid=n/2;
	leftsum(0, mid, 0);
	sort(vec.begin(), vec.end());
	rightsum(mid, n-1, 0);
	printf("%d", cnt);
}
