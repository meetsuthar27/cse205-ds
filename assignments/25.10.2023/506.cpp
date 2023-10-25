class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        vector<string> ans(score.size());

        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }

        for(int i=0;i<score.size();i++){
            auto it=pq.top();
            pq.pop();
            int val = it.first;
            int idx = it.second;

            if(i==0){
                ans[idx]="Gold Medal";
            }
            else if(i==1){
                ans[idx]="Silver Medal";
            }
            else if(i==2){
                ans[idx]="Bronze Medal";
            }
            else{
                ans[idx]=to_string(i+1);
            }
        }

        return ans;
    }
};
