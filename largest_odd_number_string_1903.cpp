#include <iostream>
#include <string>
#include <vector>
using namespace std ;

/*1903 : Largest Odd Number in String

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
 

Constraints:

1 <= num.length <= 105
num only consists of digits and does not contain any leading zeros.

Approach
1. Iterate through the string from right to left.
2. If the last digit is odd, return the entire string as it is already the largest odd number.
3. If the last digit is even, keep moving left until an odd digit is found.
Return the substring from the beginning of the string to the index where the first odd digit is encountered.

Complexity
The time complexity is O(n), where n is the length of the input string num.
The space complexity is O(1) since we are not using any extra space that scales with the input size*/

string largestOddNumber(string num) {
        if(num.back() % 2 == 1) return num ; //last digit is odd
        for(int i = num.length() - 1 ; i>=0 ; i--){
            int n = num[i];
            if(n % 2 == 1) return num.substr(0,i+1);
        }
        return "" ;
        
}

int main(){
vector<string> testCases = {
        "52", "4206", "35427"
        
    };

    for (string s : testCases) {
        cout << "Input: " << s << " Output: " <<largestOddNumber(s)<<endl ;
    }

return 0 ;
}
