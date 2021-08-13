// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
bool isPossible(int arr[], int n, int m, int curr_min)
    {
    	int studentsRequired = 1;
    	int curr_sum = 0;
    
    	for (int i = 0; i < n; i++)
    	{
    		if (arr[i] > curr_min)
    			return false;
    
    		if (curr_sum + arr[i] > curr_min)
    		{
    			studentsRequired++;
    			curr_sum = arr[i];
    
    			if (studentsRequired > m)
    				return false;
    		}
    
    		else
    			curr_sum += arr[i];
    	}
    	return true;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        int start=*max_element(arr,arr+n);
        int end=accumulate(arr,arr+n,0);
      //  cout<<start<<endl;
        int res=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(isPossible(arr,n,m,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return res;
    }
