//Recursion un functions ko khete hai zo khud ko call kare

#include<bits/stdc++.h>

using namespace std;


//q.1

//Print increasing
void printIncreasing(int n)
{
	if(n==0) return;
	printIncreasing(n-1);
	cout<<n<<endl;
}

//q.2

//Print Decreasing
void printDecreasing(int n)
{
	if(n==0) return;
	cout<<n<<endl;
	printDecreasing(n-1);
}





//q.3

//Print   Decreasing and Increasing
void printIncDec(int n)
{
	if(n==0) return;

	cout<<n<<endl;
	printIncDec(n-1);
	cout<<n<<endl;
}

//Factorial

//Base condition
//fact(1)==1

//Recursive condition
//fact(n)=n*fact(n-1);

int fact(int n)
{
	if(n==1)
		return 1;

	return n*fact(n-1);
}


double pow(double a,double b)//a^b
{
	if(b==0)
		return 1;
	if(b>0)
	return a*pow(a,b-1);
	else
	return 1/a*pow(a,b+1);
}



double pow2(double a,int b)//a^b
{
	if(b==0)
		return 1;

	double p = pow2(a,b/2);

	if(b%2==0)
	   return p*p;
		
	if(b>0)
	  return a*p*p;
	else
	  return 1/a*p*p;
	
}

//gcd expanation is good
// https://dyclassroom.com/recursion-algorithm/greatest-common-divisor-gcd

int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	printIncreasing(5);
	printDecreasing(5);
	printIncDec(10);
	cout<<pow(2,-3)<<endl;
	cout<<pow2(2,-5)<<endl;
	cout<<gcd(10,5)<<endl;

}