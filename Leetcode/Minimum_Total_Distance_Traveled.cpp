#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // long dp[101][101][101];
    // long findDistance(int n, int m, vector<int> &robot, vector<vector<int>> &factory, int rbIdx, int fcIdx, int limit) {
    //     if(rbIdx == n)
    //         return 0;

    //     if(fcIdx == m)
    //         return 1e16;

    //     if(dp[rbIdx][fcIdx][limit] != -1)
    //         return dp[rbIdx][fcIdx][limit];

    //     long nextFactory = findDistance(n, m, robot, factory, rbIdx, fcIdx + 1, 0);

    //     long includeRobot = 1e16;
    //     if(limit < factory[fcIdx][1])
    //         includeRobot = abs(robot[rbIdx] - factory[fcIdx][0]) + findDistance(n, m, robot, factory, rbIdx + 1, fcIdx, limit + 1);

    //     return dp[rbIdx][fcIdx][limit] = min(nextFactory, includeRobot);
    // }

    // long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = robot.size();
    //     int m = factory.size();

    //     sort(robot.begin(), robot.end());
    //     sort(factory.begin(), factory.end());

    //     memset(dp, -1, sizeof(dp));
    //     return findDistance(n, m, robot, factory, 0, 0, 0);
    // }

    // long dp[101][10001];
    // long findDistance(int n, int m, vector<int> &robot, vector<int> &factory, int rbIdx, int fcIdx) {
    //     if(rbIdx == n)
    //         return 0;

    //     if(fcIdx == m)
    //         return LONG_MAX;

    //     if(dp[rbIdx][fcIdx] != -1)
    //         return dp[rbIdx][fcIdx];

    //     long nextFactory = findDistance(n, m, robot, factory, rbIdx, fcIdx + 1);

    //     long includeRobot = findDistance(n, m, robot, factory, rbIdx + 1, fcIdx + 1);
    //     if(includeRobot != LONG_MAX)
    //         includeRobot = abs(robot[rbIdx] - factory[fcIdx]) + includeRobot;

    //     return dp[rbIdx][fcIdx] = min(nextFactory, includeRobot);
    // }

    // long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = robot.size();
    //     int m = factory.size();

    //     sort(robot.begin(), robot.end());
    //     sort(factory.begin(), factory.end());

    //     vector<int> fact;
    //     for(auto &child : factory) {
    //         for(int j = 0; j < child[1]; j++) {
    //             fact.push_back(child[0]);
    //         }
    //     }

    //     memset(dp, -1, sizeof(dp));
    //     return findDistance(n, fact.size(), robot, fact, 0, 0);
    // }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = robot.size();

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> fact;
        for(auto &child : factory) {
            for(int j = 0; j < child[1]; j++) {
                fact.push_back(child[0]);
            }
        }

        int m = fact.size();
        vector<vector<long>> dp(n + 1, vector<long> (m + 1, 0));

        for(int rbIdx = n-1; rbIdx >= 0; rbIdx--) {
            for(int fcIdx = m; fcIdx >= 0; fcIdx--) {
                if(fcIdx == m) {
                    dp[rbIdx][fcIdx] = LONG_MAX; 
                    continue;
                }
                    
                long nextFactory = dp[rbIdx][fcIdx + 1];

                long includeRobot = dp[rbIdx + 1][fcIdx + 1];
                if(includeRobot != LONG_MAX)
                    includeRobot = abs(robot[rbIdx] - fact[fcIdx]) + includeRobot;

                dp[rbIdx][fcIdx] = min(nextFactory, includeRobot);
            }
        }

        return dp[0][0];
    }
};