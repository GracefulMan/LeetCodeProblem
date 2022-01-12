#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

template<class T>
struct Node {
    T val;
    Node *next;

    Node(T val, Node<T> *next = nullptr) : val(val), next(next) {}
};

template<class T>
Node<T> *reverseLinkNodeByIteration(Node<T> *head) {
    //迭代反转法，head 为无头节点链表的头指针
    if (head == nullptr || head->next == nullptr)
        return head;
    Node<T> *beg = nullptr;
    Node<T> *mid = head;
    Node<T> *end = head->next;
    while (true) {
        mid->next = beg;
        if (end == nullptr) break;
        beg = mid;
        mid = end;
        end = end->next;
    }
    head = mid;
    return head;
}

template<class T>
Node<T> *reverseLinkNodeByInsertMethod(Node<T> *head) {
    Node<T> *new_head = nullptr;
    Node<T> *p = nullptr;
    if (head == nullptr || head->next == nullptr)
        return head;
    while (head != nullptr) {
        p = head;
        head = head->next;
        p->next = new_head;
        new_head = p;
    }
    return new_head;
}

template<class T>
Node<T> *reverseLinkNodeLocal(Node<T> *head) {
    Node<T> *beg = head;
    Node<T> *end = head->next;
    while (end) {
        beg->next = end->next;
        end->next = head;
        head = end;
        end = beg->next;
    }
    return head;
}

template<class T>
Node<T> *createNodeListByList(T *data, int n) {
    Node<T> *head = new Node<T>(data[0]);
    Node<T> *p = head;
    for (int i = 1; i < n; i++) {
        Node<T> *tmp = new Node<T>(data[i], nullptr);
        p->next = tmp;
        p = p->next;
    }
    return head;
}

template<class T>
Node<T> printNodeList(Node<T> *head) {
    Node<T> *p = head;
    while (p) {
        cout << p->val << '\t';
        p = p->next;

    }
    cout << endl;
}

template<class T>
void printOrderListCommonPart(Node<T> *link1, Node<T> *link2) {
    Node<T> *p1 = link1;
    Node<T> *p2 = link2;
    while (p1 && p2) {
        if (p1->val == p2->val) {
            cout << p1->val << '\t';
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->val < p2->val)
            p1 = p1->next;
        else
            p2 = p2->next;
    }
}

template<class T>
void swap_val(Node<T> *node1, Node<T> *node2) {
    T tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;
}

template<class T>
Node<T> *sortLinkList(Node<T> *head) {
    // 值交换的排序
    Node<T> *p = head;
    while (p) {
        Node<T> *tmp = p->next;
        while (tmp != nullptr) {
            if (tmp->val < p->val) swap_val(p, tmp);
            tmp = tmp->next;
        }
        p = p->next;
    }
    return head;
}

template<class T>
bool isPalindromeWritten(Node<T> *head) {
    stack<T> myStack;
    Node<T> *p = head;
    while (p) {
        myStack.push(p->val);
        p = p->next;
    }
    p = head;
    while (p) {
        if (p->val != myStack.top()) return false;
        myStack.pop();
        p = p->next;
    }
    return true;
}


// four type of slow-fast pointers.

template<class T>
Node<T> *slowFast1(Node<T> *head) {
    //奇数长度返回中点， 偶数长度返回上中点
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;
    Node<T> *slow = head;
    Node<T> *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


template<class T>
Node<T> *slowFast3(Node<T> *head) {
    //奇数长度返回中点前一个，偶数长度返回上中点前一个
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return nullptr;
    Node<T> *slow = head;
    Node<T> *fast = head->next->next;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template<class T>
Node<T> *slowFast2(Node<T> *head) {
    // 奇数长度返回中点，偶数长度返回下中点
    if (head == nullptr) return nullptr;
    if (head->next == nullptr || head->next->next == nullptr)
        return head->next;
    Node<T> *slow = head;
    Node<T> *fast = head->next;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}

template<class T>
Node<T> *slowFast4(Node<T> *head) {
    //奇数长度返回中点前一个，偶数长度返回下中点前一个
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    if (head->next->next == nullptr)
        return head;
    Node<T> *slow = head;
    Node<T> *fast = head->next;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


template<class T>
bool isPalindromeInterview(Node<T> *head) {
    // 奇数返回中点，偶数返回上中点
    Node<T> *mid = slowFast1(head)->next;
    stack<T> tmpStack;
    while (mid) {
        tmpStack.push(mid->val);
        mid = mid->next;
    }
    Node<T> *p = head;
    while (!tmpStack.empty()) {
        T val = tmpStack.top();
        if (val != p->val) return false;
        tmpStack.pop();
        p = p->next;
    }
    return true;
}

template<class T>
void swap(T *data, int i, int j) {
    T tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

template<class T>
void partition(T *data, int n, T val) {
    int left_boarder = -1;
    int right_board = n;
    int idx = left_boarder + 1;
    while (idx < right_board) {
        if (data[idx] < val) {
            swap(data, idx, ++left_boarder);
            idx++;
        } else if (data[idx] > val) {
            swap(data, idx, --right_board);
        } else {
            idx++;
        }
    }
}

template<class T>
Node<T> *DutchFlagProb(Node<T> *head, T val) {
    //笔试做法，直接用一个数组处理.
    int num = 0;
    Node<T> *p = head;
    while (p) {
        p = p->next;
        num += 1;
    }
    T *data = new T[num];
    p = head;
    for (int i = 0; i < num; i++) {
        data[i] = p->val;
        p = p->next;
    }
    partition(data, num, val);
    p = head;
    for (int i = 0; i < num; i++) {
        p->val = data[i];
        p = p->next;
    }
    return head;
}


template<class T>
Node<T> *DutchFlagProbInterview(Node<T> *head, T val) {
    //用六个指针分别维护小于区域头和尾，等于区域头和尾，大于区域头和尾。
    Node<T> *sH = nullptr, *sT = nullptr;
    Node<T> *eH = nullptr, *eT = nullptr;
    Node<T> *bH = nullptr, *bT = nullptr;
    Node<T> *p = head;
    while (p) {
        if (p->val < val) {
            if (sH == nullptr) {
                sH = p;
                sT = p;
            } else {
                sT->next = p;
                sT = p;
            }
        } else if (p->val == val) {
            if (eH == nullptr) {
                eH = p;
                eT = p;
            } else {
                eT->next = p;
                eT = p;
            }
        } else {
            if (bH == nullptr) {
                bH = p;
                bT = p;
            } else {
                bT->next = p;
                bT = p;
            }
        }
        p = p->next;
    }
    bT->next = nullptr;
    if (sT != nullptr) {
        sT->next = eH;
        eT = eT == nullptr ? sT : eT;
    }
    if (eT != nullptr) {
        eT->next = bH;
    }
    return sH != nullptr ? sH : (eH != nullptr ? eH : bH);

}


template<class T>
struct RandomNode {
    T val;
    RandomNode<T> *next;
    RandomNode<T> *rand;

    RandomNode(const T val) : val(val) {}
};

template<class T>
RandomNode<T> *copyLinkNode(RandomNode<T> *head) {
    unordered_map<RandomNode<T> *, RandomNode<T> *> map;
    RandomNode<T> *p = head;
    while (p) {
        RandomNode<T> *tmp = new RandomNode<T>(p->val);
        map[p] = tmp;
        p = p->next;
    }
    p = head;
    while (p) {
        RandomNode<T> *org_key = p->next;
        RandomNode<T> *copy_key = map[org_key];
        copy_key->next = map[org_key->next];
        copy_key->rand = map[org_key->rand];
        p = p->next;
    }
    return map[head];
}


template<class T>
RandomNode<T> *copyLinkByNode2(RandomNode<T> *head) {
    RandomNode<T> * p = head;
    while (p){
        RandomNode<T> * tmp = new RandomNode<T>(p->val);
        tmp->next = p->next;
        p->next = tmp;
        p = p->next;
    }
    p = head;
    while (p){
        p->next->rand = p->rand->next;
        p = p->next;
    }
    RandomNode<T> *new_head = head->next, *p2 = new_head;
    p = head;
    while (p){
        p->next = p->next->next;
        p2->next = p2->next->next;
        p = p->next;
        p2 = p2->next;
    }
    return new_head;
}

int main() {
    //test Node
    int data[] = {1, 2, 3, 4, 5, 6};
    Node<int> *head = createNodeListByList(data, 6);
//    head = reverseLinkNodeByIteration(head);
//    head = reverseLinkNodeByInsertMethod(head);
    head = reverseLinkNodeLocal(head);
    // print the common part of link list.
    int data2[] = {4, 1, 2, 3, 4, 9, 8};
    Node<int> *head2 = createNodeListByList(data2, 7);
    head = sortLinkList(head);
    printNodeList(head);
    head2 = sortLinkList(head2);
    printNodeList(head2);
    printOrderListCommonPart(head, head2);

    int data3[] = {1, 2, 3, 4, 3, 2, 1};
    Node<int> *head3 = createNodeListByList(data3, 7);
    bool res = isPalindromeWritten(head3);
    bool res2 = isPalindromeInterview(head3);
    cout << endl;
    if (res2)
        cout << "is Palindrome" << endl;
    else
        cout << "isn't Palindrome" << endl;

    head3 = DutchFlagProbInterview(head3, 2);
    printNodeList(head3);


}

