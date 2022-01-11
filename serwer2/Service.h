#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include "BasicController.h"
#include "Street_workout.h"
#include <vector>
using std::vector;

class Service : public BasicController {
    public:
    Service(const std::string& address,const std::string& port) : BasicController(address,port) {}
    ~Service() {}
    void handleGet(http_request message);
    void handlePut(http_request message);
    void handle_options(http_request message);
    void initRestOpHandlers() override;
    private:
    vector<int> numbers{1,2};
    float calculateSum();
};
#endif // SERVICE_H_INCLUDED
