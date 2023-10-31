class Solution {
public:
    int largestInteger(int num) {
        vector<int> v;

        while(num!=0){
            v.push_back(num%10);
            num /= 10;
        }

        reverse(v.begin(),v.end());
        priority_queue<int>pq1,pq2;

        for(auto dig : v){
            if(dig%2 == 0) pq1.push(dig);
        }
        for(auto dig : v){
            if(dig%2 == 1) pq2.push(dig);
        }

        int ans =0;

        for(int i=0;i<v.size(); i++){
            if(v[i]% 2 == 0){
                ans = ans*10 +pq1.top();
                pq1.pop();
            }
            else{
                ans = ans*10 + pq2.top();
                pq2.pop();
            }
        }
        return ans;
    }
};
