#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = skill.size();

        long long total = 0;
        for(int j = 0; j < n; j++)
            total += skill[j];

        if(total % (n / 2) != 0)
            return -1;

        sort(skill.begin(), skill.end());

        int pairSum = total / (n / 2);
        int i = 0;
        int j = n-1;

        long long product = 0;
        while(i <= j) {
            if(skill[i] + skill[j] != pairSum)
                return -1;

            product += (skill[i] * skill[j]);
            i++, j--;
        }

        return product;
    }
};