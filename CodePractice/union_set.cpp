//
// Created by 马鸿英 on 2022/2/17.
//

#include <iostream>
using namespace std;

class UnionSet{
private:
    int size;
    int *parent;
public:
    UnionSet(int size):size(size){
        parent = new int [this->size];
        for(int i=0;i<size; i++)
            parent[i] = -1;
    }
    int Find(int x){
        //找的同时，实现路径压缩
        if(parent[x] < 0) return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int root1, int root2){
        //按照规模进行合并,将规模小的归并到规模大的树上面;
        if(root1 == root2) return;
        if(parent[root1] < parent[root2]){
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }else{
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
    }
    ~UnionSet(){
        delete []  parent;
    }
};


int main(){
    UnionSet set(7);
    set.Union(0, 2);
    set.Union(1,2);
    set.Union(2, 3);

    set.Union(4, 5);
    set.Union(5, 6);
    for(int i=0;i<4;i++)
        cout<<set.Find(i)<<"\t";

    cout<<set.Find(4)<<"\t";
    cout<<set.Find(5)<<"\t";
    cout<<set.Find(6)<<"\t";






}