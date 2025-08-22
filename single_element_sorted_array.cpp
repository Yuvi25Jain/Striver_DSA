#include<iostream>
using namespace std ;

// single element in sorted array : [1,1,2,2,3,3,4,5,5,6,6]

int single_element(int a[], int n){
    if (n == 1){
        return a[0] ;
    }

    // three cases . 1st element which have no element on its left side and last element which have no elements in its right side , middle elements

    //brute force : if a[i-1] =(or) a[i] =(or) a[i+1] : then this element is duplicate

    //tc : o(n)


    for(int i = 0 ; i<n ; i++){
        if(i == 0){
            if(a[i] != a[i+1]){
                return a[i] ;
            }
        }
        else if( i == n-1){
            if (a[i] != a[i-1]){
                return a[i] ;
            }
        }
        else{
            if(a[i] != a[i-1] && a[i] != a[i+1]){
                return a[i];
            }
        }
    }
    return -1 ; 
}

//optimal solution
int search_element_binary(int a[], int n){
    if(n==1){
        return a[0];
    }
    if(a[0] != a[1]){
        return a[0] ;
    }
    if(a[n-1] != a[n-2]){
        return a[n-1];
    }
    int l = 1 , h = n-2;
    while(l<=h){
        int mid = (l+h)/2 ;
        if(a[mid] != a[mid-1] && a[mid] != a[mid+1] ){
            return a[mid] ;
        }
        // Check pairs and move pointers correctly
        if((mid % 2 == 0 && a[mid] == a[mid+1]) || (mid % 2 == 1 && a[mid] == a[mid-1])){
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return -1 ;
}
int main(){
    int a[11] = {1,1,2,2,3,3,4,5,5,6,6};
    int ans = single_element(a,11);
    cout<<"Single element in the sorted array is: "<<ans<<endl;
    int ans1 = search_element_binary(a,11);
    cout<<"Optimal search SIngle element: "<<ans1<<endl;
    return 0 ; 
}