//https://leetcode.com/problems/two-sum/description/
//#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // // Approach 1: Brute Force
        // for(size_t i = 0; i < nums.size(); ++i)
        // {
        //     for(size_t j = i; j < nums.size(); ++j)
        //     {
        //         if(nums[i] + nums[j] == target)
        //         {
        //             vector <int> temp;
        //             temp.push_back(i);
        //             temp.push_back(j);
        //             return temp;
        //         }
        //     }
        // }

        // Approach 2: Two-pass Hash Table
        map <int, int> harshTB;
        map <int, int>::iterator it; 
        for(size_t i = 0; i < nums.size(); ++i)
        {
            harshTB.insert(pair<int, int>(nums[i], i));
        }
        for(size_t i = 0; i < nums.size(); ++i)
        {
            int nextVal = target - nums[i];
            it = harshTB.find(nextVal);
            if(it != harshTB.end())
            {
                vector <int> temp;
                temp.push_back(i);
                temp.push_back(it->second);
                return temp; 
            }
        }
    }
};

int main()
{
    static const int arr[] = {2, 7, 11, 15};
    vector <int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]));

    Solution s;
    vector <int> res = s.twoSum(vec, 9);
    cout << res[0] << " " << res[1];

    return 0;
}