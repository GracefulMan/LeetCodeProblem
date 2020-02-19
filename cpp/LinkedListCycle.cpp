//
// Created by 马鸿英 on 2019/3/5.
//
#include <iostream>
#include <set>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head){
    if(!head) return false;
    ListNode *p,*move;
    p=move = head;
    while(move&&p){
        if(!move->next) return false;
        if(!move->next->next) return false;
        move=move->next->next;
        p=p->next;
        if(p==move) return true;
    }
    return false;
}
