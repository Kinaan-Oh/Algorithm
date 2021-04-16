struct Window
{
    int begin, end; //  range: [begin,end)
    Window(int b,int e):begin(b),end(e){}
    bool operator != (Window r)
    {
        return !(begin==r.begin && end==r.end);
    }
    bool operator == (Window r)
    {
        return (begin==r.begin && end==r.end);
    }
};

Window END(-1,-1);

class Solution {
private:
    unordered_map<char,int> count;
    int need;
    Window window = Window(0,0);
    Window ans = Window(-100000,100000);

public:
    string minWindow(string s, string t) 
    {
        need = t.size();
        for(int i=0;i<t.size();i++) count[t[i]]++;
        
        while(window!=END)
        {
            if(need==0)
            {
                window = contract(s);
                updateAns();
                window = prepare(s);
            }
            
            else    window = expand(s);
        }
        
        if(ans==Window(-100000,100000)) return "";
        return s.substr(ans.begin,ans.end-ans.begin);
    }
    
    Window expand(string s)
    {
        int end = window.end;
        while(need>0)
        {
            if(end==s.size())   return END;
            if(--count[s[end++]]>=0)    need--;
        }
        return Window(window.begin,end);
    }
    
    Window contract(string s)
    {
        int begin  = window.begin;
        while(need==0)
        {
            if(++count[s[begin++]]>0)   need++;
        }
        --count[s[--begin]];
        need--;
        return Window(begin,window.end);
    }
    
    Window prepare(string s)
    {
        ++count[s[window.begin++]];
        need++;
        return Window(window.begin,window.end);
    }
    
    void updateAns(void)
    {
        if(ans.end-ans.begin>window.end-window.begin)   ans = window;
    }
};
