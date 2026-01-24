#include "input.hpp"
#include <iostream>
#include <ostream>

int main(){

while(1){

    std::cout<<">>"<<std::flush;
    std::string line=input();
    if(line=="exit"){
        break;
    }

    std::cout<<"you typed:("<<line<<") length:"<<line.length()<<std::endl;

}
}
