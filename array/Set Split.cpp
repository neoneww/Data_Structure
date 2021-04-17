bool solve(vector<int>& nums) {
  sort(nums.begin(),nums.end());
  int sum = 0;
  for(int i=0;i<nums.size();i++)
  {
      sum+=nums[i];
  }
  int sum2 = 0;
  for(int i=0;i<nums.size();i++)
  {
      sum2+=nums[i];
      sum-=nums[i];
      if(sum == sum2)
      {
          if(nums[i] < nums[i+1])
          {
            return true;
          }
          else
          {
              return false;
          }
      }
  }

  return false;
}
