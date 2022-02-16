//
// Created by 马鸿英 on 2022/2/16.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace  std;

class Boxer{
public:
    string name;
    int strLength;
};

struct Comp{
    bool operator()(const Boxer & a, const Boxer &b) const{
        return a.strLength > b.strLength;
    }
};


int main(){
    Boxer boxer[3];
    boxer[0].name = "uday", boxer[0].strLength = 23;
    boxer[1].name = "manoj", boxer[1].strLength = 33;
    boxer[2].name = "rajiv", boxer[2].strLength = 53;
    priority_queue<Boxer, vector<Boxer>, Comp> pq;
    for(const auto & item : boxer){
        pq.push(item);
    }
    while (!pq.empty()){
        cout<<pq.top().strLength<<'\t';
        pq.pop();
    }
}