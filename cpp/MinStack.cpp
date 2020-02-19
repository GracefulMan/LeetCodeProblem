//
// Created by 马鸿英 on 2019-03-23.
//

#include <iostream>
using namespace std;

class MinStack {
private:
    struct node{
        int val;
        node *next;
        node(int val,node *n=NULL):val(val),next(n){};
        node():next(NULL){};
    };
    node *head;

public:
    /** initialize your data structure here. */
    MinStack(){
        head = new node();
    }

    void push(int x) {
        node *tmp = new node(x,head->next);
        head->next = tmp;
    }
    void pop() {
        node *tmp = head->next;
        head->next = tmp->next;
        delete tmp;
    }

    int top() {
        return head->next->val;
    }

    int getMin() {
        int min=head->next->val;
        node *p = head->next;
        while(p){
            if(p->val<min)min=p->val;
            p=p->next;
        }
        return min;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */