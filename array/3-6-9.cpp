vector<string> solve(int n) {
    vector<string> finAns;
    for(int i=1;i<=n;i++)
    {
        if(i%3 != 0) // not a multiple of 3 
        {
            bool ans = false;
            int temp = i;
            while(temp > 0)
            {
                int p = temp%10;
                if(p == 3 || p == 6 || p ==9)
                {
                    ans = true;
                    break;
                }
                temp = temp/10;
            }

            if(ans)
            {
                finAns.push_back("clap");
            }
            else
            {
                finAns.push_back(to_string(i));
            }
        }
        else{
            finAns.push_back("clap");
        }
    }

    return finAns;
}
