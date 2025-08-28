#include <iostream>
#include <string>
#include <vector>
using namespace std ;

/*205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.


Approach :

Initialize two arrays indexS and indexT of size 200 (covers extended ASCII range) to store the last seen positions of each character.

Length check: If s and t are not the same length, return false.

Iterate through each character:

For each position i, check if the last seen position of s[i] matches that of t[i].

If they differ, it means the mapping is inconsistent → return false.

Otherwise, update the last seen position of both characters to i + 1.

Return true if all characters match consistently.

🧠 Why i + 1 Instead of i?
Using i + 1 avoids confusion with the default value 0 (which means “never seen before”). This way, we can distinguish between unseen characters and those seen at index 0.
*/
bool isIsomorphic(string s, string t) {
        vector<int> indexS(200,0) ;
        vector<int> indexT(200,0) ;
        int len = s.length();
        if(len != t.length()){
            return false ;
        }
        for(int i = 0 ; i < len ; i++){
            if(indexS[s[i]] != indexT[t[i]]){
                return false ;
            }
            indexS[s[i]] = i+1 ;
            indexT[t[i]] = i+1 ;
        }
            return true ;
        
}

int main() {
    vector<pair<string, string>> testCases = {
        {"egg", "add"},
        {"foo", "bar"},
        {"paper", "title"},
        {"ab", "aa"},
        {"abc", "def"}
    };

    for (const auto& test : testCases) {
        cout << "Input: s = " << test.first << ", t = " << test.second
             << " Output: " << (isIsomorphic(test.first, test.second) ? "true" : "false") << endl;
    }

    return 0;
}




