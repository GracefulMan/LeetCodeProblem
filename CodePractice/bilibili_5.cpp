//
// Created by 马鸿英 on 2021/12/30.
//

// binary tree
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template<class T>
struct Node{
    T val;
    Node *left;
    Node *right;
    Node(T val, Node<T> *left= nullptr, Node<T>*right=nullptr):val(val), left(left),right(right){}
};


template<class T>
void preOrderRecur( Node<T> *tree){
    if(!tree) return ;
    cout<<tree->val<<'\t';
    preOrderRecur(tree->left);
    preOrderRecur(tree->right);
}

template<class T>
void preOrderIter(Node<T> * root){
    stack<Node<T>*> tmp;
    Node<T> *current;
    tmp.push(root);
    while (!tmp.empty()){
        current = tmp.top();
        tmp.pop();
        cout<<current->val<<"\t";
        if(current->right) tmp.push(current->right);
        if(current->left) tmp.push(current->left);
    }
}



template<class T>
void inOrderRecur(Node<T> *tree){
    if(!tree) return ;
    inOrderRecur(tree->left);
    cout<<tree->val<<"\t";
    inOrderRecur(tree->right);
}

template<class T>
void inOrderIter(Node<T>*root){
    stack<Node<T> *>tmp_stack;
    Node<T> * current=root;
    while (current || !tmp_stack.empty()){
        if(current){
            tmp_stack.push(current);
            current = current->left;
        }else{
            current = tmp_stack.top();
            tmp_stack.pop();
            cout<<current->val<<"\t";
            current = current->right;
        }

    }
}





template<class T>
void postOrdRecur(Node<T> *tree){
    if(!tree) return ;
    postOrdRecur(tree->left);
    postOrdRecur(tree->right);
    cout<<tree->val<<"\t";
}

template<class T>
void postOrdIter(Node<T> *root){
    stack<Node<T> *>first;
    stack<Node<T> *>second;
    Node<T> *current;
    first.push(root);
    while (!first.empty()){
        current = first.top();
        first.pop();
        second.push(current);
        if(current->left) first.push(current->left);
        if(current->right) first.push(current->right);
    }
    while (!second.empty()){
        current = second.top();
        second.pop();
        cout<<current->val<<"\t";
    }
}



//层次遍历
template<class T>
void tranverse(Node<T> *tree){
    queue<Node<T> *> myQueue;
    myQueue.push(tree);
    Node<T> *current;
    while (!myQueue.empty()){
        current = myQueue.front();
        myQueue.pop();
        cout<<current->val<<"\t";
        if(current->left) myQueue.push(current->left);
        if(current->right) myQueue.push(current->right);
    }
}

//统计最大宽度
template <class T>
int maxWidth(Node<T>* root){
    if(!root) return 0;
    queue<Node<T> *> tmp_queue;
    unordered_map<Node<T>*, int> level_map;
    Node<T> *current;
    int current_level = 1;
    int current_level_nodes = 0;
    int maxWidthNodesNums =0;
    level_map[root] = 1;
    tmp_queue.push(root);
    while (!tmp_queue.empty()){
        current = tmp_queue.front();
        tmp_queue.pop();
        int level = level_map[current];
        if(level==current_level){
            current_level_nodes++;
        } else{
            maxWidthNodesNums = maxWidthNodesNums > current_level_nodes ? maxWidthNodesNums : current_level_nodes;
            current_level++;
            current_level_nodes = 1;
        }
        if(current->left){
            level_map[current->left] = current_level + 1;
            tmp_queue.push(current->left);
        }
        if(current->right){
            level_map[current->right] = current_level + 1;
            tmp_queue.push(current->right);
        }
    }
    maxWidthNodesNums = maxWidthNodesNums > current_level_nodes ? maxWidthNodesNums : current_level_nodes;
    return maxWidthNodesNums;
}


template<class T>
bool isBinarySearchTree(Node<T> *root){
    if(!root) return true;
    static int preValue = INT32_MIN;
    bool isLeftBST = isBinarySearchTree(root->left);
    if(!isLeftBST) return false;
    if(root->val <= preValue) return false;
    else preValue = root->val;
    return isBinarySearchTree(root->right);
}

template<class T>
bool isBinarySearchTree2(Node<T> *root){
    vector<Node<T>*> list;
    inOrderInsert(root, list);
    for(int i=1;i<list.size();i++){
        if(list[i-1]->val >= list[i]->val) return false;
    }
    return true;
}

template<class T>
void inOrderInsert(Node<T> *root, vector<Node<T>*> list){
    if(!root) return ;
    inOrderRecur(root->left);
    list.push_back(root);
    inOrderRecur(root->right);
}

template<class T>
bool isBinarySearchTree3(Node<T> *root){
    if(!root) return true;
    stack<Node<T>*> tmp_stack;
    Node<T> *current = root;
    int preValue = INT32_MIN;
    while (current || !tmp_stack.empty()){
        if(current){
            tmp_stack.push(current);
            current = current->left;
        }else{
            current = tmp_stack.top();
            tmp_stack.pop();
            if(current->val <= preValue) return false;
            else preValue = current->val;
            current = current->right;
        }
    }
    return true;
}

template<class T>
bool isBinarySearchTree4(Node<T> *root){
    return isBinarySearchTreeNew(root).isBST;
}

struct BSTStruct{
        bool isBST;
        int max_val;
        int min_val;
        BSTStruct(bool isBST,int min_val=INT32_MAX,int max_val=INT32_MIN):isBST(isBST), min_val(min_val),max_val(max_val){}
    };

template<class T>
BSTStruct isBinarySearchTreeNew(Node<T> *root){
    if(!root) return BSTStruct(true);
    BSTStruct left = isBinarySearchTreeNew(root->left);
    BSTStruct right = isBinarySearchTreeNew(root->right);
    if(!left.isBST || !right.isBST) return BSTStruct(false);
    if(root->val <= left.max_val) return BSTStruct(false);
    if(root->val >= right.min_val) return BSTStruct(false);
    int max_val = max(max(left.max_val, right.max_val), root->val);
    int min_val = min(min(left.min_val, right.min_val), root->val);
    return BSTStruct(true, min_val, max_val);
}

template<class T>
bool isCompleteBinaryTree(Node<T> *root){
    if(!root) return true;
    queue<Node<T>*> my_queue;
    my_queue.push(root);
    Node<T> *current;
    bool isLeaf = false;
    while (!my_queue.empty()){
        current = my_queue.front();
        my_queue.pop();
        if(current->right && !current->left) return false;
        if(isLeaf && (current->left || current->right)) return false;
        if(current->left) my_queue.push(current->left);
        if(current->right) my_queue.push(current->right);
        if(!current->left || !current->right) isLeaf = true;
    }
    return true;
}

template<class T>
bool isBalanceTree(Node<T>*root){
    return isBalance(root).isBalance;
}

struct NewType {
        int height;
        bool isBalance;
        NewType(int height, bool isBalance):height(height), isBalance(isBalance){}
    };
template <class T>
NewType isBalance(Node<T> *root){
    if(!root) return NewType(0, true);
    NewType left =isBalance(root->left);
    NewType right = isBalance(root->right);
    bool balance = left.isBalance && right.isBalance && (abs(left.height - right.height)<=1);
    int height = max(left.height, right.height) + 1;
    return NewType(height, balance);
}

struct NodeAndHeightStruct{
    int nodes;
    int heights;
    NodeAndHeightStruct(int nodes, int heights):nodes(nodes), heights(heights){}
};

template<class T>
bool isFullBinaryTree(Node<T> *root){
    if(!root) return true;
    NodeAndHeightStruct res = isFullBinaryTreeSub(root);
    int nodes = res.nodes;
    int heights = res.heights;
    // nodes == 2^height - 1
    return nodes == ((1 << heights)-1);
}


template<class T>
NodeAndHeightStruct isFullBinaryTreeSub(Node<T> *root){
    if(!root) return NodeAndHeightStruct(0, 0);
    NodeAndHeightStruct left = isFullBinaryTreeSub(root->left);
    NodeAndHeightStruct right = isFullBinaryTreeSub(root->right);
    int nodes = left.nodes + right.nodes + 1;
    int heights = max(left.heights, right.heights) + 1;
    return NodeAndHeightStruct(nodes, heights);
}


template<class T>
Node<T> * getCommonAncestor(Node<T> *root, Node<T> *node1, Node<T> *node2){
    unordered_map<Node<T> *, Node<T> *> fatherMap;
    fatherMap[root] = root;
    commonAncestorProcess(root, fatherMap);
    unordered_set<Node<T> *> n1;
    while (fatherMap[node1] != root){
        n1.insert(node1);
        node1 = fatherMap[node1];
    }
    n1.insert(node1);

    while (n1.find(node2) == n1.end()){
        node2 = fatherMap[node2];
    }
    return node2;
}

template<class T>
void commonAncestorProcess(Node<T> *root, unordered_map<Node<T>*, Node<T>*>& map){
    if(!root) return;
    map[root->left] = root;
    map[root->right] = root;
    commonAncestorProcess(root->left, map);
    commonAncestorProcess(root->right, map);
}

template<class T>
Node<T> * getCommonAncestor2(Node<T> *root, Node<T> *node1, Node<T> *node2){
    if(root == nullptr||root == node1 || root == node2) return root;
    Node<T> *leftCommon = getCommonAncestor2(root->left, node1, node2); //向左边要答案
    Node<T> *rightConmon = getCommonAncestor2(root->right, node1, node2);
    if(leftCommon!= nullptr && rightConmon!= nullptr) return root;
    return leftCommon ? leftCommon : rightConmon;
}


struct NewNode{
        int val;
        NewNode *left;
        NewNode *right;
        NewNode *parent;
        NewNode(int val, NewNode * left= nullptr, NewNode *right= nullptr, NewNode *parent= nullptr):val(val), left(left), right(right),parent(parent){}
};

NewNode *getSuccessorNode(NewNode *node){
    if(!node) return nullptr;
    if(node->right) {
        node = node->right;
        while(node->left) node = node->left;
        return node;
    } else{
        NewNode *parent = node->parent;
        while (parent && parent->left != node){
            node = parent;
            parent = node->parent;
        }
        return parent;
    }
}

template<class T>
string serialByPre(Node<T> *root){
    //根左右
    if(!root) return "#_";
    string res = to_string(root->val) +"_";
    res += serialByPre(root->left);
    res += serialByPre(root->right);
    return res;
}

void split(const string &s, vector<string> &tokens, const string & delimiters=" "){
    string::size_type lastPos = s.find_first_not_of(delimiters, 0);
    string::size_type pos = s.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos){
        tokens.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}


template<class T>
Node<T> *reconPreOrder(queue<string> &tmpQueue){
    string val = tmpQueue.front();
    tmpQueue.pop();
    if(val == "#") return nullptr;
    Node<T>* head = new Node<T> (atoi(val.c_str()));
    head->left = reconPreOrder<T>(tmpQueue);
    head->right = reconPreOrder<T>(tmpQueue);
    return head;
}

template<class T>
Node<T>* reconByPreString(string preStr){
    vector<string> values;
    split(preStr, values, "_");
    queue<string> tmpQueue;
    for(auto s: values) tmpQueue.push(s);
    Node<T>*res = reconPreOrder<T>(tmpQueue);
    return res;
}

template<class T>
bool saveTree(Node<T> *root1, Node<T> *root2){
    if(!root1 && root2 || root1 && !root2) return false;
    if(!root1 && !root2) return true;
    if(root1->val != root2->val) return false;
    return saveTree(root1->left, root2->left) && saveTree(root1->right, root2->right);
}

void printProcess(int i, int N, bool down){
    if(i > N) return;
    printProcess(i+1, N, true);
    cout<<(down ? "凹":"凸")<<"\t";
    printProcess(i+1, N, false);
 }


void printAllFolds(int N){
    printProcess(1, N, true);
}



int main(){
    auto *tree = new Node<int>(1);
    tree->left = new Node<int>(2);
    tree->right = new Node<int>(3);
    tree->left->left = new Node<int>(4);
    tree->left->right = new Node<int>(5);
    tree->right->left = new Node<int>(6);
    tree->right->right = new Node<int>(7);
    cout<<"preOrder："<<endl;
    preOrderIter(tree);
    cout<<"\ninOrder:"<<endl;
    inOrderIter(tree);
    cout<<"\npostOrder:"<<endl;
    postOrdIter(tree);
    cout<<"\ntranverse:"<<endl;
    tranverse(tree);
    cout<<"\nMax Width:"<<endl;
    cout<<maxWidth(tree)<<endl;

    auto *root = new Node<int>(7);
    root->left  = new Node<int>(4);
    root->left->left = new Node<int>(1);
    root->left->right = new Node<int>(5);
    root->right = new Node<int> (9);
    root->right->left = new Node<int>(8);
    root->right->right = new Node<int>(11);
    cout<<"\nIs Binary Search Tree"<<endl;
    cout<<isBinarySearchTree4(root)<<endl;

    cout<<"\nIs Complete Binary Tree"<<endl;
    cout<<isCompleteBinaryTree(root)<<endl;

    cout<<"\nIs balance binary tree"<<endl;
    cout<<isBalanceTree(root)<<endl;

    cout<<"\n Is full binary tree"<<endl;
    cout<<isFullBinaryTree(root)<<endl;

    cout<<"get Common ancestor"<<endl;
    cout<<getCommonAncestor(root, root->left->left, root->left->right)->val<<endl;

    // successor test
    NewNode *succ = new NewNode(1);
    succ->left = new NewNode(2);
    succ->left->parent = succ;
    succ->right = new NewNode(3);
    succ->right->parent = succ;
    succ->left->left = new NewNode(4);
    succ->left->left->parent = succ->left;
    succ->left->right = new NewNode(5);
    succ->left->right->parent = succ->left;
    succ->right->left = new NewNode(6);
    succ->right->left->parent= succ->right;
    succ->right->right = new NewNode(7);
    succ->right->right->parent = succ->right;
    cout<<"successor:"<<endl;
    cout<<getSuccessorNode(succ->right )->val<<endl;
    cout<<"serial by preorder"<<endl;
    string tmpStr = serialByPre(tree);
    cout<<tmpStr<<endl;
    cout<<"recover from string"<<endl;
    Node<int> *recoverTree = reconByPreString<int>(tmpStr);
    cout<<saveTree(tree, recoverTree)<<endl;
    cout<<"print all folds"<<endl;
    printAllFolds(2);
}
