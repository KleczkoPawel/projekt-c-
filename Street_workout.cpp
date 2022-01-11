#include <iostream>
#include <string>
#include <vector>
#include "Street_workout.h"
#include "Service.h"

void Street_workout::treningi()
{

    if(izometria == true)
        trening = trening_map[is_isometric[poziom]];
    else
        trening  = trening_map[poziom];

    string powtorzenia = rodzaj_treningu[cel];
    vector <json::value> jsonPlan_treningowyI;
    vector <json::value> jsonPlan_treningowyII;

        for(auto mapIt = begin(trening); mapIt != end(trening); ++mapIt)
    {
        json::value cwiczenie_dzienI;
        json::value cwiczenie_dzienII;
        cwiczenie_dzienI[mapIt->first] = json::value::string(mapIt->second[0]);
        cwiczenie_dzienII[mapIt->first] = json::value::string(mapIt->second[1]);
        jsonPlan_treningowyI.push_back(cwiczenie_dzienI);
        jsonPlan_treningowyI.push_back(cwiczenie_dzienII);
    }

        this->generatedPlan["Dzien I"] = json::value::array(jsonPlan_treningowyI);
        this->generatedPlan["Dzien II"] = json::value::array(jsonPlan_treningowyII);
    //vector <chybajson> dayI;

}

