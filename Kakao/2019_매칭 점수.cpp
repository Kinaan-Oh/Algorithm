// 출제의도: "스트링패턴 매칭", C++은 string.find()를 활용. 링크점수 구할때 map 자료구조 활용시 유용. 입력크기가 작으므로 시간복잡도 고려하지 않고 구현만 하면 되는 문제.

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Page {
    string url;
    string body;
    vector<string> links;
};

string getUrl(string page) {
    int begin, end;
    int cur = page.find("<meta property=");
    cur = page.find("https://",cur);
    begin = cur;
    end = page.find("\"",cur);
    return page.substr(begin,end-begin);
}

string getBody(string page) {
    int begin, end;
    int cur = page.find("<body>");
    begin = cur+6;
    end = page.find("</body>",cur);
    return page.substr(begin,end-begin);
}

vector<string> getLinks(string body) {
    vector<string> links;
    int begin, end=0;
    while((begin=body.find("<a href=",end))!=-1) {
        begin = body.find("https://",begin);
        end = body.find("\"",begin);
        links.push_back(body.substr(begin,end-begin));
    }
    return links;
}

Page parse(string page) {
    Page pg;
    pg.url = getUrl(page);
    pg.body = getBody(page);
    pg.links = getLinks(pg.body);
    return pg;
}

int getBasicScore(string body, string word) {
    int basicScore=0;
    int begin, end=-1;
    transform(body.begin(),body.end(),body.begin(),::tolower);
    transform(word.begin(),word.end(),word.begin(),::tolower);
    while((begin=body.find(word,end+1))!=-1) {
        end = begin+word.size();
        if(begin-1>=0 && isalpha(body[begin-1]))   continue;
        if(end<body.size() && isalpha(body[end]))  continue;
        basicScore++;
    }
    return basicScore;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    double score_max=-1;
    unordered_map<string,double>   Score;  // url:score
    vector<Page>    pages_parsed;
    for(int i=0;i<pages.size();i++) {
        Page page = parse(pages[i]);
        pages_parsed.push_back(page);
    }
    for(int i=0;i<pages_parsed.size();i++) {
        int basicScore=getBasicScore(pages_parsed[i].body, word);
        Score[pages_parsed[i].url] += basicScore;
        for(int j=0;j<pages_parsed[i].links.size();j++) {
            Score[pages_parsed[i].links[j]] += (double)basicScore/pages_parsed[i].links.size();
        }
    }
    for(int i=0;i<pages_parsed.size();i++) {
        if(Score[pages_parsed[i].url]>score_max) {
            score_max = Score[pages_parsed[i].url];
            answer = i;
        }
    }

    return answer;
}
