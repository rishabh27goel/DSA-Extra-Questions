#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    // string countOfAtoms(string formula) {
        
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    //     int n = formula.size();

    //     vector<pair<string, int>> track;
    //     int i = 0;

    //     while(i < n){
    //         // Start of a formula
    //         if(formula[i] >= 'A' && formula[i] <= 'Z'){

    //             int idx = i + 1;
    //             string element = "";
    //             element.push_back(formula[i]);

    //             // Get the remining element
    //             while(idx < n && formula[idx] >= 'a' && formula[idx] <= 'z'){
    //                 element.push_back(formula[idx]);
    //                 idx++;
    //             }

    //             // Get the count if any
    //             int num = 0;
    //             while(idx < n && formula[idx] >= '0' && formula[idx] <= '9'){
    //                 num = (num * 10) + (formula[idx]-'0');
    //                 idx++;
    //             }

    //             num = max(num, 1);    
    //             track.push_back({element, num});
    //             i = idx;
    //         }
    //         else if(formula[i] == '('){
    //             track.push_back({ "(", 1 });
    //             i++;
    //         }
    //         else {
    //             // Getting the count after bracket
    //             int idx = i + 1;
    //             int num = 0;

    //             while(idx < n && formula[idx] >= '0' && formula[idx] <= '9'){
    //                 num = (num * 10) + (formula[idx]-'0');
    //                 idx++;
    //             }
    
    //             vector<pair<string, int>> insideBracket;
    //             while(!track.empty() && track.back().first != "("){
    //                 insideBracket.push_back(track.back());
    //                 track.pop_back();
    //             }

    //             // Pop opening bracket
    //             track.pop_back();
    //             num = max(num, 1);

    //             while(!insideBracket.empty()){
    //                 track.push_back({ insideBracket.back().first, insideBracket.back().second * num });
    //                 insideBracket.pop_back();
    //             }

    //             i = idx;
    //         }
    //     }

    //     map<string, int> freq;
    //     for(int i=0; i<track.size(); i++){
    //         freq[track[i].first] += track[i].second; 
    //     }

    //     string result = "";
    //     for(auto itr = freq.begin(); itr != freq.end(); itr++){
    //         if(itr->second == 1) {
    //             result += itr->first;
    //         }  
    //         else {
    //             result += itr->first;
    //             result += to_string(itr->second);
    //         }
    //     }

    //     return result;
    // }

    string countOfAtoms(string formula) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = formula.size();

        vector<int> precompute;
        vector<int> openMul(n, 1);

        int multiple = 1;
        for(int i=n-1; i>=0; i--){
            if(formula[i] == ')'){
                int idx = i + 1;
                int num = 0;

                while(idx < n && formula[idx] >= '0' && formula[idx] <= '9'){
                    num = (num * 10) + (formula[idx]-'0');
                    idx++;
                }

                num = max(num, 1);
                multiple *= num; 
                precompute.push_back(num);
            }
            else if(formula[i] == '('){
                openMul[i] = multiple;
                multiple /= precompute.back();
                precompute.pop_back();
            }
        }

        map<string, int> freq;
        vector<pair<string, int>> track;
        multiple = 1;

        int i = 0;
        while(i < n){
            // Start of a formula
            if(formula[i] >= 'A' && formula[i] <= 'Z'){

                int idx = i + 1;
                string element = "";
                element.push_back(formula[i]);

                // Get the remining element
                while(idx < n && formula[idx] >= 'a' && formula[idx] <= 'z'){
                    element.push_back(formula[idx]);
                    idx++;
                }

                // Get the count if any
                int num = 0;
                while(idx < n && formula[idx] >= '0' && formula[idx] <= '9'){
                    num = (num * 10) + (formula[idx]-'0');
                    idx++;
                }

                num = max(num, 1) * multiple;    
                track.push_back({element, num});
                freq[element] += num;
                i = idx;
            }
            else if(formula[i] == '('){
                multiple = openMul[i];
                i++;
            }
            else {
                // Getting the count after bracket
                int idx = i + 1;
                int num = 0;

                while(idx < n && formula[idx] >= '0' && formula[idx] <= '9'){
                    num = (num * 10) + (formula[idx]-'0');
                    idx++;
                }
    
                num = max(num, 1);
                multiple /= num;
                i = idx;
            }
        }

        string result = "";
        for(auto itr = freq.begin(); itr != freq.end(); itr++){
            if(itr->second == 1) {
                result += itr->first;
            }  
            else {
                result += itr->first;
                result += to_string(itr->second);
            }
        }

        return result;
    }
};