//
// Created by leelddd on 8/2/2018.
//

#ifndef LEETCODE_ALG_H
#define LEETCODE_ALG_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iterator>
#include <bits/stdc++.h>
#include <cmath>
#include <numeric>
#include <list>

using namespace std;

vector<int> mkv(vector<int> v) {
    return v;
}

vector<vector<int>> mkvv(vector<vector<int>> vv) {
    return vv;
}


template<typename T>
void print_container(const T &container) {
    std::copy(std::begin(container),
              std::end(container),
              std::ostream_iterator<typename T::value_type>(cout, " "));
    cout << endl;
}

template<typename T>
void print_container(const T &container, const char *spliter) {
    std::copy(std::begin(container),
              std::end(container),
              std::ostream_iterator<typename T::value_type>(cout, spliter));
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    // https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects
    bool operator<(const ListNode &node) const {
        return (val < node.val);
    }
};

// https://stackoverflow.com/questions/7446743/sorting-vector-of-pointers
bool compareListNode(ListNode *a, ListNode *b) { return (a->val < b->val); }


ListNode *mklst(vector<int> v) {
    ListNode *h = new ListNode(0);
    ListNode *p = h;
    for (int i: v) {
        p->next = new ListNode(i);
        p = p->next;
    }
    return h->next;
}

vector<ListNode *> mklsts(vector<vector<int>> vv) {
    vector<ListNode *> rt;
    for (auto v: vv) {
        rt.push_back(mklst(v));
    }
    return rt;
}

void printList(ListNode *l, string spliter = ", ") {
    while (l) {
        cout << l->val << spliter;
        l = l->next;
    }
    cout << endl;
}

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_tree(TreeNode *node) {
    if (!node) return;
    cout << "[";
    queue<TreeNode *> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode *node = q.front();
        cout << (node ? to_string(node->val) : "null") << ",";
        if (node && (node->left || node->right)) {
            q.push(node->left);
            q.push(node->right);
        }
        q.pop();
    }
    cout << "]," << endl;
}

#endif //LEETCODE_ALG_H
