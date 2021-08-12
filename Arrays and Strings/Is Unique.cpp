#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
Implement an algorithm to determine if a string has all unique characters. 
What if you cannot use additional data structures?

Assumptions: input is valid
*/

//O(n) time and O(n) space- use a char map
bool is_unique_option_1(string s)
{
    unordered_set<char> set;
    for(int i = 0; i < (int)s.length(); i++)
    {
        if(set.find(s[i]) == set.end())
            set.insert(s[i]);
        else
            return false;
    }
    return true;
}

//O(nlogn) time and O(1) space- sort the input and check for adjacent duplicates
bool is_unique_option_2(string s)
{
    sort(s.begin(), s.end());
    for(int i = 1; i < (int)s.length(); i++)
        if(s[i] == s[i-1]) return false;
    return true;
}

int main() {
    string s = "letcode";
    string t = "letcod";
    if(is_unique_option_1(s)) cout << "Is unique!";
    else cout << "Isn't unique!";
    cout <<"\n";
    
    if(is_unique_option_2(t)) cout << "Is unique!";
    else cout << "Isn't unique!";
}