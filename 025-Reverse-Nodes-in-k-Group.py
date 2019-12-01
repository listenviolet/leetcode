class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def reverseKGroup(head: ListNode, k: int) -> ListNode:
    prev = head
    root = head
    
    if head is None: return root
    
    i = 1
    cur = prev
    while i < k:
        if cur is None: return root
        cur = cur.next
        i +=1 
    root = cur
    
    print('new_root.val = ', root.val)

    phead = cur.next
    
    while True:
        # reverse the k group
        while prev != phead:
            p2 = prev.next
            prev.next = phead
            phead = prev
            prev = p2
        cur = prev
        i = 1
        while i < k:
            if cur is None: return root
            cur = cur.next
        prev = phead
        phead = cur.next
        prev = c


node1 = ListNode(1)
node2 = ListNode(2)

node3 = ListNode(3)
node4 = ListNode(4)
node5 = ListNode(5)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5

new_root = reverseKGroup(node1, 3)
cur = new_root
while cur is not None:
    print(cur.val)
    cur = cur.next