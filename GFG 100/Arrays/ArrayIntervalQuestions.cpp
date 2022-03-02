// https://leetcode.com/problems/merge-intervals/discuss/1398334/C%2B%2B-SIMPLE-with-EXPLANATION-Pattern-for-INTERVAL-problems
// https://leetcode.com/problems/insert-interval/
//Can Also be done using binary search 
class Solution

{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
        // firstly pushing all the elements before the overlap.i.e ended before start of this interval
        while (i < n and intervals[i][1] < newInterval[0])
            res.push_back(intervals[i++]);

        // if that while loop broke before n it means we definetly found an overlapping
        // now will be merging overlapping
        vector<int> temp = newInterval;
        while (i < n and intervals[i][0] <= newInterval[1])
        { // merging : if intervals started before or equal to ending of new interval
            temp[0] = min(temp[0], intervals[i][0]);
            temp[1] = max(temp[1], intervals[i][1]);
            i++;
        }
        res.push_back(temp);

        // adding rest elements to the res after merging overlap
        while (i < n)
            res.push_back(intervals[i++]);
        return res;
    }
};