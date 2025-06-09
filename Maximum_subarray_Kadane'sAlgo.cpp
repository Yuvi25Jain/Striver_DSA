#include<iostream>
using namespace std ; 

//question : Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray

//brute : o(n3) ->better O(n2) -> optimal O(n)

//brute : We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.

//i loop from 0 to n , j from i to n and k from i to j.



// int maxSubarraySum(int arr[], int n) {
//     int maxi = INT_MIN; // maximum sum

//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             // subarray = arr[i.....j]
//             int sum = 0;

//             //add all the elements of subarray:
//             for (int k = i; k <= j; k++) {
//                 sum += arr[k];
//             }

//             maxi = max(maxi, sum);
//         }
//     }

//     return maxi;
// }



//better : remove k loop

/* Assume previous subarray = arr[i……j-1]
current subarray = arr[i…..j]
Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]*/


// int maxSubarraySum(int arr[], int n) {
//     int maxi = INT_MIN; // maximum sum

//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for (int j = i; j < n; j++) {
//             // current subarray = arr[i.....j]

//             //add the current element arr[j]
//             // to the sum i.e. sum of arr[i...j-1]
//             sum += arr[j];

//             maxi = max(maxi, sum); // getting the maximum
//         }
//     }

//     return maxi;
// }

//optimal : Kadane Algo

// We will run a loop(say i) to iterate the given array.
// Now, while iterating we will add the elements to the sum variable and consider the maximum one.
// If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.



// long long maxSubarraySum(int arr[], int n) {
//     long long maxi = LONG_MIN; // maximum sum
//     long long sum = 0;

//     for (int i = 0; i < n; i++) {

//         sum += arr[i];

//         if (sum > maxi) {
//             maxi = sum;
//         }

//         // If sum < 0: discard the sum calculated
//         if (sum < 0) {
//             sum = 0;
//         }
//     }

//     // To consider the sum of the empty subarray
//     // uncomment the following check:

//     //if (maxi < 0) maxi = 0;

//     return maxi;
// }

//follow up question : print the subarray too



long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}






int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}



