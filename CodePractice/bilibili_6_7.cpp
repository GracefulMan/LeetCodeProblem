//
// Created by 马鸿英 on 2022/2/3.
//
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Edge;
struct Node{
    int val;
    int in;
    int out;
    std::vector<Node> nexts;
    std::vector<Edge> edges;
    Node(){};
    Node(int val):val(val),in(0), out(0){}
    bool operator==(const Node &other) const{
        return other.val == val;
    }
    Node(const Node &p){
        val = p.val;
        in = p.in;
        out = p.out;
        nexts = p.nexts;
        edges = p.edges;
    }
};

namespace std {
    template<>
    struct hash<Node> {
        inline size_t operator()(const Node &node) const {
            std::hash<std::string> hash;
            return hash(to_string(node.val));
        }
    };
}

struct Edge{
    int weight;
    Node from;
    Node to;
    Edge(int weight, Node from, Node to):weight(weight), from(from), to(to) {};
    bool operator==(const Edge & other) const {
        return weight == other.weight && from == other.from && to == other.to;
    }
};
/*
std::unordered_set is defined within std namespace.
 And it uses std::hash structures to hash many different types.
 If you want to be able to use std::unordered_set<X>
 (without adding much info to the declaration),
 you must create another overload of the std::hash template, so as to make it hash your structure.
 * */
namespace std {
    template<>
    struct hash<Edge> {
        inline size_t operator()(const Edge &edge) const {
            std::hash<std::string> hash;
            return hash(std::to_string(edge.weight) + std::to_string(edge.from.val) + std::to_string(edge.to.val));
        }
    };
}

struct Graph{
    unordered_map<int, Node> nodes;
    unordered_set<Edge> edges;
};


Graph createGraph(int matrix[][3], int row, int column){
    // this function has some mistakes.
    //matrix i:[from ,to, weight], eg:[1, 2, 4], 1-->2, the weight is 4.
    Graph graph;
    for(int i=0; i < row; i++){
        int from = matrix[i][0];
        int to = matrix[i][1];
        int weight = matrix[i][2];
        //点集合没有这个点的话就把点加到点集合里；
        if(graph.nodes.find(from) == graph.nodes.end()){
            graph.nodes[from] = Node(from);
        }
        if(graph.nodes.find(to) == graph.nodes.end()){
            graph.nodes[to] = Node(to);
        }
        Node fromNode = graph.nodes[from];
        Node toNode = graph.nodes[to];
        Edge newEdge(weight, fromNode, toNode);
        fromNode.nexts.push_back(toNode);
        fromNode.out++;
        toNode.in++;
        fromNode.edges.push_back(newEdge);
        graph.edges.insert(newEdge);
    }
    return graph;
}

//宽度优先遍历
void bfs(Node node){
    queue<Node > q;
    unordered_set<Node> visited;
    q.push(node);
    visited.insert(node);
    Node current;
    while (!q.empty()){
        current = q.front();
        q.pop();
        cout<<current.val<<"\t";
        for(auto item : current.nexts){
            if(visited.find(item) == visited.end()){
                visited.insert(item);
                q.push(item);
            }
        }
    }
}
//深度优先遍历
void dfs(Node node){
    stack<Node> s;
    unordered_set<Node> visited;
    s.push(node);
    visited.insert(node);
    Node current;
    while (!s.empty()){
        current = s.top();
        s.pop();
        for(auto item : current.nexts){
            if(visited.find(item) == visited.end()){
                s.push(current);
                s.push(item);
                visited.insert(item);
                cout<<item.val<<"\t";
                break; // 比较精彩的部分
            }
        }
    }
}


int main(){
    int matrix[][3] = {{1, 2, 5}, {1, 3, 7}, {2, 3, 6},{1, 4, 10}, {3, 4, 11}};
    auto graph = createGraph(matrix, 5, 3);
    cout<<graph.nodes.size()<<endl;
    cout<<graph.edges.size()<<endl;
    auto node = graph.nodes[2];
    dfs(node);

}