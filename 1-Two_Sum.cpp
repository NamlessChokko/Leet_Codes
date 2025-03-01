#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map; 
        int result = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {

            if (hash_map.find(nums[i]) != hash_map.end()){
                return {i, hash_map[nums[i]]};
            }
            
            result = target - nums[i];
            hash_map.insert(make_pair(result, i));
        }

        return {};
}
};


int main (){
    vector<int> nums;
    vector<int> result;
    int target;
    Solution solution;

    nums = {3,2,4};
    target = 6;

    result = solution.twoSum(nums, target);

    cout << to_string(result[0]) << "|" << to_string(result[1]) << endl;



    return 0;
}