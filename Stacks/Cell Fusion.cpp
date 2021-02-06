int solve(vector<int>& cells)
{
    priority_queue<int> pp;
    
    for(int i=0;i<cells.size();i++)
    {
        pp.push(cells[i]);
    }

    while(pp.empty() == false)
    {
        int a = pp.top();
        pp.pop();
        if(pp.empty() == true)
        {
            return a;
        }
        else
        {
            int b = pp.top();
            pp.pop();
            if(a != b)
            {
                int c = floor((a + b) / 3);
                pp.push(c);
            }
        }
    }

    return -1;
}
