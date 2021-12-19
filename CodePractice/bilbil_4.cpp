#include <iostream>
using namespace  std;
template<class T>
class Node {
public:
    T val;
    Node *next;
    Node(T val, Node<T> *next= nullptr):val(val), next(next){}
};
template<class T>
Node<T> *reverseLinkNodeByIteration(Node<T> *head) {
    //迭代反转法，head 为无头节点链表的头指针
    if(head == nullptr || head->next == nullptr)
        return head;
    Node<T> *beg = nullptr;
    Node<T> *mid = head;
    Node<T> *end = head->next;
    while (true){
        mid->next = beg;
        if(end == nullptr) break;
        beg = mid;
        mid = end;
        end = end->next;
    }
    head = mid;
    return head;
}

template<class T>
Node<T> *reverseLinkNodeByInsertMethod(Node<T> *head){
    Node<T>*new_head= nullptr;
    Node<T> *p= nullptr;
    if(head == nullptr || head->next== nullptr)
        return head;
    while (head!=nullptr){
        p = head;
        head = head->next;
        p->next = new_head;
        new_head = p;
    }
    return new_head;
}

template<class T>
Node<T> *reverseLinkNodeLocal(Node<T>*head){
    Node<T> *beg = head;
    Node<T>*end = head->next;
    while (end){
        beg->next = end->next;
        end->next = head;
        head = end;
        end = beg->next;
    }
    return head;
}

template<class T>
Node<T> *createNodeListByList(T *data, int n){
    Node<T> *head = new Node<T>(data[0]);
    Node<T> *p = head;
    for(int i=1;i<n;i++){
        Node<T> * tmp = new Node<T>(data[i]);
        p->next = tmp;
        p = p->next;
    }
    return head;
}

template<class T>
Node<T> printNodeList(Node<T>*head){
    Node<T>*p = head;
    while (p) {
        cout << p->val << '\t';
        p = p->next;

    }
    cout<<endl;
}
int main(){
    //test Node
    int data[] = {1, 2, 3, 4, 5, 6};
    Node<int> *head = createNodeListByList(data, 6);
    printNodeList(head);
//    head = reverseLinkNodeByIteration(head);
//    head = reverseLinkNodeByInsertMethod(head);
    head = reverseLinkNodeLocal(head);
    printNodeList(head);



}