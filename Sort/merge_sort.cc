#include <iostream>
#include <vector>



void merge(std::vector<int> &arr, int left, const int mid,
		  const int right, std::vector<int> tmp){
	int left_idx = left;
	int right_idx = mid+1;
	int k = 0;

	while(left_idx<=mid && right_idx<=right){
		if(arr[left_idx]<=arr[right_idx])
			tmp[k++] = arr[left_idx++];
		else
			tmp[k++] = arr[right_idx++];
    }
		while(left_idx<=mid) tmp[k++] = arr[left_idx++];
		while(right_idx<=right) tmp[k++] = arr[right_idx++];

		k=0;
		while(left<=right)
			arr[left++] = tmp[k++];

}


void merge_sort(std::vector<int> &arr, const int left, const int right, std::vector<int> tmp){
	if(left<right){
		int mid = (left+right)>>1;
		merge_sort(arr, left, mid, tmp);
		merge_sort(arr, mid+1, right, tmp);
		merge(arr, left, mid, right, tmp);
	}
}



int main(int argc, char const *argv[])
{
	int arr[] = {1,4,0,3,5,9,7};
	std::vector<int> v;
	v.insert(v.begin(), arr, arr+7);
	std::vector<int> temp(v.size());

	merge_sort(v, 0, 6, temp);

	for(int idx=0; idx<v.size(); idx++)
		std::cout<<v[idx]<<" ";
	std::cout<<std::endl;
	return 0;
}
