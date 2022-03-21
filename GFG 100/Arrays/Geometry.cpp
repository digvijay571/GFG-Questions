//Overlapping Rectangles
// Two rectangles do not overlap if one of the following conditions is true.

// One rectangle is above top edge of other rectangle.
// One rectangle is on left side of left edge of other rectangle.

int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        
        // left side
        if(R1[0]<L2[0] || R2[0]<L1[0]) return 0;//r1 left r2 or r2 left r1 
        
        // up side
        if(L2[1]<R1[1] || L1[1]<R2[1]) return 0;//r1 above r2 or r2 above r1 
        
         return 1;
    }



//Can Make A Triange






//Missing Point of Parallelogram





//Points on Straight Line