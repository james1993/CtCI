// Example program
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient
space at the end to hold the additional characters, and that you are given the "true" length of the string.
*/

//O(n) time, O(1) space. insert in place, starting from end of string.
void URLify(string& s, int ptr)
{
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(s[ptr] != ' ') 
            s[i] = s[ptr--];
        else
        {
            s[i--] = '0';
            s[i--] = '2';
            s[i] = '%';
            ptr--;
        }
    }
}

int main() {
    string s = "Mr John Smith    ";
    URLify(s, 12);
    cout << s;
}