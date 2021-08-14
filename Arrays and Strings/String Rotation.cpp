#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1.
*/

//O(n) time, O(1) space- append s2 to itself then check for s1.
bool is_rotation(string s1, string s2)
{
    s2 += s2;
    return s2.find(s1) != string::npos;
}
int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    if(is_rotation(s1,s2)) cout << "Yes\n";
    else cout << "No\n";
    
    s1 = "waterbottle";
    s2 = "waterbottel";
    
    if(is_rotation(s1,s2)) cout << "Yes\n";
    else cout << "No\n";
}