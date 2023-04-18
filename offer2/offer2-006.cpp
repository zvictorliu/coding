#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i != j){
            if (numbers[i] + numbers[j] == target) break;
            if (numbers[i] + numbers[j] > target) j--;
            else i++;
        }
        vector<int> result = {i, j};
        return result;
    }
};

int main(){
    Solution res;
    vector<int> numbers = {1,2,4,6,10};
    int target = 8;
    res.twoSum(numbers, target);
}