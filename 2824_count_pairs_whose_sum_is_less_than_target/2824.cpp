#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int countPairs(vector<int>& nums, int target) {
        int sizeOfVec = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = sizeOfVec - 1, c = 0;

        while (i < j) {
            if (nums[i] + nums[j] < target) {
                c += j - i;
                i++;
            } else {
                j--;
            }
        }
        return c;
    }
};

int main() {
    Solution solution;
    vector<int> v = {-6, 2, 5, -2, -7, -1, 3};
    int target = -2;
    int result = solution.countPairs(v, target);
    cout << result << endl;
    return 0;
}