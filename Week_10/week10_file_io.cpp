// Week 10: file I/O, checked failures, return codes, exceptions, and CSV parsing.
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

bool readWithStatus(const string& path){ifstream file(path);if(!file)return false;string line;while(getline(file,line)){}return true;}
void readWithException(const string& path){ifstream file(path);if(!file)throw runtime_error("Could not open "+path);}
void sumNumbers(){
    ifstream in("numbers.txt");if(!in){cerr<<"Activity 1: numbers.txt is missing.\n";return;}
    int value,sum=0;while(in>>value)sum+=value;in.close();
    ofstream out("sum.txt");if(!out){cerr<<"Cannot create sum.txt.\n";return;}
    out<<"The total sum is: "<<sum<<'\n';out.close();cout<<"ACTIVITY 1 - Sum of numbers: "<<sum<<" (written to sum.txt)\n";
}
void analyzeMissingFile(){
    ifstream missing("missing_data.txt");string line;
    if(!missing){cout<<"ACTIVITY 2 - Missing file leaves the stream failed; unchecked reads yield no data. Check open status before processing.\n";return;}
    getline(missing,line);cout<<line<<'\n';
}
void compareErrors(){
    cout<<"\nACTIVITY 3 - Return code: "<<(readWithStatus("missing_data.txt")?"success":"failure handled by caller")<<'\n';
    try{readWithException("missing_data.txt");cout<<"Exception strategy: opened successfully.\n";}
    catch(const runtime_error& error){cout<<"Exception caught: "<<error.what()<<"\n";}
}
void parseCsv(){
    ifstream file("students.csv");if(!file){cerr<<"Cannot open students.csv.\n";return;}
    cout<<"\nACTIVITY 4 - Robust CSV parsing\n";string line;
    while(getline(file,line)){
        if(line.empty())continue;
        if(!line.empty()&&line.back()=='\r')line.pop_back();
        stringstream row(line);string name,a,b,c;
        if(!getline(row,name,',')||!getline(row,a,',')||!getline(row,b,',')||!getline(row,c,',')){cout<<"WARNING: malformed row skipped: "<<line<<'\n';continue;}
        try{
            size_t used1=0,used2=0,used3=0;int s1=stoi(a,&used1),s2=stoi(b,&used2),s3=stoi(c,&used3);
            if(used1!=a.size()||used2!=b.size()||used3!=c.size()||s1<0||s1>100||s2<0||s2>100||s3<0||s3>100)throw invalid_argument("invalid score");
            cout<<name<<" -> GPA/average: "<<(s1+s2+s3)/3.0<<'\n';
        }catch(const exception&){cout<<"WARNING: Skipping malformed record for "<<name<<" (invalid score data).\n";}
    }
}
int main(){cout<<"WEEK 10 - FILE I/O AND ERROR HANDLING\n";sumNumbers();analyzeMissingFile();compareErrors();parseCsv();return 0;}
