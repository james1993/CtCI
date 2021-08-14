#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Implement a method to perform basic string compression using the counts of repeated characters.
If the "compressed" string would not become smaller than the original string, your method should return the original string. 
*/

//O(n) time
//O(1) space
string compress(string s)
{
    string compressed_s = "";
    int count = 1;
    for(int i = 1; i < (int)s.length(); i++)
    {
        if(s[i] == s[i-1]) count++;
        else
        {
            compressed_s += s[i-1];
            compressed_s += to_string(count);
            count = 1;
        }
    }
    compressed_s += s[s.length()-1];
    compressed_s += to_string(count);
    
    return compressed_s.length() >= s.length() ? s : compressed_s;
}

int main() {
    string s ="aabcccccaaaaaaaaaaaaaaaaa";
    string compressed_s = compress(s);
    cout << compressed_s;
}