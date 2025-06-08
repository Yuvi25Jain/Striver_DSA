#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// question : find the majority element in the array.
// brute O (n2) -> better o(nlogn) + o(n) -> optimal using moore voting algorithm (o(n))

//brute force : two loop . match element . if same increase count by one . compare if count greater than half of size of array
// int majorityElement(vector<int> v) {

//     //size of the given array:
//     int n = v.size();

//     for (int i = 0; i < n; i++) {
//         //selected element is v[i]
//         int cnt = 0;
//         for (int j = 0; j < n; j++) {
//             // counting the frequency of v[i]
//             if (v[j] == v[i]) {
//                 cnt++;
//             }
//         }

//         // check if frquency is greater than n/2:
//         if (cnt > (n / 2))
//             return v[i];
//     }

//     return -1;
// }


//better : use a hashmap and store (key,value )pair . key is element and value is the no of tiimes it occurs. traverse the array and update the value of key. check if the value is greater than the floor of n/2. if yes return the key else iterate forward.



// int majorityElement(vector<int> v) {

//     //size of the given array:
//     int n = v.size();

//     //declaring a map:
//     map<int, int> mpp;

//     //storing the elements with its occurnce:
//     for (int i = 0; i < n; i++) {
//         mpp[v[i]]++;
//     }

//     //searching for the majority element:
//     for (auto it : mpp) {
//         if (it.second > (n / 2)) {
//             return it.first;
//         }
//     }

//     return -1;
// }

//optimal : moorey voting

// Initialize 2 variables:
// Count –  for tracking the count of element
// Element – for which element we are counting
// Traverse through the given array.
// If Count is 0 then store the current element of the array as Element.
// If the current element and Element are the same increase the Count by 1.
// If they are different decrease the Count by 1.
// The integer present in Element should be the result we are expecting 


int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

int main(){
    vector<int> a = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
    int ans = majorityElement(a) ;
    cout<<"Majority element in the given array is: "<<ans<<endl;
    return 0 ;

}