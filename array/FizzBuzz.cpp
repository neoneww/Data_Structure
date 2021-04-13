vector<string> solve(int n) {
 vector<string> temp;
 string a = "Fizz" ;
 string b = "Buzz";
 for(int i=1;i<=n;i++)
 {
     if(i%3==0&&i%5==0)
     {
         temp.push_back(a+b);
     }
     else if(i%3==0)
     {
         temp.push_back(a);
     }
     else if(i%5==0)
     {
         temp.push_back(b);
     }
     else
     {
         temp.push_back(to_string(i));
     }
 }

 return temp;  
}
