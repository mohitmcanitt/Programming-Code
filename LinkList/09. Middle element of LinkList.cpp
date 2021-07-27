/*
Approach 1 (using two traversal) 
  (i) Find the length of linked list.
  (ii) iterate Loop from 1 to length/2;   i<=length/2

Approach : 2 Using Runner Technique / Single Traversal
  (i) we declare two pointers
  Slow = head;
  fast = head;
  Slow speed 1 Jump
  Fast pointer will jump 2.
  in each iteration.

  if fast, will encounter nULL value, which means fast pointer has reached end.
  Slow will cover, only half of the length of total length, bcoz It was running half of speed of fant

  Slow pointer will be the middle element.
  */
// input : [1,2,3,4,5,6]
// Output : 4
// input :[1,2,3,4,5]
// output : 3
ListNode* middleNode(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
