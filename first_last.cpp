#include<iostream>
#include<vector>
#include<utility>
using namespace std ;

//first and last occurance of element 
// a[8] = {2,4,6,8,8,8,11,13} , x= 8 , return {3,5}

//way1: using linear search . takes o(n). compare the element with target. increase first and last accordingly.
// pair<int,int> firstAndLast(vector<int>& a, int x){
//     int first  = -1 , last = -1 ;
//     int low = 0 , high = a.size()-1 ;

//     for(int i = 0 ; i< a.size(); i++){
//         if(a[i] == x){
//             if(first == -1){
//                 first = i ;
//             }

//                 last = i ;
            
//         }
//     }
//     return make_pair(first, last);

// }

//way2 : optimised : binary search functionalities of lower and upper bound


// int lowerbound(vector<int>&a, int n , int x){
//     int low = 0 , high = n-1 ;
//     int ans = n ;
//     while(low<=high){
//         int mid = low + (high-low)/2 ;
//         if(a[mid] >=x){
//             ans = mid ;
//             high = mid-1 ;
//         }
//         else{
//             low = mid+1 ;
//         }
//     }
//     return ans ;
// }



// int upperbound(vector<int>&a, int n , int x){
//     int low = 0 , high = n-1 ;
//     int ans = n ;
//     while(low<=high){
//         int mid = low + (high-low)/2 ;
//         if(a[mid]>x){
//             ans = mid ;
//           high = mid - 1 ;
//         }
//         else{
//             low = mid + 1 ; 
//         }
//     }
//     return ans ;
// }

// pair<int , int>firstAndLast(vector<int>& a , int n, int x){
//     int lb = lowerbound(a,n,x);
//     if( (lb ==n) || (a[lb] !=x)) {
//         return {-1,-1};
//     }
//     else{
//         return{lb, upperbound(a,n,x)-1} ;
//     }
// }

//way 3 : pure bs , one for first occurance and one for last occurance

int first(vector<int>&a , int n , int x){

    int low = 0 , high = n-1 , first = -1 ;
    while(low <= high){
        int mid = low + (high - low)/ 2 ;
        if(a[mid] == x){
            first = mid ;
            high = mid - 1 ;
        }
        else if (a[mid] < x){
            low = mid +1 ;
        }
        else{
            high = mid - 1 ; 
        }
    }
    return first; 
    

   
}
int last(vector<int>&a , int n , int x){

    int low = 0 , high = n-1 , last = -1 ;
    while(low <= high){
        int mid = low + (high - low)/ 2 ;
        if(a[mid] == x){
            last = mid ; 
           low = mid +1 ;
        }
        else if (a[mid] < x){
            low = mid +1 ;
        }
        else{
            high = mid - 1 ; 
        }
    }
    return last ; 
    

   
}


pair<int , int>firstAndLast(vector<int>& a , int n, int x){
   int ft = first(a,n,x) ;
   if ( ft == -1) return {-1,-1} ;
   int lt = last(a,n,x) ;
   return{ft, lt} ;
}




int main(){
    vector<int> a = {2,4,6,8,8,8,11,13};
    int n = a.size() ; 
    int x = 8 ;
    pair<int, int> result = firstAndLast(a,n,x);
    cout<<"First occurance: "<<result.first<<" last occurance: "<<result.second<<endl;

    //for vector : result[0] and result[1]
    return 0;
}

