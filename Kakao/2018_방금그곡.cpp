// O(musicinfo.size * lengthOfContent)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct MusicInfo
{
    string title;
    int playtime;
    string content;
};

int getPlaytime(string begin, string end)
{
    int begin_minute = stoi(begin.substr(0,2))*60 + stoi(begin.substr(3,2));
    int end_minute = stoi(end.substr(0,2))*60 + stoi(end.substr(3,2));
    return end_minute - begin_minute;
}

string getContent(string partOfContent, int playtime)
{
    string content;
    string partOfContentSubstituted;
    for(int i=0;i<partOfContent.size();i++)
    {
        if(partOfContent[i]=='#')   partOfContentSubstituted.back()=tolower(partOfContentSubstituted.back());
        else    partOfContentSubstituted += partOfContent[i];
    }
    if(playtime==-1)    return  partOfContentSubstituted;
    for(int i=0;i<playtime/partOfContentSubstituted.size();i++)
    {
        content += partOfContentSubstituted;
    }
    content += partOfContentSubstituted.substr(0,playtime%partOfContentSubstituted.size());
    
    return content;
}

MusicInfo parse(string musicinfo)
{
    MusicInfo musicinfo_parsed;
    vector<int> indicesOfComma;
    int cur=-1;
    for(int i=0;i<3;i++)
    {
        cur = musicinfo.find_first_of(",",cur+1);
        indicesOfComma.push_back(cur);
    }
    musicinfo_parsed.playtime = getPlaytime(musicinfo.substr(0,indicesOfComma[0]),musicinfo.substr(indicesOfComma[0]+1,indicesOfComma[1]-indicesOfComma[0]-1));
    musicinfo_parsed.title = musicinfo.substr(indicesOfComma[1]+1,indicesOfComma[2]-indicesOfComma[1]-1);
    musicinfo_parsed.content = getContent(musicinfo.substr(indicesOfComma[2]+1), musicinfo_parsed.playtime);
    
    return musicinfo_parsed;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int playtimeOfAnswer=0;
    vector<MusicInfo>   musicinfos_parsed;
    for(int i=0;i<musicinfos.size();i++)
    {
        musicinfos_parsed.push_back(parse(musicinfos[i]));
    }
    for(int i=0;i<musicinfos_parsed.size();i++)
    {
        if(musicinfos_parsed[i].content.find(getContent(m,-1))!=-1 && musicinfos_parsed[i].playtime>playtimeOfAnswer) {
            answer = musicinfos_parsed[i].title;
            playtimeOfAnswer = musicinfos_parsed[i].playtime;
        }   
    }
    return answer;
}
