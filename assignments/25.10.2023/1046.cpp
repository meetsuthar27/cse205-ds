class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n =stones.size();
        priority_queue<int> pq(stones.begin(),stones.end());


        while(pq.size()>1){
            
                int a=pq.top();
                pq.pop();
                int b=pq.top();
                pq.pop();

                if(pq.size()==0)
                {
                    pq.push(a-b);
                    break;
                }

                if(a==b) continue;

                else pq.push(a-b);

            // if(pq.size()==2){
            //     int a=pq.top();
            //     pq.pop();
            //     int b=pq.top();
            //     pq.pop();

            //     if(a=b) return 0;
            //     else return a-b;
            // }

        }

        return pq.top();

    }
};
