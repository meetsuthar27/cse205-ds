class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int>pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        vector<int>ans;
        map<int,int>mp;

        while(k>0){
            k--;
            mp[pq.top()]++;
            pq.pop();
        }

    for(int i=0;i<nums.size();i++){

          if(mp[nums[i]]>= 1){

              ans.push_back(nums[i]);
              mp[nums[i]]--;
          }


      }
        return ans;

        
    }
};
