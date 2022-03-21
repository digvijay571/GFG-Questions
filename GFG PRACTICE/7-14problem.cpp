//What do u mean by consecutive (are also sorted)?
//arr[i+1] - arr[i] ==1;

// https://www.geeksforgeeks.org/count-of-only-repeated-element-in-a-sorted-array-of-consecutive-elements/
//Binary search


//Using Binary search we can find the starting index of repeating charaters
//function used: arr[0]+m>arr[m];
pair<int, int> sequence(const vector<int>& a)
{
    if (a.size() == 0)
        return {0, 0};
 
    int s = 0;
    int e = a.size() - 1;
    while (s < e)
    {
        int m = (s + e) / 2;

        if ( a[0]+m>a[m])//FFFFFTTTT
                               |
                        //This is going to our ans (i.e last F that is lower half)
            e = m - 1;
        else
            s = m;
    }

    //{1,2,3,4}
    //last element -first elemet = size-1;

    //consecutive+extra = size
    // ((last element - fist element)+1) + repeated= (size)
    //repeated = (size) - (((last element - fist element)+1));

    return {a[s], a.size() - (a[a.size() - 1] - a[0])};
}
 
// Driver code
int main()
{
    pair<int, int>p = sequence({ 1, 2, 3, 4, 4, 4, 5, 6 });
    cout << "Repeated element is " << p.first
         << ", it appears " << p.second << " times";
    return 0;
}