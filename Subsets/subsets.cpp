class Solution {
private: 
    void powerset(vector<int> nums, int index, vector<int> output, vector<vector<int>>& ans) {
        //base case 
        if (index >= nums.size()) {
            ans.push_back(output); 
            return ; 
        }

        //excluding an element 
        powerset(nums, index+1, output, ans);

        //including an element 
        int element = nums[index]; 
        output.push_back(element); 
        powerset(nums, index+1, output, ans);
        output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> output; 
        int index; 

        powerset(nums, index, output, ans); 
        return ans; 
    }
};