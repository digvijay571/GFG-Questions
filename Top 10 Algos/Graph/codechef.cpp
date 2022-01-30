#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;cin>>T;

	while(T--)
	{

		int N;cin>>N;
		unordered_map<int,int> mp;
		bool flag = false;
		int totalfreq = 0;
		int max_freq = 0;
		while(N--)
		{
			int num;cin>>num;
			
			if(mp.count(num))
			{
				mp[num]++;
				max_freq = max(max_freq,mp[num]);
				totalfreq +=1; 
				flag=true;
			}
			else
			{
				mp[num] = 1;
				totalfreq +=1; 
			}
		}
		if(flag || totalfreq == 1)
		{
			// cout<<mp.size()<<endl;
			if(mp.size()==1)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<(totalfreq-max_freq)+1<<endl;
			}
		}
		else
		{
			cout<<-1<<endl;
		}

	}
}