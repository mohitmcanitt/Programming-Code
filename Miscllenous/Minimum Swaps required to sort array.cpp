int minSwaps(vector<int>&nums)
	{
	    // Code here
	   int n=nums.size();
	   pair<int,int>ap[n];
	   for(int i=0;i<n;i++)
	   {
	        ap[i].first=nums[i];
	        ap[i].second=i;
	   }
	   sort(ap,ap+n);
	   bool visited[n]={false};
	   int ans=0;
	   for(int i=0;i<n;i++)
	   {
	       if(visited[i] or i==ap[i].second)
	        continue;
	        
	        int node=i;
	        int cycle=0;
	        
	        while(visited[node]==false)
	        {
	            visited[node]=true;
	            int new_node=ap[node].second;
	            node=new_node;
	            cycle++;
	        }
	        ans+=(cycle-1);
	   }
	   return ans;
	}
