#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
Given two strings, write a method to decide if one is a permutation of the other.
*/

//O(1) space O(n) time
bool is_permutation(string s1, string s2)
{
    unordered_map<char,int> char_map;
    for(int i = 0; i < (int)s1.length(); i++)
        char_map[s1[i]]++;
    for(int i = 0; i < (int)s2.length(); i++)
        char_map[s2[i]]--;
    for(auto character : char_map)
    {
        if(character.second != 0) return false;
    }
    
    return true;
}

int main() {
    string s1 = "leetcode";
    string s2 = "edocteel";
    
    if(is_permutation(s1,s2)) cout << "Is permutation!";
    else cout << "Not permutation";
}