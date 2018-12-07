//C001:単語のカウント C++版 20180707 (★リファクタンリング前) 
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

enum error_code{
    ERROR_NO_ERROR = 0,
    ERROR_OTHER = 1,
};

class WordCounter{
private:
    map<string, int> _counter;
    vector<string> _words;

public:
    WordCounter(){
        _counter.clear();
        _words.clear();
    };

    void add(string word){
        if(_counter.find(word) == _counter.end()){
            _counter[word] = 0;
            _words.push_back(word);
        }

        _counter[word]++;
    };
    
    void print(){
        vector<string>::iterator ite = _words.begin();
        while(ite != _words.end()){
            cout << *ite << " " << _counter[*ite] << "\n";
            ++ite;
        }
    }
};

int main(void){
    WordCounter wc;
    string s;

    try{
        while(cin >> s){
            wc.add(s);
        }
        
        wc.print();
    }catch(...){
        return ERROR_OTHER;
    }

    return ERROR_NO_ERROR;
}
