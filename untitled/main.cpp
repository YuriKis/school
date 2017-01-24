#include <iostream>

#include <vector>
struct str {
    std::vector<char> ss;
    str(char arr[]){
        std::vector<char>().swap(ss);
        for (int i = 0; i < sizeof(arr); ++i) {
            ss.push_back(arr[i]);
        }
    }
    str(std::vector<char> s) {
        ss = s;
    }
    char get(int i){ return ss[i];}
    void set(char c, int n) { ss[n] = c;}
    void print(){
        for(auto &a: ss) std::cout << a;
    }
    void concat(char arr[]){
        for (int i = 0; i < sizeof(arr); ++i) {
            ss.push_back(arr[i]);
        }
    }
    void concat(std::vector<char> s) {//indexOf
        ss = s;
    }
    int find(char arr[]){ //
        int c=0;
        for (int i = 0; i < ss.size(); ++i){
            for (int j = 0; j < sizeof(arr); ++j) {
                if(ss[i] == arr[j]) c++;
                else                c=0;
            }
            if (c == sizeof(arr)) return i;
        }
    }
};
int main() {

    str sss("lllllol");
    sss.concat("- xxx");
    sss.print();
    std::cout <<"\n"<< sss.find("lol")<<"\n";
    return 0;
}