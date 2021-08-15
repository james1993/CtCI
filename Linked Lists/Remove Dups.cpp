#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

/*
Write code to remove duplicates from an unsorted linked list.
How would you solve this problem if a temporary buffer is not allowed?
*/

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

//O(n) time, O(n) space- put elements in set and check before adding
//If set not allowed, iterate through entire list at each element, checking for duplicates and removing- O(n^2) time, O(1) space
ListNode* remove_duplicates(ListNode* head)
{
    unordered_set<int> set;
    set.insert(head->val);
    ListNode* dummy = head;
    
    while(head && head->next)
    {
        if(set.find(head->next->val) == set.end()) set.insert(head->next->val);
        else 
        {
            ListNode* dup = head->next;
            head->next = head->next->next;
            delete(dup);
        }
        head = head->next;
    }
    return dummy;
}

int main() {
    return 0;
}