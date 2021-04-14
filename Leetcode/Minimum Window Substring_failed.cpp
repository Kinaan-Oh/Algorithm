// 마지막 테스트케이스 

typedef pair<int,int>   Window;
Window Impossible(-100000,100000);
Window End(-1,-1);

class Solution {
private:
    int numOfNeed;
    map<char,int>   need;
    map<char,bool>  isInT;
    Window window={0,0};
    Window ans = Impossible;
    
public:
    string minWindow(string s, string t) 
    {
        numOfNeed = t.size();
        for(int i=0;i<t.size();i++)  
        {
            need[t[i]]++;
            isInT[t[i]]=true;
        }
        
        while(window!=End)
        {
            if(numOfNeed==0)
            {
                updateAns();
                window = contract(s);
            }
            else
            {
                window = expand(s);
            }
        }
        if(ans==Impossible) return "";
        return  s.substr(ans.first,ans.second-ans.first);
    }
    
    Window contract(string s)
    {
        if(isInT[s[window.first]] && need[s[window.first]]>=0)
        {
            numOfNeed++;
        }
        need[s[window.first]]++;
        
        for(int i=window.first+1;i<s.size();i++)
        {
            if(isInT[s[i]])
            {
                return Window(i,window.second);
            }
        }
        return End;
    }
    
    Window expand(string s)
    {
        for(int i=window.second;i<s.size();i++)
        {
            if(isInT[s[i]])
            {
                if(need[s[i]]>0)
                {
                    numOfNeed--;
                }
                need[s[i]]--;
                return Window(window.first,i+1);
            }
        }
        return End;
    }
    
    int getLengthOfWindow(Window window)
    {
        return window.second - window.first;
    }
    
    void updateAns(void)
    {
        if(getLengthOfWindow(ans)>getLengthOfWindow(window))    ans = window;
    }
};
