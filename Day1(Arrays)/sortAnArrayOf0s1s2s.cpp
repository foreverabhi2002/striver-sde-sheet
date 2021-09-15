#include <bits/stdc++.h>
using namespace std;

// First Solution
// By sorting the array
// Time Complexity: O(nlog n)
// Space Complexity: O(1)

int main() {
	int n;
	cin>>n;
	vector <int> nums;
	for(int i=0;i<n;i++) {
		int el;
		cin>>el;
		nums.push_back(el);
	}
	sort(nums.begin(),nums.end());
	for(auto it:nums) {
		cout<<it<<" ";
	}
	return 0;
}

// Second Solution
// By counting sort
// Step 1: Traverse through the array and count the no. of 0's, 1's and 2's
// Step 2: Run a loop for no. occurences of 0's, then for 1's and then  for 2's
// Time Complexity: O(n) + O(n) = O(2n)



// Third Solution
// Dutch National Flag Algorithm
// three pointers need to consider: low, mid and high ptr
// Initially low ptr at the start, mid ptr at the start and high ptr at the last
// [0....low-1] -> 0
// [high+1....n] -> 2
// Time Complexity: O(n)
// Space Complexity: O(1)

void sortColors(vector<int>& nums) {
	int low=0;
	int high=nums.size()-1;
	int mid=0;

	while(mid<=high) {
		switch(nums[mid]) {
			// If element is 0
			case 0:
				swap(nums[low++],nums[mid++]);
				break;
			// If element is 1
			case 1:
				mid++;
				break;
			// If element is 2
			case 2:
				swap(nums[mid],nums[high--]);
				break;
		}
	}
	for(auto it:nums) {
		cout<<it<<" ";
	}
}

int main() {
	int n;
	cin>>n;
	vector <int> nums;
	for(int i=0;i<n;i++) {
		int el;
		cin>>el;
		nums.push_back(el);
	}
	sortColors(nums);
	return 0;
}