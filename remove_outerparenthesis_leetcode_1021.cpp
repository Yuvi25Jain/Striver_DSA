#include<iostream>
#include<string>
#include<vector>
using namespace std ;

//1021. Remove Outermost Parentheses

// Example 1:

// Input: s = "(()())(())"
// Output: "()()()"
// Explanation: 
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

/*Approach
1. Initialize Variables:
'result': An empty string to store the final output.
balance: A counter to keep track of the balance of parentheses (( increases the balance and ) decreases it).
2. Loop Through the String:
Use a for loop to go through each character in the string s.
For each character:
If it’s an opening parenthesis (:
If the balance is more than 0, it means this ( is not an outermost parenthesis, so add it to 'result'.
Increase the balance by 1.
If it’s a closing parenthesis ):
Decrease the balance by 1.
If the balance is more than 0 after decreasing, it means this ) is not an outermost parenthesis, so add it to 'result'.
3. Return the Result:
After processing all characters, the 'result' string will contain the original string without the outermost parentheses.
Complexity
- Time complexity:

The time complexity is O(n), where n is the length of the string s. This is because we go through the string once.
- Space complexity:

The space complexity is O(n), where n is the length of the string s, because the result string might store almost all characters from s.*/


    // Function to remove outermost parentheses of every primitive string in the
    // decomposition of s*/
string removeOuterParentheses(string s) {
        string result;   // To store the final result
        int balance = 0; // To keep track of the balance of parentheses

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // If balance is greater than 0, it means this '(' is not an
                // outermost parenthesis
                if (balance > 0) {
                    result += s[i]; // Add the character to the result
                }
                balance++; // Increase the balance for '('
            } else {
                balance--; // Decrease the balance for ')'
                // If balance is greater than 0, it means this ')' is not an
                // outermost parenthesis
                if (balance > 0) {
                    result += s[i]; // Add the character to the result
                }
            }
        }

        return result; // Return the final result after removing outermost
                       // parentheses
}



int main() {

    //multiple strings
    vector<string> testCases = {
        "(()())(())",
        "(()())(())(()(()))",
        "()()",
        "(((())))"
    };

    for (string s : testCases) {
        cout << "Input: " << s << " Output: " << removeOuterParentheses(s) << endl;
    }

    /*for (int i = 0; i < testCases.size(); i++) {
    string s = testCases[i];
    // use s
}*/
    return 0;
}



/* byte size concept


for loop using index and for loop range based 

1. traditional for loop
int arr[] = {1, 2, 3, 4, 5};
int n = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
}
cout << endl;


2. range based for loop
int arr[] = {1, 2, 3, 4, 5};
for (int x : arr) {
    cout << x << " ";
}
cout << endl;

range based make the code easy to read and work without indices , iterates all the elements

for (datatype variable : container) {
    // code using variable
}*/