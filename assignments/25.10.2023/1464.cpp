class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;

        for(int i:nums){
            pq.push(i);
        }
        
        int a=pq.top();
        pq.pop();
        int b=pq.top();

        return (a-1)*(b-1);
    }
};
