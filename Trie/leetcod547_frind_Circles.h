class DisjointSet_Tree{
public:
	DisjointSet_Tree(int n){
		for(int i = 0; i < n; i++){
			_id.push_back(i);
			_size.push_back(1);
		}
		_count = n;
	}
	int find(int p){
		while(p != _id[p]){
			_id[p] = _id[_id[p]];
			p = _id[p];
		}
		return p;
	}
	
	void union_(int p, int q){
		int i = find(p);
		int j = find(q);
		if(i == j){
			return;
		}
		if(_size[i] < _size[j]){
			_id[i] = j;
			_size[j] += _size[i];
		}
		else{
			_id[j] = i;
			_size[i] += _size[j];
		}
		_count--;
	}
    
    int count(){
        return _count;
    }
private:
	std::vector<int> _id;
	std::vector<int> _size;
	int _count;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        DisjointSet_Tree disjointset_tree(M.size());
        for(int i = 0; i < M.size(); i++){
            for(int j = 0; j < M.size(); j++){
                if(M[i][j]){
                    disjointset_tree.union_(i,j);
                }
            }
        }
        return disjointset_tree.count();
    }
};