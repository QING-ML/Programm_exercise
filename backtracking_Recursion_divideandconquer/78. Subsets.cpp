class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        result.push_back(item);
        generator(0, nums, item, result);
        return result;
    }
private:
    void generator(int i, const std::vector<int>& nums, std::vector<int> &item,  
                  std::vector<std::vector<int>> &result){
        if(i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        generator(i+1, nums, item, result);
        item.pop_back();
        generator(i+1, nums, item, result);
        
    }
};