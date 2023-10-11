// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         int count=0;

//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i] == nums[j]){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt = 0;

        for (int i : nums) {
            if(mp.find(i)!=mp.end()){
            cnt += mp[i];
            mp[i]++;
            }
            else{
                mp[i]=1;
            }
        }

        return cnt;
    }
};
