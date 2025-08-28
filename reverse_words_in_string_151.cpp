#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std ;

/* 151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?*/

/*All Solutions


Easy and Simple C++ solution | Two Pointers ✅

Ayush Bansal
50 Days Badge 2024
68876
Jul 23, 2024
Two Pointers
String
C++
Approach
1) Reverse the entire string: The solution begins by reversing the entire input string s. This step ensures that words which were at the end of the original string are now at the beginning, and vice versa.

2) Initialize pointers: Three pointers are used: left, right, and i, all initialized to 0. The left and right pointers help in marking the start and end of each word, while i traverses the string.

3) Skip leading spaces: The outer while loop iterates over the string. The inner loop while(i<n && s[i]==' ') i++; skips any leading spaces.

4) Process each word:

Identify word boundaries: Once the leading spaces are skipped, the second inner loop while(i<n && s[i]!=' ') identifies the current word and assigns characters to the correct position in the string starting from right.
Reverse the current word: After identifying the word, it is reversed back to its original order within the reversed string. This reversal is done using the reverse function on the substring from left to right.
Add space after the word: A space is added after the word to separate it from the next word.
5) Resize the string: After all words are processed, the string is resized to remove the trailing space added after the last word.

Reason for the Approach
Efficiency: Reversing the entire string first allows the algorithm to process words in their final position. This avoids the need for additional data structures, making the in-place manipulation of the string possible.

In-place manipulation: This approach modifies the input string directly without requiring extra space, which is memory efficient.

Simplicity: The logic of reversing the entire string and then reversing individual words is straightforward and easy to understand.

Complexity
Time complexity: O(n)
Space complexity: O(1)*/

string reverseWords(string s) {
        reverse(s.begin() , s.end()) ;
        int n = s.size();
        int left = 0 , right = 0 ;
        for(int i = 0 ;  i<n ; i++){
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }
            reverse(s.begin() + left, s.begin() + right);
            s[right++] = ' ';
            left = right;
            

        }
        s.resize(right - 1);
        return s;
        
}

int main(){
    vector<string> testCases = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        
    };
    for (string s : testCases) {
        cout << "Input: " << s << " Output: " << reverseWords(s) << endl;
    }
    
    return 0 ; 
}