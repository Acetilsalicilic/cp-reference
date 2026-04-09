#include <bits/stdc++.h>
using namespace std;

struct Node {
    // All default values so they create
    // the identity element. Initial value
    // should represent the identity, as well
    // as the other lazy fields
    int value = 0;

    bool lazy_sum_flag = false;
    bool lazy_set_flag = false;

    int lazy_sum_value = 0;
    int lazy_set_value = 0;

    // "Combine" operator. Can be defined
    // as needed by the problem.
    Node operator+ (const Node& a) {
        // We build a new instance that combines
        // two nodes
        return {
            .value = this->value + a.value
        };
    }
};

// This function is the heart of lazy prop
// Allows to flush or push the delayed updates
// stored in the parent to the children, so
// we're one step closer to updating the
// leaf nodes
void push(
        Node& parent, 
        Node& left_child, 
        int left_tl,
        int left_tr,
        Node& right_child,
        int right_tl,
        int right_tr
        ) {
    // If parent doesn't have pending updates, 
    // then we do nothing
    if (parent.lazy_sum_flag) {
        left_child.lazy_sum_flag = true;
        // This operation must combine with any
        // possible previously added values. If
        // it overrides it, then we lose it. As this
        // is a sum, it must be summed
        left_child.lazy_sum_value += 
            parent.lazy_sum_value;
        // We must also update the values of the
        // children, not only add to their
        // delayed operations
        left_child.value += 
            (left_tr - left_tl + 1) * parent.lazy_sum_value;

        right_child.lazy_sum_flag = true;
        right_child.lazy_sum_value +=
            parent.lazy_sum_value;
        right_child.value +=
            (right_tr - left_tl + 1) * parent.lazy_sum_value;

        // As we've pushed the pending update, the
        // parent doesn't need to store it as
        // pending. It already passed it to it's
        // children.
        parent.lazy_sum_flag = false;
        parent.lazy_sum_value = 0;
    }

    if (parent.lazy_set_flag) {
        left_child.lazy_set_flag = true;
        // This overrides, cause it's the nature
        // of the type of query
        left_child.lazy_set_value =
            parent.lazy_set_value;
        left_child.value =
            (left_tr - left_tl + 1) * parent.lazy_set_value;

        right_child.lazy_set_flag = true;
        right_child.lazy_set_value =
            parent.lazy_set_value;
        right_child.value =
            (right_tr - right_tl + 1) * parent.lazy_set_value;

        parent.lazy_set_flag = false;
        parent.lazy_set_value = 0;
    }
}

int n, N;
vector<Node> tree;
vector<int> a;

