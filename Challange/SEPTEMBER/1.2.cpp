#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        int n = nums.size();
        vector<pair<long long, int>> list;
        for (int i = 0; i < n; i++)
            list.push_back({nums[i], i});
        sort(list.begin(), list.end());
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n && list[j].first - list[i].first <= t; j++)
                if (abs(list[j].second - list[i].second) <= k)
                    return true;
        }
        return false;
    }
};