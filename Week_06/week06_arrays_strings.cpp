// Week 6: searching, 2D-array layout, string comparison, and score analysis.
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
    const int values[8] = {12, 45, 67, 89, 23, 56, 78, 90};
    int target, found = -1;
    cout << "ACTIVITY 1 - Search target in 12 45 67 89 23 56 78 90: ";
    if (!(cin >> target)) return 1;
    for (int i=0;i<8;++i) if(values[i]==target){found=i;break;}
    if(found>=0) cout << target << " found at index " << found << " (position " << found+1 << ")\n";
    else cout << target << " was not found.\n";

    int matrix[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout << "\nACTIVITY 2 - Row-major traversal with addresses\n";
    for(int r=0;r<3;++r) for(int c=0;c<4;++c) cout << "matrix["<<r<<"]["<<c<<"]="<<matrix[r][c]<<" @ "<<static_cast<const void*>(&matrix[r][c])<<'\n';
    cout << "Column-major traversal values: ";
    for(int c=0;c<4;++c) for(int r=0;r<3;++r) cout << matrix[r][c] << ' ';
    cout << "\n\nACTIVITY 3 - C-string and std::string comparison\nEnter a name: ";
    cin >> ws; string name; getline(cin,name);
    char cName[100]; name.copy(cName,99); cName[name.size()<99?name.size():99]='\0';
    cout << "std::string length="<<name.length()<<", first character="<<(name.empty()?' ':name[0])<<'\n';
    cout << "C-string length="<<string(cName).length()<<", first character="<<(cName[0]?cName[0]:' ')<<"\n\n";

    vector<int> scores(10); double total=0;
    cout << "ACTIVITY 4 - Enter 10 scores (0-100): ";
    for(int& score:scores){ if(!(cin>>score)||score<0||score>100){cout<<"Invalid score.\n";return 1;} total+=score; }
    double average=total/scores.size(); int high=scores[0],low=scores[0],above=0;
    cout<<fixed<<setprecision(2)<<"Average: "<<average<<"\nScores above average: ";
    for(int i=0;i<10;++i){if(scores[i]>average){cout<<scores[i]<<" (position "<<i+1<<") ";++above;} if(scores[i]>high) high=scores[i]; if(scores[i]<low) low=scores[i];}
    cout<<"\nHighest: "<<high<<"; lowest: "<<low<<"; count above average: "<<above<<'\n';
    return 0;
}
