#include <vector>
#include <algorithm>
#include <set>
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::set<std::vector<int>> res_set;
        std::sort(candidates.begin(), candidates.end());
        generate(0, candidates, result, item, res_set, 0, target);
        return result;
    }
private:
    void generate(int i, std::vector<int> &candidates, 
                  std::vector<std::vector<int>> &result,
                  std::vector<int> &item,
                  std::set<std::vector<int>> &res_set, int sum, int target){
        if(i >= candidates.size() || sum > target){
            return;
        }
        sum += candidates[i];
        item.push_back(candidates[i]);
        if(sum == target && res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, candidates, result, item, res_set, sum, target);
        sum -= candidates[i];
        item.pop_back();
        generate(i+1, candidates, result, item, res_set, sum, target);
    }
 };