#include <iostream>
#include <string>
#include <vector>
#include "Crossfit.h"
#include "Service.h"

Crossfit::Crossfit(string ccel, string izzo, string lvl, string sche)
{
    poziom = lvl;
    izometria = izzo;
    cel = ccel;
    schem = sche;
}
void Crossfit::trening_creator()
{
        vector <json::value> jsonPlan_treningowyI;
        vector <json::value> jsonPlan_treningowyII;
        string powtorzenia;
        string serie;

        trening  = trening_map[poziom];

        powtorzenia = cel_treningu[cel];
        serie = serie_treningu[schem];


        if(schem == "obw" and cel=="wytrzymalosc")
        {
            json::value serie_i_powtorzenia;
            serie_i_powtorzenia["obwod"] = json::value::string(wytrzymalosc_komunikat);
            jsonPlan_treningowyI.push_back(serie_i_powtorzenia);
            jsonPlan_treningowyII.push_back(serie_i_powtorzenia);

            for(auto mapIt = begin(trening); mapIt != end(trening); ++mapIt)
            {
                json::value cwiczenie_dzienI;
                json::value cwiczenie_dzienII;
                cwiczenie_dzienI[mapIt->first] = json::value::string(mapIt->second[0]+" | "+powtorzenia);
                cwiczenie_dzienII[mapIt->first] = json::value::string(mapIt->second[1]+" | "+powtorzenia);
                jsonPlan_treningowyI.push_back(cwiczenie_dzienI);
                jsonPlan_treningowyII.push_back(cwiczenie_dzienII);
            }
        }

        else if(schem == "obw" and cel!="wytrzymalosc")
        {

            if ((poziom == "advanced") and (izometria == "false"))
            {
                serie = " | 3 serie ";
                json::value cwiczenie_dodatkowe_klatka_dzienI;
                json::value cwiczenie_dodatkowe_klatka_dzienII;
                json::value cwiczenie_dodatkowe_nogi_dzienI;
                json::value cwiczenie_dodatkowe_nogi_dzienII;
                json::value cwiczenie_dodatkowe_plecy_dzienI;
                json::value cwiczenie_dodatkowe_plecy_dzienII;

                cwiczenie_dodatkowe_klatka_dzienI["klatka dodatek"] = json::value::string(trening["klatka"][2]+" "+serie+powtorzenia);
                cwiczenie_dodatkowe_nogi_dzienI["nogi dodatek"] = json::value::string(trening["pnogi"][2]+" "+serie+powtorzenia);
                cwiczenie_dodatkowe_plecy_dzienI["plecy dodatek"] = json::value::string(trening["nplecy"][2]+" "+serie+powtorzenia);

                cwiczenie_dodatkowe_klatka_dzienII["klatka dodatek"] = json::value::string(trening["klatka"][3]+" "+serie+powtorzenia);
                cwiczenie_dodatkowe_nogi_dzienII["nogi dodatek"] = json::value::string(trening["pnogi"][3]+" "+serie+powtorzenia);
                cwiczenie_dodatkowe_plecy_dzienII["plecy dodatek"] = json::value::string(trening["nplecy"][3]+" "+serie+powtorzenia);

                jsonPlan_treningowyI.push_back(cwiczenie_dodatkowe_klatka_dzienI);
                jsonPlan_treningowyII.push_back(cwiczenie_dodatkowe_klatka_dzienII);
                jsonPlan_treningowyI.push_back(cwiczenie_dodatkowe_nogi_dzienI);
                jsonPlan_treningowyII.push_back(cwiczenie_dodatkowe_nogi_dzienII);
                jsonPlan_treningowyI.push_back(cwiczenie_dodatkowe_plecy_dzienI);
                jsonPlan_treningowyII.push_back(cwiczenie_dodatkowe_plecy_dzienII);
            }

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




        generatedPlan["Dzien I"] = json::value::array(jsonPlan_treningowyI);
        generatedPlan["Dzien II"] = json::value::array(jsonPlan_treningowyII);

}
