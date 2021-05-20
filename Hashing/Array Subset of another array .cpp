string isSubset(int a1[], int a2[], int n, int m) {
  unordered_map<int,int> temp;
  
  for(int i=0;i<n;i++)
  {
      temp[a1[i]]++;
  }
  
  for(int j=0;j<m;j++)
  {
      if(temp.find(a2[j]) != temp.end())
      {
          if(temp[a2[j]] == 0)
          {
              return "No";
          }
          temp[a2[j]]--;
      }
      else
      {
          return "No";
      }
  }
  return "Yes";
}
