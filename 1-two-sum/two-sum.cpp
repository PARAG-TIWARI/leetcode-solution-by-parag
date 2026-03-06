class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int>numscpy;
        vector<int>ans;
        ans.resize(2);
        int n=nums.size(),val;
        for(int i=0;i<n;i++)
        {
            ans[0]=i;
            val=target-nums[i];
            auto temp=numscpy.find(val);
            if(temp!=numscpy.end())
            {
                ans[1]=temp->second;
                return ans;
            }
            numscpy[nums[i]]=i;
        }
        return {};
    }
};