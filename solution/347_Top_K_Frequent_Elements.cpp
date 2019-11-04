#include "alg.h"

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> val2freq;
    unordered_map<int, vector<int>> freq2val;
    for (int i: nums) {
        if (val2freq.count(i)) val2freq[i] += 1;
        else val2freq[i] = 1;
    }
    vector<int> freq;
    for (auto &p: val2freq) {
        if (freq2val.count(p.second)) freq2val[p.second].push_back(p.first);
        else {
            freq2val[p.second] = {p.first};
            freq.push_back(p.second);
        }
    }
    sort(freq.begin(), freq.end());

    int sum = 0;
    vector<int> rt;
    for (int i = freq.size() - 1; i >= 0; i--) {
        auto val_set = freq2val[freq[i]];
        sum += val_set.size();
        // cout << sum;
        if (sum > k) {
            int min = sum - k;
            rt.insert(rt.end(), val_set.begin(), val_set.end() - min);
            return rt;
        } else if (sum == k) {
            rt.insert(rt.end(), val_set.begin(), val_set.end());
            return rt;
        }
        rt.insert(rt.end(), val_set.begin(), val_set.end());
        if (sum == k) return rt;
    }
    return rt;
}

int main() {

}