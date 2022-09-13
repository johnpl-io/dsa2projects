#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
int spellcheck(const string &inputname, const string &outputname) {
    ifstream inputfile (inputname);
        string line;
        string buf = "";
        
        if(inputfile.is_open())
        while(getline(inputfile, line)) {
              

stringstream s(line);
while (s >> line) {
    buf = "";
int num_count = 0;
for(auto &c : line) {
    bool num_exist;
   if((num_exist = (c >= '0' && c<='9')) ||(c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z') || (c == '\'') || (c == '-')) {
            buf+=c;  
            if(num_exist) 
            num_count++;

} else {
if(buf.length() > 0) {
    transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
    cout << buf << " num count" << num_count << endl;
}
    buf = "";
}

}
if(buf.length() > 20) {
    transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
    cout << buf.substr(0,20) << " IS TOO LONG" << endl;
}
else {
    if(buf.length() > 0) {
    transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
   cout << buf << " num count" << num_count << endl;
    }
}
        

} 

}
return 0;
}
int main() {
spellcheck("test.txt", "output.txt");

}



