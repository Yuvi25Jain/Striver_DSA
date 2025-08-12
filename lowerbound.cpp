#include<iostream>
#include<vector>
using namespace std ; 

int lower_bound(vector <int> &arr , int x){
    int s = 0 , e = arr.size() - 1 , ans  = arr.size();
    while(s<=e){
        int mid = e + (s-e)/2 ;
        if(arr[mid] >= x){
            ans = mid ;
            e = mid - 1 ; 


        }
        else{
            s = mid + 1 ;
        }
        
    }
    return ans ; 
}

int main() {
    // Create a sorted vector
    vector<int> arr = {1,2,3,3,5,8,8,10,10,11};
    // Define the target value to search for
    
    // Call the binary_search function
    int result = lower_bound(arr,9);
    // Check the result and print the appropriate message
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    return 0;
}