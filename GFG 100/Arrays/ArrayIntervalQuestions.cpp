// Sorting+intervals

// https://leetcode.com/problems/merge-intervals/discuss/1398334/C%2B%2B-SIMPLE-with-EXPLANATION-Pattern-for-INTERVAL-problems
// https://leetcode.com/problems/insert-interval/
// Can Also be done using binary search

// Merge intervals
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        int start = intervals[0][0];
        int end = intervals[0][1];

        vector<vector<int>> ans;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= end) // if the current interval has started before ending of prev interval
            {
                end = max(end, intervals[i][1]);
            }
            else
            {
                // if prev cannot be merged
                // the it cannot merged with any of further intervals
                // so push it into ans

                ans.push_back({start, end});

                // update prev interval to current one
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};

// If current inteval has started before ending of prev then there is an overalp
// we will consider min end to get maximum interval space

// Erase Change is in

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        int end = intervals[0][1];

        int remove = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < end)
            {
                remove++;

                end = min(end, intervals[i][1]);
            }
            else
            {
                end = intervals[i][1];
            }
        }

        return remove;
    }
};

// IF we sort based upon starting time :
// we are sure that our curr interval has started is either after our equal to prev stating time

// So the criterial for partial overlapping is judged by:ending interval only
// if ending of prev >= stating of current then there is an overalap

// ps-> start previours interval
//
// merged interval = {ps,max(ce,pe)};

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

// https://leetcode.com/problems/remove-covered-intervals/

// Dry run to get the idea

//  Brute force O(N2) solution .

int removeCoveredIntervals(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (i != j)
            {
                if (v[j][0] >= v[i][0] && v[j][1] <= v[i][1])
                {
                    v[j][0] = v[j][1] = -1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i][0] != -1)
            ans++;
    }
    return ans;
}

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &A)
    {

        int res = 0, start = -1, end = -1;
        sort(A.begin(), A.end());

        // sort based on start interval

        //[[1,4],[1,2],[1,3]]
        //[[1 2],[1 3],[1 4]]

        // after defaul sorting
        // if the starting points are equal then prev interval will definetly overlap curr inteval
        // if they are diffrent

        // ---------
        // -----------
        //      -
        //      --
        //      ----
        //      ------------

        //      ----------------
        //                        -----

        for (auto &curr : A)
        {
            if (curr[0] > start && curr[1] > end)
            {

                // curr_start is either equal  or greater

                // if equal then it means that current interval will cover the range

                // if greater and if end is less than prev end

                // then it will be covered by prev interval

                // so if greater and end is greater then there is not covering
                // and move start
                // res++

                // always maximise the end

                // if curr interval is starting after range start and ending after the range end)
                start = curr[0]; // move  start to next start
                ++res;
            }

            end = max(end, curr[1]);
        }

        return res;
    }
};

// DP+Greedy+Intervals:https://www.youtube.com/watch?v=Pk128gC_sdw


//interval+covering some time or area with minimum intervals

//  https://leetcode.com/problems/video-stitching/
// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/


class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        //for each of clips
        //we try to get maximum end if it has started somewhere before and ended after curr min
        
        //if mini==maxi then return -1
        
        //make mini = maxi ,count++
        
        //repeat this untill maxi<time
        
        int mini=0;
        int maxi=0;
        int count=0;
        while(maxi<time)
        {
            for(int i=0;i<clips.size();i++)
            {
                if(clips[i][0]<=mini && clips[i][1]>maxi)
                {
                    maxi = max(maxi,clips[i][1]);
                }
            }
             //Upar ke scanning  mei AGAR KOI RANGE MILA HOGA TO MAX!=MIN HOGA
		     //Else ESSE AAGE NHI BADH PA RAHE HAI
            if(maxi==mini)
                return -1;
            
            mini=maxi;
            count++;
        }
        
        return count;
    }
};


//Change is we have to form itervals intead of iterating through intervals 

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        
        //for each of clips
        //we try to get maximum end if it has started somewhere before and ended after curr min
        
        //if mini==maxi then return -1
        
        //make mini = maxi ,count++
        
        //repeat this untill maxi<time
        
        int mini=0;
        int maxi=0;
        int count=0;
        while(maxi<n)
        {
            for(int i=0;i<ranges.size();i++)
            {
                if((i-ranges[i])<=mini && (i+ranges[i])>maxi)
                {
                    maxi = max(maxi,i+ranges[i]);
                }
            }
            if(maxi==mini)
                return -1;
            
            mini=maxi;
            count++;
        }
        
        return count;

    }
};