#include<vector>
#include<set>
#include<algorithm>
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::set<std::vector<int>> res_set;
        std::sort(nums.begin(), nums.end());
        result.push_back(item);
        generate(0, nums, result, item, res_set);
        return result;
    }
private:
    void generate(int i, std::vector<int> &nums, 
                  std::vector<std::vector<int>> &result, std::vector<int> &item,
                 std::set<std::vector<int>> &res_set){
        if( i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        
        if(res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, result, item, res_set);
        item.pop_back();
        generate(i+1, nums, result, item, res_set);
    }
    
};