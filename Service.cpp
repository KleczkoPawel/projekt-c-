#include "Service.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "mysql_connection.h"
#include <mysql.h>

using namespace std;
using std::string;

void Service::initRestOpHandlers() {
    _listener.support(methods::GET,std::bind(&Service::handleGet,this,std::placeholders::_1));
    _listener.support(methods::PUT,std::bind(&Service::handlePut,this,std::placeholders::_1));
}
float Service::calculateSum() {
    float sum = 0;
    for(unsigned int i = 0;i<numbers.size();i++) {
        sum+=numbers[i];
    }
    return sum;
}
void Service::handleGet(http_request message) {

    MYSQL *connect;
    MYSQL_ROW row;
    MYSQL_RES * result;

    unsigned int num_fields;
    unsigned int i;

    connect = mysql_init(NULL);
    if(!connect)
    {
        puts("nie udalo sie1");
    }

    connect = mysql_real_connect(connect,"127.0.0.1","dbuser","1234","CLIENT_DB",0, NULL, 0);
    if(!connect)
    {
        cout << ("not connected to database") << endl;
    }
    else
        cout << ("connected to database ") << endl;

    mysql_query(connect, "SELECT * FROM Logins");

    result = mysql_store_result(connect);
    num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result)))
    {
       unsigned long * lengths;
       lengths = mysql_fetch_lengths(result);

       for(i = 0; i < num_fields; i++)
       {
              cout << ("[%.* s] \t", (int)lengths[i], row[i] ? row[i] : "NULL");
       }
       cout << ("\n");
    }


    mysql_close(connect);
    message.reply(status_codes::OK);
    }

void Service::handlePut(http_request message) {

    message.extract_json().then([=](pplx::task<json::value> task)
    {
        try
        {
            MYSQL *connect;
            connect = mysql_init(NULL);
            if(!connect)
            {
                puts("nie udalo sie1");
            }
            connect = mysql_real_connect(connect,"127.0.0.1","dbuser","1234","CLIENT_DB",0, NULL, 0);

            if(!connect)
            {
                puts("not connected to database");
            }
            else{
                puts("connected to database ");
            }
            mysql_query(connect,"INSERT INTO Logins (ClientName,ClientSecondName,ClientWeight,ClientPassword,ClientEmail,ClientHeight,ClientID,ClientSex,ClientAge) VALUES ('Siara','Siarzewski',3,'daawa','adwawdawdaad',4214,5,'aa',33)");
            mysql_close(connect);
            json::value val = task.get();
            int number = val[U("number")].as_number().to_int32();
            numbers.push_back(number);
            message.reply(status_codes::OK);
        }
        catch(std::exception& e) {
            message.reply(status_codes::BadRequest);
        }
    });
}

