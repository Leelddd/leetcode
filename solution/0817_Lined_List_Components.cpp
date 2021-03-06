#include "alg.h"

// remove reference for easy to test
int numComponents(ListNode *head, vector<int> G) {
    unordered_set<int> subset(G.begin(), G.end());

    int cnt = 0;
    bool in_subset = false;
    while (head) {
        if (!subset.count(head->val)) {
            if (in_subset) cnt++;
            in_subset = false;
        } else if (subset.count(head->val)) {
            in_subset = true;
        }
        head = head->next;
    }
    if (in_subset)cnt++;
    return cnt;
}

// https://leetcode.com/problems/linked-list-components/discuss/123842/C%2B%2BJavaPython-Easy-and-Concise-Solution-with-Explanation
int numComponents(ListNode *head, vector<int> &G) {
    int cnt = 0;
    unordered_set<int> gset(G.begin(), G.end());
    while (head) {
        if (gset.count(head->val)
            && (!head->next || !gset.count(head->next->val)))
            cnt++;
        head = head->next;
    }
    return cnt;
}

int main() {
    cout << numComponents(mklst({0}), {0});
    cout << numComponents(mklst({0, 1, 2, 3}), {0});
    cout << numComponents(mklst({0, 1, 2, 3}), {0, 1, 3});
    cout << numComponents(mklst({0, 1, 2, 3, 4}), {0, 1, 3, 4});
}