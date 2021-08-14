// Example program
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Given two strings, write a function to check if they are one edit away.
*/

//O(n) time, O(1) space- iterate through both strings. if mismatch found, test all 3 possibilities for equality
bool equal(string& s0, int i, string& s1, int j) {
    while (i < (int)s0.size() && j < (int)s1.size() && s0[i] == s1[j]) {
        i++, j++;
    }
    return i == (int)s0.size() && j == (int)s1.size();
}

bool one_away(string s0, string s1) {
    for (int i = 0; i < min((int)s0.size(), (int)s1.size()); i++) {
        if (s0[i] != s1[i])
            return equal(s0, i + 1, s1, i) || equal(s0, i, s1, i + 1) || equal(s0, i + 1, s1, i + 1);
    }
    return true;
}

int main() {
    string s1 = "pale"; string s2 = "ple";
    string s3 = "pales"; string s4 = "pale";
    string s5 = "pale"; string s6 = "bale";
    string s7 = "pale"; string s8 = "bake";
    
    if(one_away(s1,s2)) cout << "Yes\n";
    else cout << "No\n";
    if(one_away(s3,s4)) cout << "Yes\n";
    else cout << "No\n";
    if(one_away(s5,s6)) cout << "Yes\n";
    else cout << "No\n";
    if(one_away(s7,s8)) cout << "Yes\n";
    else cout << "No\n";
}