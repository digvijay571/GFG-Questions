
//Majority Element





//Buy and Sell Stocks




//Job Sequencing


//Keywprd:DIffrece


//Idea:Sorting makes all the nos as close as possible to minimze the diffrence

//Miminize height DIffrence

//Chocoate distribution


//Diffrece between two arrays is minimum











//Fractional Knapsack

//Concepet: val/wt
//value per unit weight
bool compare(Item i1,Item i2)//i1 i2
{                              //r1>r2
    double r1 = (i1.value*1.0)/i1.weight;
    double r2 = (i2.value*1.0)/i2.weight;
    
    return r1>r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       sort(arr,arr+n,compare);
       
       double ans=0;
       int i=0;
       while(i<n&&W>0)
       {
           int currweight=arr[i].weight;
           int currval=arr[i].value;
           if(currweight <= W)
           {
               W-=currweight;
               ans +=currval;
           }
           else
           {
               ans+=((currval*1.0)/currweight)*W;
               break;
           }
           i++;
       }
       
       return ans;
    }
        
};



