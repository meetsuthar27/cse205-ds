class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gsz) {
        if(hand.size()%gsz !=0)
            return false;

        int curr=0, prev=-1;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto h : hand)
            pq.push(h);

        vector<int> tmp;
        while(!pq.empty()) {
            int t = pq.top();
            pq.pop();
            if(prev ==-1 ||t - prev==1) {
                prev= t;
                curr++;
            }
            else {
                tmp.push_back(t);
            }

            if(curr == gsz) {
                curr = 0;
                prev = -1;

                for(auto e : tmp)
                    pq.push(e);

                tmp = {};
            }
        }   
        
        if(curr){
            return false;
        }
        else{
            return true;
        }
        return false;
    }
};
