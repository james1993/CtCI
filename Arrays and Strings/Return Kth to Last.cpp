#include <iostream>
#include <string>

using namespace std;

/*
Implement an algorithm to find the kth to last element of a singly linked list.
*/
struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//O(n) time, O(1) space- deduce node from total length of list
int get_kth_to_last(ListNode* head, int k)
{
    int length = 0;
    ListNode* dummy = head;
    while(head)
    {
        length++;
        head = head->next;
    }
    int node_location = max(0,length - k - 1);
    
    while(node_location--)
        dummy = dummy->next;
    return dummy->val;
}

int main() {
    return 0;
}