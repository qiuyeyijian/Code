#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyed 判圈法
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;

    do {
      if (!fast || !fast->next) return nullptr;
      fast = fast->next->next;
      slow = slow->next;
    } while (fast != slow);

    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }

    return fast;
  }
};