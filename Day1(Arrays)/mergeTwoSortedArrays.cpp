#include <bits/stdc++.h>
using namespace std;

// First Solution
// Using third array
// Storing array1 and array2 elements in array3
// Sorting array3
// Pushing new array3 to array1 and array2
// Time Complexity: O(2n + nlog n) => ~ O(n)

// int main() {
// 	int n1,n2;
// 	cin>>n1>>n2;
// 	vector <int> a1;
// 	for(int i=0;i<n1;i++) {
// 		int el;
// 		cin>>el;
// 		a1.push_back(el);
// 	}
// 	vector <int> a2;
// 	for(int i=0;i<n2;i++) {
// 		int el;
// 		cin>>el;
// 		a2.push_back(el);
// 	}
// 	int n=n1+n2;
// 	vector <int> a;
// 	for(int i=0;i<n;i++) { // Time Complexity: O(n)
// 		if(i<n1) {
// 			a.push_back(a1[i]);
// 		} else {
// 			a.push_back(a2[i-n1]);
// 		}
// 	}
// 	sort(a.begin(),a.end()); // Time Complexity: O(nlog n)
// 	for(int i=0;i<n;i++) { // Time Complexity: O(n)
// 		if(i<n1)
// 			a1[i]=a[i];
// 		else
// 			a2[i-n1]=a[i];
// 	}
// 	cout<<endl;
// 	for(auto it:a1)
// 		cout<<it<<" ";
// 	cout<<endl;
// 	for(auto it:a2)
// 		cout<<it<<" ";
// 	return 0;
// }

// Second Solution
// Using Insertion Sort Algorithm
// Time Complexity: O(n1*m1)
// void merge(vector <int> a1, vector <int> a2, int n1, int n2) {
// 	for(int i=0;i<n1;i++) {
// 		if(a1[i]>a2[0]) {
// 			swap(a1[i],a2[0]);
// 			int first=a2[0];
// 			int k;
// 			for(k=1;k<n2 && a2[k]<first;k++) {
// 				a2[k-1]=a2[k];
// 			}
// 			a2[k-1]=first;
// 		}
// 	}
// 	cout<<endl;
// 	for(auto it:a1)
// 		cout<<it<<" ";
// 	cout<<endl;
// 	for(auto it:a2)
// 		cout<<it<<" ";
// }

// int main() {
// 	int n1,n2;
// 	cin>>n1>>n2;
// 	vector <int> a1;
// 	for(int i=0;i<n1;i++) {
// 		int el;
// 		cin>>el;
// 		a1.push_back(el);
// 	}
// 	vector <int> a2;
// 	for(int i=0;i<n2;i++) {
// 		int el;
// 		cin>>el;
// 		a2.push_back(el);
// 	}
// 	merge(a1,a2,n1,n2);
// 	return 0;
// }

// Third Solution
// Gap Method

int nextGap(int gap) {
	if(gap<=1)
		return 0;
	return (gap/2)+(gap%2);
}

void merge(vector* <int> a1, vector* <int> a2, int n1, int n2) {
	int i,j,gap=n1+n2;
	for(gap=nextGap(gap);gap>0;gap=nextGap(gap))
		for(i=0;i+gap<n1;i++)
			if(a1[i]>a1[i+gap])
				swap(a1[i],a1[i+gap]);
	for(j=gap>n1?gap-n1:0;i<n1&&j<n2;i++,j++)
		if(a1[i]>a2[j])
			swap(a1[i],a2[j]);
	if(j<n2)
		for(j=0;j+gap<n2;j++)
			if(a2[j]>a2[j+gap])
				swap(a2[j],a2[j+gap]);
}

int main() {
	int n1,n2;
	cin>>n1>>n2;
	vector <int> a1;
	for(int i=0;i<n1;i++) {
		int el;
		cin>>el;
		a1.push_back(el);
	}
	vector <int> a2;
	for(int i=0;i<n2;i++) {
		int el;
		cin>>el;
		a2.push_back(el);
	}
	merge(a1,a2,n1,n2);
	for(auto it:a1)
		cout<<it<<" ";
	cout<<endl;
	for(auto it:a2)
		cout<<it<<" ";
	return 0;
}