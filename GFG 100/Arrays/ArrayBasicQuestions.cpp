#include<bits/stdc++.h>

using namespace std;
//Q.1Max or Min Element in Array

int maxElement(int arr[],int n)//we have to pass size with arr
							  // as they are passed as pointers
{
	int maxNum=arr[0];
	for(int i=1;i<n;i++)
	{
		maxNum = max(maxNum,arr[i]);//maximizing maxNum

		//OR

		if(maxNum<arr[i])
		{
			maxNum=arr[i];
		}
	}

	return maxNum;
}

//Q. Find Second Largest Element

int secondLargest(int arr[],int n)
{
	int largest = arr[0];
	int secondLargest = INT_MIN;

	for(int i=0;i<n;i++)
	{
		if(arr[i] > largest)
		{
			largest=arr[i];
			secondLargest=largest;
		}
		else if(arr[i] > secondLargest)
		{
			secondLargest=arr[i];
		}
	}
	return secondLargest;
}

void printVec(vector<int>& v)
{
	for(auto e:v)
	{
		cout<<e<<" ";
	}
	cout<<endl;
}


vector<int> frequencyMap(string s)
{
    
    int n=s.size();

    vector<int> fmp(26,0);//frequency map of each character here capital and small letters are considered same

    for(int i=0;i<n;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        fmp[s[i]-'a']++;

        if(s[i]>='A'&&s[i]<='Z')
        fmp[s[i]-'A']++;
    }

    return fmp;
}
int main()
{
	// int arr[] = {1,2,43,23,-3,20,5};
	// int size = sizeof(arr)/sizeof(arr[0]);
	// cout<<maxElement(arr,size);

	string s="hellomynameisdigvijay";

	vector<int> fmp = frequencyMap(s);
	cout<<(char)(max_element(fmp.begin(),fmp.end())-fmp.begin()+'a');

}