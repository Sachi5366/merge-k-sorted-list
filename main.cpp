#include <bits/stdc++.h>
using namespace std;

/*  Node structure for Linked List */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Custom comparator for priority queue */
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap based on node value
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

    // Push the first node of each list into min-heap
    for (auto node : lists) {
        if (node != nullptr)
            pq.push(node);
    }

    // Dummy head for final merged list
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    // Extract minimum and add the next element of that list
    while (!pq.empty()) {
        ListNode* smallest = pq.top();
        pq.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next)
            pq.push(smallest->next);
    }

    return dummy->next;
}

/* Utility Function to print Linked List */
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

/* ------- MAIN DRIVER CODE ------- */
int main() {
    int k;
    cout << "Enter number of sorted lists: ";
    cin >> k;

    vector<ListNode*> lists(k);

    for (int i = 0; i < k; i++) {
        int n;
        cout << "\nEnter number of elements in list " << i + 1 << ": ";
        cin >> n;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        cout << "Enter sorted elements: ";
        while (n--) {
            int x;
            cin >> x;
            ListNode* newNode = new ListNode(x);

            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        lists[i] = head;
    }

    cout << "\nMerged Sorted List:\n";
    ListNode* result = mergeKLists(lists);
    printList(result);

    return 0;
}
