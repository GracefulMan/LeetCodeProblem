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

void printList(vector<Node> data);

namespace std {
    template<>
    struct hash<Node> {
        inline size_t operator()(const Node &node) const {
            std::hash<int> hash;
            return hash(node.val);
        }
    };
}

struct Edge{
    int weight;
    Node from;
    Node to;
    Edge(int weight, Node from, Node to):weight(weight){
        this->from = from;
        this->to = to;
    };
    bool operator==(const Edge & other) const {
        return weight == other.weight && from == other.from && to == other.to;
    }
    bool operator<(const Edge &other) const {
        return this->weight < other.weight;
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
            return hash(to_string(edge.weight) + to_string(edge.from.val) + to_string(edge.to.val));
        }
    };
}

struct Graph{
    unordered_map<int, Node> nodes;
    unordered_set<Edge> edges;

    //以下自己随便乱实现的，方便调试;
    friend ostream & operator<<(ostream &os, const Graph &graph){
        os << "点信息："<<endl;
        for(auto item= graph.nodes.begin(); item != graph.nodes.end(); item ++){
            os << "节点：" << item->second.val<<"：指向:";
            for(auto node : item->second.nexts){
                cout<< node.val <<",";
            }
            os<<endl;
        }
        os << "边信息:"<<endl;
        for(auto item : graph.edges){
            os << item.from.val << "----"<<item.weight<<"---->"<< item.to.val<<endl;
        }
        return os;
    }
};


Graph createGraph(vector<vector<int>> matrix){
    // this function has some mistakes.
    //matrix i:[from ,to, weight], eg:[1, 2, 4], 1-->2, the weight is 4.
    Graph graph;
    for(int i=0; i < matrix.size(); i++){
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
        cout << fromNode.val << ": "<<fromNode.nexts.size()<<endl;
        printList(fromNode.nexts);
        cout << "-------------"<<endl;
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

vector<Node> sortedByTopology(Graph graph){
    unordered_map<Node, int> inMap;
    queue<Node> zeroInQueue;
    for(auto item = graph.nodes.begin(); item != graph.nodes.end(); item++){
        inMap[item->second] = item->second.in;
        if(item->second.in == 0)
            zeroInQueue.push(item->second);
    }
    Node current;
    vector<Node> res;
    while(!zeroInQueue.empty()){
        current = zeroInQueue.front();
        res.push_back(current);
        zeroInQueue.pop();
        for(auto item : current.nexts){
            inMap[item]--;
            if(inMap[item] == 0)
                zeroInQueue.push(item);
        }
    }
    return res;
}

void printList(vector<Node> data){
    for(auto item : data){
        cout<<item.val<<"\t";
    }
    cout<<endl;
}



// 最小生成树
class UnionSet{
private:
    unordered_map<Node, unordered_set<Node>> map;
public:
    UnionSet(const Graph &graph){
        for(const auto & node : graph.nodes){
            unordered_set<Node> set;
            set.insert(node.second);
            map[node.second] = set;
        }
    }
    bool isSameSet(const Node &from, const Node &to) const{
        auto & fromSet = map.at(from);
        auto & toSet = map.at(to);
        return fromSet == toSet;
    }
    void unionSet(Node from, Node to){
        auto & fromSet = map.at(from);
        auto & toSet = map.at(to);
        for(auto toNode : toSet){
            fromSet.insert(toNode);
            map[toNode] = fromSet;
        }
    }
};

struct Comp{
    bool operator()(const Edge &a, const Edge &b) const{
        return a.weight > b.weight; //这样重载之后，是从小到大的排序；
    }
};

unordered_set<Edge> MSTByKruska(const Graph & graph){
    priority_queue<Edge,vector<Edge>, Comp> q;
    UnionSet unionFind(graph);
    for(const auto& edge : graph.edges){
        q.push(edge);
    }
    unordered_set<Edge> result;
    while (!q.empty()){
        Edge edge = q.top();
        q.pop();
        if(!unionFind.isSameSet(edge.from, edge.to)){
            result.insert(edge);
            unionFind.unionSet(edge.from, edge.to);
        }
    }
    return result;
}

unordered_set<Edge> MSTByPrim(const Graph & graph){
    //这个实现的缺陷：可能将一条边多次加入q，但是不影响结果。即常数时间增加
    priority_queue<Edge, vector<Edge>, Comp>q;
    unordered_set<Edge> result;
    unordered_set<Node> set;
    for(auto item=graph.nodes.begin(); item != graph.nodes.end(); item++){
        //for 循环对于连通图没必要，但是对于森林（即有多个子图，每个子图内连通）有用；
        auto node = item->second;
        if (!(set.find(node) == set.end())){
            set.insert(node);
            for(auto tmp : node.edges){
                // 解锁这个点连接的所有边
                q.push(tmp);
            }
            while (!q.empty()){
                Edge edge = q.top(); //弹出最小的边
                q.pop();
                Node toNode = edge.to; //看是否是个新节点
                if(set.find(toNode) == set.end()){
                    //如果是新节点，则加入集合，同时将其连接的边也都加进去。
                    set.insert(toNode);
                    for(auto tmp : toNode.edges)
                        q.push(tmp);
                }
            }
        }
    }
    return result;
}

Node* getMinDistanceAndUnselectedNode(const unordered_map<Node*, int> &map, const unordered_set<Node*> &selected) {
    Node* minNode= nullptr;
    int minDistance = INT32_MAX;
    for(auto item=map.begin(); item != map.end(); item++){
        Node *node = item->first;
        int distance = item->second;
        if(selected.find(node) == selected.end() && distance < minDistance){
            minNode = node;
            minDistance = distance;
        }
    }
    return minNode;
}

unordered_map<Node*, int> dijkstra(Node* head){
    unordered_map<Node*, int> distanceMap;
    distanceMap[head] = 0;
    unordered_set<Node *> selectedNodes;
    Node* node = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
    while (node != nullptr){
        int distance = distanceMap[node];
        for(Edge edge : node->edges){
            Node toNode = edge.to;
            if(distanceMap.find(&toNode)==distanceMap.end()){
                distanceMap[&toNode] = distance + edge.weight;
            }
            distanceMap[&toNode] = min(distanceMap[&toNode], distance + edge.weight);
        }
        selectedNodes.insert(node);
        node = getMinDistanceAndUnselectedNode(distanceMap, selectedNodes);
    }
    return distanceMap;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 5}, {1, 3, 7}, {2, 3, 6},{1, 4, 10}, {3, 4, 11}, {2, 6, 6},{6, 3, 1}, {3, 5, 6},{5, 4, 1}};
    auto graph = createGraph(matrix);
    cout<<graph<<endl;
    cout<<graph.nodes.size()<<endl;
    cout<<graph.edges.size()<<endl;
    auto node = graph.nodes[2];
    dfs(node);
    auto res = sortedByTopology(graph);
    printList(res);
    MSTByKruska(graph);

}