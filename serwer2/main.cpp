#include <iostream>
#include "Service.h"
using namespace std;

int main()
{

    Service serv("127.0.0.1","7070");
    serv.setEndpoint("/api");
    serv.accept().wait();

    while(1==1)
    {
        sleep(1000);
    }
    return 0;
}
