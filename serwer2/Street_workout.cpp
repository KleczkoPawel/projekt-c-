#include <iostream>
#include <string>
#include <vector>
#include "Street_workout.h"
#include "Service.h"

Street_workout::Street_workout(string ccel, string izzo, string lvl, string sche)
{
    poziom = lvl;
    izometria = izzo;
    cel = ccel;
    schem = sche;
}

void Street_workout::trening_creator()
{
        vector <json::value> jsonPlan_treningowyI;
        vector <json::value> jsonPlan_treningowyII;
        string powtorzenia;
        string serie;

        if(izometria == "true")
            {
                string str_trening = is_isometric[poziom];
                trening = trening_map[str_trening];
                powtorzenia= " ";
                serie = " ";
            }

        else
            {
                trening  = trening_map[poziom];
                powtorzenia = cel_treningu[cel];
                serie = serie_treningu[schem];
            }




        if(izometria == "true" or schem == "obw")
        {

                for(auto mapIt = begin(trening); mapIt != end(trening); ++mapIt)
            {
                json::value cwiczenie_dzienI;
                json::value cwiczenie_dzienII;
                cwiczenie_dzienI[mapIt->first] = json::value::string(mapIt->second[0]+" "+serie+powtorzenia);
                cwiczenie_dzienII[mapIt->first] = json::value::string(mapIt->second[1]+" "+serie+powtorzenia);
                jsonPlan_treningowyI.push_back(cwiczenie_dzienI);
                jsonPlan_treningowyII.push_back(cwiczenie_dzienII);
            }
        }

        else // push-pull
        {
            for (int j=0; j<2; j++)
            {

                  int i = 1;
                    for(auto mapIt = begin(trening); mapIt != std::prev(end(trening)); ++mapIt)
                {
                    json::value cwiczenie_dzienI;
                    json::value cwiczenie_dzienII;
                    if (i%2 == 0)
                    {
                        cwiczenie_dzienI[mapIt->first] = json::value::string(mapIt->second[j]+" "+serie+powtorzenia);
                        jsonPlan_treningowyI.push_back(cwiczenie_dzienI);
                    }
                    else
                    {
                        cwiczenie_dzienII[mapIt->first] = json::value::string(mapIt->second[j]+" "+serie+powtorzenia);
                        jsonPlan_treningowyII.push_back(cwiczenie_dzienII);
                    }
                    i++;
                }

                json::value cwiczenie_brzuch_dzienI;
                json::value cwiczenie_brzuch_dzienII;
                cwiczenie_brzuch_dzienI["brzuch"] = json::value::string(trening["zbrzuch"][j]+" "+serie+powtorzenia);
                cwiczenie_brzuch_dzienII["brzuch"] = json::value::string(trening["zbrzuch"][j]+" "+serie+powtorzenia);
                jsonPlan_treningowyII.push_back(cwiczenie_brzuch_dzienII);
                jsonPlan_treningowyI.push_back(cwiczenie_brzuch_dzienI);


            }


        }


        generatedPlan["Dzien I"] = json::value::array(jsonPlan_treningowyI);
        generatedPlan["Dzien II"] = json::value::array(jsonPlan_treningowyII);

}

