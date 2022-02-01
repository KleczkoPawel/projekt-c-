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
#include <cstring>
#include "Street_workout.h"
#include "Silownia_free.h"
#include "Silownia_machine.h"
#include "Crossfit.h"


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
            json::value val = task.get();

            string cel = val.at("cel").as_string();
            string izometryczny = val.at("izo").as_string();
            string rodzaj = val.at("rodzaj").as_string();
            string poziom = val.at("lvl").as_string();
            string schem = val.at("schem").as_string();

            if (rodzaj == "kalistenika")
            {
                Street_workout plan_treningowy(cel,izometryczny,poziom,schem);
                plan_treningowy.trening_creator();

                http_response response(status_codes::OK);

                response.headers().add(U("Allow"), U("GET, PUT, OPTIONS"));
                response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
                response.headers().add(U("Access-Control-Allow-Methods"), U("GET, PUT, OPTIONS"));
                response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type"));

                response.set_body(plan_treningowy.generatedPlan);

                message.reply(response);
            }
            else if (rodzaj == "silownia_free")
            {
                Silownia_free plan_treningowy(cel,izometryczny,poziom,schem);
                plan_treningowy.trening_creator();

                http_response response(status_codes::OK);

                response.headers().add(U("Allow"), U("GET, PUT, OPTIONS"));
                response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
                response.headers().add(U("Access-Control-Allow-Methods"), U("GET, PUT, OPTIONS"));
                response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type"));

                response.set_body(plan_treningowy.generatedPlan);

                message.reply(response);
            }
            else if (rodzaj == "silownia_machin")
            {
                Silownia_machine plan_treningowy(cel,izometryczny,poziom,schem);
                plan_treningowy.trening_creator();

                http_response response(status_codes::OK);

                response.headers().add(U("Allow"), U("GET, PUT, OPTIONS"));
                response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
                response.headers().add(U("Access-Control-Allow-Methods"), U("GET, PUT, OPTIONS"));
                response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type"));

                response.set_body(plan_treningowy.generatedPlan);

                message.reply(response);
            }
            else
            {
                Crossfit plan_treningowy(cel,izometryczny,poziom,schem);
                plan_treningowy.trening_creator();

                http_response response(status_codes::OK);

                response.headers().add(U("Allow"), U("GET, PUT, OPTIONS"));
                response.headers().add(U("Access-Control-Allow-Origin"), U("*"));
                response.headers().add(U("Access-Control-Allow-Methods"), U("GET, PUT, OPTIONS"));
                response.headers().add(U("Access-Control-Allow-Headers"), U("Content-Type"));

                response.set_body(plan_treningowy.generatedPlan);

                message.reply(response);
            }
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
