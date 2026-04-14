class Solution {
public:
    int singleNumber(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end());

        int index = 0;
        int size = numbers.size();

        while (index < size - 1) {
            if (numbers[index] == numbers[index + 1]) {
                index += 2;
            } else {
                return numbers[index];
            }
        }

        return numbers[index];
    }
};