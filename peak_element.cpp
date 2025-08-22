#include<iostream>
using namespace std ;

// peak element : what is peak element left element < current element > right element

// consider the 4 egs

/*
1. [1,2,3,4,5,6,7,8,1] = ans = 8
2. multiple peaks : return the first ones
3. strictly increasing  or 4. strictly decreasing: assume -infinity at both the end*/

//brute force : linear search o(n)

int peak_brute(int a[], int n){
    for(int i = 0 ; i< n ; i++){
        if ((i == 0 || a[i-1] < a[i]) && (i == n-1 || a[i] > a[i+1])) {
            return i;
        }
    }
    return -1;
}

//optimal approach : binary seach : o(logn)

int peak_optimal(int a[], int n){
    //single element 
    if(n == 1) {
        return 0 ;
    }
    // only 1st element
    if(a[0] > a[1]){
        return 0 ;
    }
    if(a[n-1] > a[n-2]){
        return n-1 ;
    }
    int l = 1, h = n - 2;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
            return mid;
        } else if (a[mid] < a[mid + 1]) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return -1;
}


int main(){
    int a[10] = {1,2,3,4,5,6,7,8,5,1};
    int b[7] = {1,2,1,3,5,6,4};
    int c[5] = {1,2,3,4,5} ;
    int d[5] = {5,4,3,2,1};
    int a1 = peak_brute(a,10);
    int a2 = peak_brute(b,7);
    int a3 = peak_brute(c,5);
    int a4 = peak_brute(d,5);
    cout<<"Peak element in arr1 : "<<a1<<" Peak element in 2 : "<<a2<<" Peak element in 3 : "<<a3<<" Peak element in 4: "<<a4<<endl;

    cout<<endl;

    int o1 = peak_optimal(a,10);
    int o2 = peak_optimal(b,7);
    int o3 = peak_optimal(c,5);
    int o4 = peak_optimal(d,5);
    cout<<"Optimal force answer: "<<endl;

    cout<<o1<<" "<<o2<<" "<<o3<<" "<<o4<<" "<<endl;
    return 0 ;
}