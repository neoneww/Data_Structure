int solve(string animals, string dinosaurs) {
    set<char> pp;
    int cnt = 0;

    for(int i=0;i<dinosaurs.length();i++)
    {
        pp.insert(dinosaurs[i]);
    }

    for(int i=0;i<animals.length();i++)
    {
        if(pp.find(animals[i]) != pp.end())
        {
            cnt++;
        }
    }

    return cnt;
}
