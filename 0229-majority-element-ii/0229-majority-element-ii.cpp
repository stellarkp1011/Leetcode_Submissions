class Solution {
public:
    // O(n2)
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     int mini = (n / 3) + 1;
    //     vector<int> list;
    //     for(int i = 0; i < n ; i++) {
    //         if(list.size() == 0 || list[0] != nums[i]) {
    //             int cnt = 0;
    //             for(int j = 0; j < n; j++) {
    //                 if(nums[i] == nums[j]) {
    //                     cnt++;
    //                 }
    //             }
    //             if(cnt >= mini) list.push_back(nums[i]);
    //         }
    //         if(list.size() == 2) break;
    //     }
    //     return list;
    // }

    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     int mini = (n / 3) + 1;
    //     vector<int> list;
    //     unordered_map<int, int> mpp;
    //     for(int i = 0; i < n; i++) {
    //         mpp[nums[i]]++;
    //         if(mpp[nums[i]] == mini) list.push_back(nums[i]);
    //         if(list.size() == 2) break;
    //     }
    //     return list;
    // }

    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mini = (n / 3) + 1;
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && nums[i] != el2){
                cnt1 = 1;
                el1 = nums[i];
            } else if(cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (nums[i] == el1){
                cnt1++;
            } else if (nums[i] == el2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        vector<int> list;
        for(int i = 0; i < n; i++) {
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;
        }
        if(cnt1 >= mini) list.push_back(el1);
        if(cnt2 >= mini) list.push_back(el2);
        return list;
    }
};