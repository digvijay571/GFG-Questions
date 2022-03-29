#include<stdio.h>

using namespace std;



int main()
{
   int n;scanf("%d",&n);

   int arr[n];

   int oddLen=0,evenLen=0;
   for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
       if(arr[i]%2==0)
       {
           evenLen++;
       }
       else
       {
          oddLen++;
       }
   }

   int oddArr[oddLen],evenArr[evenLen];
   int j=0,k=0;
   for(int i=0;i<n;i++)
   {
       if(arr[i]%2==0)
       {
           evenArr[j++]=arr[i];
       }
       else
       {
           oddArr[k++]=arr[i];
       }
   }
   
   printf(" Original array is ");
   for(int i=0;i<n;i++)
   {
       printf("%d",arr[i]);
       if(i!=n-1)
       printf(",");
   }

   printf(" Odd array is ");
   for(int i=0;i<oddLen;i++)
   {
       printf("%d",oddArr[i]);
      if(i!=oddLen-1)
       printf(",");
   }

   printf(" Even array is ");
   for(int i=0;i<evenLen;i++)
   {
       printf("%d",evenArr[i]);
       if(i!=evenLen-1)
       printf(",");
   }
}