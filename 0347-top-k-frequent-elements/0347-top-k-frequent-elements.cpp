class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     map<int, int> mpp;
    //     for(int num : nums) {
    //         mpp[num] ++;
    //     }

    //     vector<pair<int, int>> v(mpp.begin(), mpp.end());
    //     sort(v.begin(), v.end(), [](auto &a, auto &b) {
    //         return a.second > b.second;
    //     });   

    //     vector<int> result;

    //     for(int i = 0; i < k; i++) {
    //         result.push_back(v[i].first);
    //     }
    //     return result;     
    // }

    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(int num : nums) {
            mpp[num] ++;
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto &it : mpp) {
            int value = it.first;
            int freq = it.second;

            pq.push({freq, value});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};