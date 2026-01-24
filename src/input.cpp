#include "input.hpp"
#include <cstdio>
#include <ostream>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <termios.h>
#include <unistd.h>

struct termios old = {0};
void get_char_settongs_on(){

    // 1. Get current terminal settings
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    
    // 2. Modify settings: turn off "canonical" mode and "echo"
    old.c_lflag &= ~ICANON; 
    old.c_lflag &= ~ECHO;   
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    
    // 3. Apply new settings
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
}
void get_char_settongs_off(){

    // 5. Restore old settings (VERY IMPORTANT!)
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
}

char getch() {
    char buf = 0;
    
    
    // 4. Read the character
    if (read(0, &buf, 1) < 0) perror("read()");
    
    
    return buf;
}

void handle_arrow_keys(int &pose ,std::string& res){
    //skip next two chars
    getch();
    char arrow=getch();
    if(arrow=='D'){//left arrow
        if(pose>0){
            pose--;
            std::cout<<"\033[D"<<std::flush;
        }
    }else if(arrow=='C'){//right arrow
        if(pose<res.length()){
            pose++;
            std::cout<<"\033[C"<<std::flush;
        }
    }

}

void handle_back_space(int &pose,std::string& res){
    if(pose!=0){
        res.erase(pose-1,1);
        pose--;
        std::cout << "\b \b"<<res.substr(pose)<<" "<< std::flush;//delete a char
        std::cout <<"\033["<<res.length()-pose+1<<"D"<<std::flush;//print the rest of the string in the right place
    }
}
void handle_insert_char(int &pose,std::string& res,char c){
            if(!(' '<=c && c<='~')){
                std::cout<<"\a";
                return;
            }
            res.insert(pose,1,c);
            pose++;
            std::cout<<res.substr(pose-1)<<std::flush;
            if(res.length()-pose!=0)//coz \033[0D works like \033[1D for some reasons :3
                std::cout <<"\033["<<res.length()-pose<<"D"<<std::flush;
}

std::string input(){
    get_char_settongs_on();

    std::string res="";
    int pose=0;
    char c=0;//set to 0 in case garbage memory is '\n' || 10
    while(c!='\n'){
        c=getch();
        if(c=='\033'){//escape key
            handle_arrow_keys(pose, res);
            continue;
        }
        else if(c==127){//backspace
            handle_back_space(pose, res);
            continue;
        }
        if(c!='\n'){
            handle_insert_char(pose, res,c);
        }
    }
    std::cout<<std::endl;

    get_char_settongs_off();
    return res;
}

