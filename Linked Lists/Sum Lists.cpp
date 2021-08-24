/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(ListNode* node) {
  while (node && node->next) {
      cout << node->val << "->";
      node = node->next;
  }

  if (node) {
    cout << node->val << endl;
  } else {
    cout << "Empty LinkedList" << endl;
  }
}
/*
You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order. Write a function that adds the two numbers 
and returns the sum as a linked list.
*/
ListNode* sum_lists(ListNode* head1, ListNode* head2)
{
    int carry = 0;
    ListNode* dummy = head1;
    while(head1 && head2)
    {
        int sum = head1->val + head2->val + carry;
        if(sum < 10)
        {
            head1->val = sum;
            carry = 0;
        }
        else
        {
            head1->val = sum%10;
            carry = 1;
        }
        if(!head1->next) 
        {
            head1->next = head2->next;
            head1 = head1->next;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head2)
    {
        head1 = head2;
        head1->val = head2->val + carry;
        carry = 0;
        head2 = head2->next;
        head1 = head1->next;
    }
    while(head1)
    {
        head1->val += carry;
        carry = 0;
        head1 = head1->next;
    }
    if(carry == 1) head1->next = new ListNode(carry);
    
    return dummy;
}

int main() {
    string line;
    ListNode* head = NULL;

    ListNode* head1 = stringToListNode("[7,1,6]");
    ListNode* head2 = stringToListNode("[5,9,2,1]");
    ListNode* sum_head = sum_lists(head1, head2);
    
    prettyPrintLinkedList(sum_head);
    return 0;
}