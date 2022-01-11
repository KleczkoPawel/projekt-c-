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
#include<cstring>


using namespace std;
using std::string;


void Service::initRestOpHandlers() {
    _listener.support(methods::GET,std::bind(&Service::handleGet,this,std::placeholders::_1));
    _listener.support(methods::PUT,std::bind(&Service::handlePut,this,std::placeholders::_1));
    _listener.support(methods::OPTIONS,std::bind(&Service::handle_options,this,std::placeholders::_1));
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

            json::value val = task.get();

            auto ClientName = val.at("ClientName").as_string () ;
            auto ClientSecondName = val.at("ClientSecondName").as_string ();
            auto ClientWeight = val.at("ClientWeight").as_string ();
            auto ClientPassword = val.at("ClientPassword").as_string ();
            auto ClientEmail = val.at("ClientEmail").as_string ();
            auto ClientHeight = val.at("ClientHeight").as_string ();
            auto ClientSex = val.at("ClientSex").as_string ();
            auto ClientAge = val.at("ClientAge").as_string ();

            string dane_str1 = "INSERT INTO Logins (ClientName,ClientSecondName,ClientWeight,ClientPassword,ClientEmail,ClientHeight,ClientSex,ClientAge)VALUES(";
            string dane_str2 = '"'+ClientName+'"'+","+'"'+ClientSecondName+'"'+","+'"'+ClientWeight+'"'+","+'"'+ClientPassword+'"'+","+'"'+ClientEmail+'"'+","+'"'+ClientHeight+'"'+","+'"'+ClientSex+'"'+","+'"'+ClientAge+'"'+")";

            mysql_query(connect,(dane_str1+dane_str2).c_str());
            mysql_close(connect);
            cout << "wpisano" << endl;
            http_response response(status_codes::OK);
            response.headers().add(U("Allow"), U("GET, PUT, OPTIONS"));
            response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
            response.headers().add(U("Access-Control-Allow-Methods"), U("GET, PUT, OPTIONS"));
            response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type"));
            message.reply(response);
        }

        catch(std::exception& e) {
            http_response response(status_codes::BadRequest);
            response.headers().add(U("Allow"), U("GET, PUT, OPTIONS"));
            response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
            response.headers().add(U("Access-Control-Allow-Methods"), U("GET, PUT, OPTIONS"));
            response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type"));
            message.reply(response);
        }
    });
}
  void Service::handle_options(http_request message)
  {
    http_response response(status_codes::OK);
    response.headers().add(U("Allow"), U("GET, POST, OPTIONS"));
    response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
    response.headers().add(U("Access-Control-Allow-Methods"), U("GET, PUT, OPTIONS"));
    response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type"));
    message.reply(response);
  }
