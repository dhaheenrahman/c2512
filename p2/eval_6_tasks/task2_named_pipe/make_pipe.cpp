// #include <sys/types.h>
#include <sys/stat.h>
#include <iostream>

using namespace std;

int main(){
    if(mkfifo("mypipe", 0666) == -1){
        perror("mkpipe failed");
        return 1;
    }
    cout << "pipe created" << endl;
    return 0;
}
