// O(nlgn)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct File
{
    int id;
    string head;
    int number;
};

File parse(int id, string file)
{
    File file_parsed;
    int indexOfFirstDigit = file.find_first_of("0123456789");
    int indexOfLastDigit = file.find_last_of("0123456789");
    file_parsed.id = id;
    file_parsed.head = file.substr(0,indexOfFirstDigit);
    file_parsed.number = stoi(file.substr(indexOfFirstDigit,indexOfLastDigit-indexOfFirstDigit+1));
    
    return file_parsed;
}

bool compare(File f1, File f2)
{
    transform(f1.head.begin(),f1.head.end(),f1.head.begin(),::tolower);
    transform(f2.head.begin(),f2.head.end(),f2.head.begin(),::tolower);
    if(f1.head==f2.head) {
        if(f1.number==f2.number) {
            return f1.id<f2.id;
        }
        return f1.number<f2.number;
    }
    return f1.head<f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File>    files_parsed;
    for(int i=0;i<files.size();i++)
    {
        files_parsed.push_back(parse(i,files[i]));
    }
    sort(files_parsed.begin(),files_parsed.end(),compare);
    for(int i=0;i<files_parsed.size();i++)   answer.push_back(files[files_parsed[i].id]);
    return answer;
}
