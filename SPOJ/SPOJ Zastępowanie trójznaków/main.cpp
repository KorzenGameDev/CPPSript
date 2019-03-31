#include <iostream>
#include <string>

using namespace std;

string kod;
int main()
{
    getline(cin,kod);
    for(int i=0;i<kod.size()-1;i++){
        if(kod[i]=='?' && kod[i+1]=='?' && kod[i+2]!='/0'){
            switch(kod[i+2]){
                case '=': kod.replace(i,3,"#"); break;
                case '/': kod.replace(i,3,"\\"); break;
                case '\'': kod.replace(i,3,"^"); break;
                case '(': kod.replace(i,3,"["); break;
                case ')': kod.replace(i,3,"]"); break;
                case '!': kod.replace(i,3,"|"); break;
                case '<': kod.replace(i,3,"{"); break;
                case '>': kod.replace(i,3,"}"); break;
                case '-': kod.replace(i,3,"~"); break;
                default: break;}}}
    cout<<kod<<endl;
    return 0;
}
