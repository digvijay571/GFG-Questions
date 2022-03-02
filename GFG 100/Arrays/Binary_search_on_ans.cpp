https : // leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/discuss/777019/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.

        https : // leetcode.com/problems/minimum-time-to-complete-trips/
                class Solution
{
public:
    // let say function f(t) return true if it's possible to complete totalTrips in t time and false
    // otherwise. And X be the optimal solution i.e. minimum time required to complete totalTrips.
    // So, for any time t where( t < X ) , f(t) return false and for any time s where (s >= X)
    // f(s) returns true. Simply means funtion f(t) is monotonous .

    // Monotonic function
    // A function f(x) is said to be monotonic iff for any x if f(x) returns true, then for any value of y (where y > x) should also return true and similarly if for a certain value of x for which f(x) is false, then for any value z (z < x) the function should also return false.

    bool isPossible(long long int mid, vector<int> &time, long long int totalTrips) // time is mid ->can i complete totalTrips
    {
        long long int currTrips = 0;

        for (auto t : time)
        {

            currTrips += mid / t;
        }

        return (currTrips >= totalTrips);
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long int min = *min_element(time.begin(), time.end());

        long long int l = min;
        long long int r = (min * totalTrips);

        while (l < r)
        {

            long long int mid = l - (l - r) / 2;
            if (isPossible(mid, time, totalTrips))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r;
    }
};
