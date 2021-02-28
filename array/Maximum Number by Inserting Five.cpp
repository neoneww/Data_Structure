int solve(int n) {
    string s = to_string(n);
    string a;
    bool aa = false;
    int i = 0;
    if(s[0] != '-')
    {
        while(i<s.length())
        {
            if(s[i] < '5' && aa == false)
            {
                a+='5';
                a+=s[i];
                aa = true;
            }
            else 
            {
                a+=s[i];
            }

            i++;
        }

        if(aa == false)
        {
            a+='5';
        }
    }
    else
    {
        i = 1;
        a+='-';
        while(i<s.length())
        {
            if(s[i] > '5' && aa ==false)
            {
                a+='5';
                a+=s[i];
                aa = true;
            }
            else
            {
                a+=s[i];
            }

            i++;
        }

        if(aa == false)
        {
            a+='5';
        }
    }

    int az = stoi(a);

    return az;


}
