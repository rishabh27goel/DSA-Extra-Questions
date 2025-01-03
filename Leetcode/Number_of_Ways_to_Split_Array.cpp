#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
  int waysToSplitArray(vector<int> &nums) {
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = nums.size();

    long rightSum = accumulate(nums.begin(), nums.end(), 1L * 0);
    long leftSum = 0;

    int splits = 0;
    for (int j = 0; j < n - 1; j++)
    {
      leftSum += 1L * nums[j];
      rightSum -= 1L * nums[j];

      if (leftSum >= rightSum)
        splits++;
    }

    return splits;
  }
};