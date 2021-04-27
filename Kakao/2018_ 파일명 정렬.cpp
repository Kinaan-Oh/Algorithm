// stable_sort 기능을 사용할 수 있지만, 순서정보를 활용하여 안정 정렬을 구현. O(nlgn).

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
    transform(file_parsed.head.begin(),file_parsed.head.end(),file_parsed.head.begin(),::tolower);
    file_parsed.number = stoi(file.substr(indexOfFirstDigit,indexOfLastDigit-indexOfFirstDigit+1));
    
    return file_parsed;
}

bool compare(File f1, File f2)
{
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
