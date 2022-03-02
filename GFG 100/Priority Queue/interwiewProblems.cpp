// https://leetcode.com/problems/seat-reservation-manager/
// Priority queue is a min heap which will always pop out the smallest value
// Therefore we can use Priority queue to store the available seats,
//  we can easily access to the smallest-numbered unreserved seat by the function q.top(), q.pop().
class SeatManager
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int count;
    SeatManager(int n)
    {
        count = 0;
    }

    int reserve()
    {
        if (pq.size() == 0)
            return ++count;
        int top = pq.top();
        pq.pop();
        return top;
    }

    void unreserve(int seatNumber)
    {
        pq.push(seatNumber);
    }
};

// We don't need n to implement an algorithm for this question. n is really there to trick us imo.
// https://leetcode.com/problems/seat-reservation-manager/discuss/1657649/Java-or-PriorityQueue-or-Keep-1-Seat-is-Enough.
// For example, the following code ignores n and still works.
