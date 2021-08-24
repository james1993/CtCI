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
Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. 
*/
ListNode* partition(ListNode* head, int partition_value)
{
    ListNode* less = head;
    ListNode* more = head;
    ListNode* new_head = less->val >= partition_value ? more : less;
    
    while(less->val >= partition_value)
        less = less->next;
    while(more->val < partition_value)
        more = more->next;
    
    ListNode* more_head = more;
    
    while(less && less->next)
    {
        if(less->next->val >= partition_value) less->next = less->next->next;
        else less = less->next;
    }
    while(more && more->next)
    {
        if(more->next->val < partition_value) more->next = more->next->next;
        else more = more->next;
    }
    
    less->next = more_head;
    return new_head;
}

int main() {
    string line;
    ListNode* head = NULL;
    while (getline(cin, line)) {
        head = stringToListNode(line);
        prettyPrintLinkedList(head);
    }
    ListNode* new_head = partition(head,5);
    prettyPrintLinkedList(new_head);
    return 0;
}