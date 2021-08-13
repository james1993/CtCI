// Example program
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Given a string, write afunction to check if it is a permutation of a palindrome.
*/

//O(n) time, O(1) space- add to set and erase from set. palindrome allows for only 1 non-duplicate.
bool is_perm_of_palin(string s)
{
    unordered_set<char> set;
    for(int i = 0; i < (int)s.length(); i++)
    {
        if(isalpha(s[i]))
        {
            char character = tolower(s[i]);
            if(set.find(character) == set.end()) set.insert(character);
            else set.erase(character);
        }
    }
    return set.size() < 2;
}

int main() {
    string s = "Tact Coaaa";
    if(is_perm_of_palin(s)) cout << "Yes!";
    else cout << "No!";
}