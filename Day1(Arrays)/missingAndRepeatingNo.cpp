#include <bits/stdc++.h>
using namespace std;

// First Solution
// By sorting the array
// Time Complexity: O(nlog n)
// Space Complexity: O(1)

// int main() {
// 	int n;
// 	cin>>n;
// 	vector <int> nums;
// 	for(int i=0;i<n;i++) {
// 		int el;
// 		cin>>el;
// 		nums.push_back(el);
// 	}
// 	sort(nums.begin(),nums.end());
// 	int missing=-1,r=-1,repeating=-1;
// 	for(int i=0;i<n;i++) {
// 		if(r==nums[i]) {
// 			repeating=nums[i];
// 			break;
// 		}
// 		r=nums[i];
// 	}
// 	for(int i=0;i<n;i++) {
// 		if(nums[i]!=i+1 && nums[i-1]!=repeating) {
// 			missing=i+1;
// 			break;
// 		}
// 	}
// 	cout<<"Missing = "<<missing<<", Repeating = "<<repeating;
// 	return 0;
// }

// Second Solution
// Time Complexity: O(2n) => ~O(n)
int main() {
	int n;
	cin>>n;
	vector <int> nums;
	for(int i=0;i<n;i++) {
		int el;
		cin>>el;
		nums.push_back(el);
	}
	vector <int> ans(n,0);
	for(int i=0;i<n;i++) { // Time Complexity: O(n)
		if(ans[nums[i]]==1) {
			ans[nums[i]]=2;
			continue;
		}
		ans[nums[i]]=1;
	}
	int missing=-1,repeating=-1;
	for(int i=0;i<n;i++) { // Time Complexity: O(n)
		if(ans[i]<1)
			missing=i;
		if(ans[i]>1)
			repeating=i;
	}
	cout<<"Missing = "<<missing<<", Repeating = "<<repeating;
	return 0;
}
