// 큐. O(progresses.size()).

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> getWorkPeriodOfProgresses(vector<int> &progresses, vector<int> &speeds)
{
    vector<int> workPeriodOfProcess;
    for(int i=0;i<progresses.size();i++)
    {
        int workPeriod;
        if((100-progresses[i])%speeds[i]==0)   workPeriod = (100-progresses[i])/speeds[i];
        else    workPeriod = (100-progresses[i])/speeds[i] + 1;
        
        workPeriodOfProcess.push_back(workPeriod);
    }
    return  workPeriodOfProcess;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> workPeriodOfProcess = getWorkPeriodOfProgresses(progresses, speeds);
    int numOfFunctionsToRelease=1;
    int firstFunctionToRelease=0;

    for(int i=1;i<workPeriodOfProcess.size();i++)
    {
        if(workPeriodOfProcess[firstFunctionToRelease]>=workPeriodOfProcess[i])  numOfFunctionsToRelease++;
        else
        {
            answer.push_back(numOfFunctionsToRelease);
            firstFunctionToRelease = i;
            numOfFunctionsToRelease = 1;
        }
    }
    if(numOfFunctionsToRelease>0)    answer.push_back(numOfFunctionsToRelease);
    
    return answer;
}
