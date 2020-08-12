/* You are given two non-empty linked lists representing two non-negative integers.
* The digits are stored in reverse order and each of their nodes contain a single
* digit. Add the two numbers and return it as a linked list.
*
* You may assume the two numbers do not contain any leading zero, except the number
* 0 itself.
*
* Example
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var dummy = ListNode{0, nil}
    temp := &dummy
    carry := 0
    for l1 != nil || l2 != nil || carry != 0 {
        value := carry
        if l1 != nil {
            value += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            value += l2.Val
            l2 = l2.Next
        }
        carry = value / 10
        temp.Next = new(ListNode)
        temp = temp.Next
        temp.Val = value % 10
    }
    return dummy.Next
}
