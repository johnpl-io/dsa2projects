#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>
using namespace std;
int spellcheck(const string &inputname, const string &outputname) {
    ifstream inputfile (inputname);
        string line;
        string buf = "";
        
        if(inputfile.is_open())
        while(getline(inputfile, line)) {
              buf = "";
       for(auto &c : line) {
   if((c >= '0' && c<='9') ||(c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z') || (c == '\'') || (c == '-')) {
            buf+=c;    
            if(buf.length() > 10) {
                cout << buf << "is too long!" << endl;
                buf = "";
                

            }     
} else {
     cout << buf << endl;
    buf = "";
} 

       }
       cout << buf << endl;
        }
return 0;
}
int main() {
spellcheck("test.txt", "output.txt");

}



