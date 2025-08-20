#include<iostream>
#include<vector>
using namespace std;

//Count Occurrences in Sorted Array

int countOccurrences(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

// Print occurrences of each element in a sorted array
void printOccurrences(int arr[], int n) {
    int i = 0;
    while (i < n) {
        int count = 1;
        while (i + count < n && arr[i] == arr[i + count]) {
            count++;
        }
        cout << arr[i] << " occurs " << count << " times" << endl;
        i += count;
    }
}


int search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int low = 0 , high = n-1 ;
        while(low<=high){
            int mid = low + (high - low)/2 ;
            if (nums[mid] == target){
                return mid ;
            }

            

                                //left part sorted
            
                    if(nums[low] <= nums[mid]){
                        //if element is present in left sorted part
                        if(nums[low] <= target && target <= nums[mid]){
                            //eliminate the right half
            
                            high = mid - 1 ; 
                        }
                        //eliminate the left sorted part
                        else{
                        low = mid + 1 ;
                        }
                    }
                    else{
                        //right part is sorted nums[mid] <= nums[high]
            
                        if(nums[mid] <= target && target <= nums[high]){
                            //eliminate the left half
            
                            low = mid + 1 ;
                        }
                        //eliminate the right sorted part
                        else{
                        high = mid-1 ;
                        }
                    }
                }
                
            return -1; 
}  

//question : duplicates in rotated sorted

//edge case : where a[low] = a[mid] = a[high] = all contain the same element

// means a[low] and a[high] can't be our target so eliminate them by shrinking the search space . how ? simply remove low = low +1  and high = high -1 and continue to above search. for unique elements

bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    int arr[8] =  {2, 4, 6, 8, 8, 8, 11, 13};
    int ans = countOccurrences(arr,8,8);
    cout<<"The number of occurances: "<<ans<<endl;

    cout<<endl;
    cout<<"Each element occurance is : "<<endl;
    printOccurrences(arr,8);

    vector<int> arrVec(arr, arr + 8);
    int ans2 = search(arrVec, 8);
    cout << "Index of 8 in arrVec: " << ans2 << endl;
    return 0 ; 

}