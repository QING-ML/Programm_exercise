class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> graph;
        construct_graph(beginWord, wordList, graph);
        int step;
        step = BFS_graph(beginWord, endWord, graph);
        return step;
    }

private:
    int BFS_graph(string &beginWord, string &endWord, map<string, 
                  vector<string>> graph){
        queue<pair<string, int>> Q;
        Q.push(make_pair(beginWord, 1));
        set<string> visit;
        visit.insert(beginWord);
        while(!Q.empty()){
            string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            for(int i = 0; i < graph[node].size(); i++){
                if(graph[node][i] == endWord){
                    return step + 1;
                }
                if(visit.find(graph[node][i]) == visit.end()){
                    
                    Q.push(make_pair(graph[node][i], step + 1));
                    visit.insert(graph[node][i]);
                }
            }
        }
        return 0;
    }
    
    bool connect(const string &word1, const string &word2 ){
        int cnt = 0;
        for(int i = 0; i < word1.length(); i++){
            if(word1[i] != word2[i]){
                cnt ++;
            }
        }
        return cnt == 1;
    }
    
    void construct_graph(string &beginWord,
                        vector<string> &wordList,
                        map<string, vector<string>> &graph){
        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); i++){
            graph[wordList[i]] = vector<string>();
        }
        
        for(int i = 0; i < wordList.size(); i++){
            for(int j = i + 1; j < wordList.size(); j++){
                if(connect(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }
};