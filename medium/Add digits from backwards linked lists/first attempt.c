/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int countListLength(struct ListNode* linkedListNode){
    int length = 1;
    while(linkedListNode->next){
        length++;
        linkedListNode = linkedListNode->next;
    }
    return length;
}

struct ListNode* addTwoNumbersOrdered(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* il1 = l1;
    struct ListNode* il2 = l2;
    struct ListNode* prevIL1 = NULL;
    int carry = 0;
    int lastDigit;
    do{
        //printf("starting digits: %d, %d, ", il1->val, il2->val);

        il1->val = il1->val + il2->val + carry;
        lastDigit = il1->val;
        
        carry = 0;
        if(il1->val > 9){
            carry = 1;
            il1->val -= 10;
            lastDigit = il1->val;
        }
        //printf("sum: %d, ", il1->val);
        //printf("carry? %d\n", carry);

        if(il1->next){
            il1 = il1->next;
        }else{
            break;
        }

        il2->val = 0;
        if(il2->next){
            il2 = il2->next;
        }
    }while(il1->val > -1);

    if(carry == 1){
        //printf("adding MSD\n");
        struct ListNode* MSD = malloc(sizeof(struct ListNode));
        il1->next = MSD;
        MSD->val = 1;
        MSD->next = NULL;
    }
    return l1;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){    
    struct ListNode* returnValue;
    if(countListLength(l1) > countListLength(l2)){
        return addTwoNumbersOrdered(l1, l2);
    }else{
        return addTwoNumbersOrdered(l2, l1);
    }
}