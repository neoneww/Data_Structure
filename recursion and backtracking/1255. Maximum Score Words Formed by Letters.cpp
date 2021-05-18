class Solution {
public:
    // letters is basically frequency array 
    int solution(vector<string>& words, vector<int>& letters, vector<int>& score,int idx)
    {
        if(idx == words.size())
        {
            return 0;
        }
        // 1 case: when we are not including the word 
        int sno = 0 + solution(words,letters,score,idx+1);

        //2 case: when we are including the word 
        int sword = 0;
        string word = words[idx];
        bool flag = true;

        for(int i = 0; i < word.length(); i++)
        {
            if(letters[word[i]-'a'] == 0)     // frequency of the particular word 
            {
                flag = false;
            }
            letters[word[i]-'a']--;
            sword += score[word[i]-'a'];
        }
        int syes = 0;
        if(flag) // if we can include the particular word
        {
            syes = sword + solution(words,letters,score,idx+1);
        }
        
        // after making the call we need to restore the frequency of the word in the letter array

        for(int i = 0; i < word.length(); i++)
        {
            letters[word[i]-'a']++;
        }

        return max(syes,sno);
    }


    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int> freq(26,0);

        for(int i = 0; i < letters.size(); i++)
        {
            freq[letters[i]-'a']++;
        }


        return solution(words,freq,score,0);     
    }
}; 
