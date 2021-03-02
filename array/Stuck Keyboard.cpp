//given two string typed and target 
bool solve(string typed, string target)
{
    if(typed.length() == 0 && target.length() != 0 ||typed.length() != 0 && target.length() == 0 || typed.length() < target.length() || typed.length() == target.length() && typed != target)
    {
        return false;
    }
    
    if(typed == target)
    {
        return true;
    }

    int i=0,j=0; // target string = j     i = typed string
    while(i<typed.length())
    {
        if(typed[i] == target[j])
        {
            i++;
            j++;
        }
        else if(typed[i] != target[j] && typed[i] == target[j-1])
        {
            i++;
        }
        else if(j == target.length()-1 && typed[i] == target[j])
        {
            i++;
        }
        else 
        {
            return false;
        }
    }

    if(i == typed.length() && j < target.length())
    {
        return false;
    }

    return true;
}
