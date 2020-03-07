#include <vector>
struct GraphNode{
    int label;
    vector<GraphNode*> neighbors;
    GraphNode(int x) : label(x) {};
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<GraphNode*> graph;
        vector<int> visit;
        //build graph, -1:not visit, 0: visiting; 1: visited
        for(int i = 0; i < numCourses; i++){
            graph.push_back(new GraphNode(i));
            visit.push_back(-1);
        }
        //build direction
        for(int i = 0; i < prerequisites.size(); i++){
            for(int j = prerequisites[i].size() - 1; j >= 0; j-- ){
                GraphNode *begin = graph[prerequisites[i][j]];
                if(j >= 1){
                    GraphNode *end = graph[prerequisites[i][j - 1]];
                    begin -> neighbors.push_back(end); 
                }
            }
        }
        //run DFS
        for(int i = 0; i < graph.size(); i++){
            if(visit[i] == -1 && !DFS_graph(graph[i], visit)){
                return false;
            }
        }
        //delete
        for(int i = 0; i < numCourses; i++){
            delete graph[i];
        }
        return true;
    }
private:
    bool DFS_graph(GraphNode *node, vector<int> &visit){
        visit[node -> label] = 0;
        for(int i = 0; i < node -> neighbors.size(); i++){
            if( visit[node -> neighbors[i] -> label] == -1){
                if(DFS_graph(node -> neighbors[i], visit) == 0){
                    return false;
                }
            }
            else if(visit[node -> neighbors[i] -> label] == 0){
                return false;
            }
        }
        visit[node -> label] = 1;
        return true;
    }
};