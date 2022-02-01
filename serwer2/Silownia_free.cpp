#include <iostream>
#include <string>
#include <vector>
#include "Silownia_free.h"
#include "Service.h"

Silownia_free::Silownia_free(string ccel, string izzo, string lvl, string sche)
{
    poziom = lvl;
    izometria = izzo;
    cel = ccel;
    schem = sche;
}
void Silownia_free::trening_creator()
{
        vector <json::value> jsonPlan_treningowyI;
        vector <json::value> jsonPlan_treningowyII;
        string powtorzenia;
        string serie;

        if(izometria == "true")
            {
                string str_trening = is_isometric[poziom];
                trening = trening_map[str_trening];
                cout << "str trening working" << endl;
            }

        else
            {
                trening  = trening_map[poziom];
            }

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
                cout << "cwiczenia appended to json plan" << endl;
            }

            for(auto mapIt = begin(trening); mapIt != end(trening); ++mapIt)
            {

                json::value cwiczenie_dzienI;
                json::value cwiczenie_dzienII;

                cout << "json value created" << endl;

                cwiczenie_dzienI[mapIt->first] = json::value::string(mapIt->second[0]+" "+serie+powtorzenia);
                cwiczenie_dzienII[mapIt->first] = json::value::string(mapIt->second[1]+" "+serie+powtorzenia);

                cout << "cwiczenie have value now" << endl;

                jsonPlan_treningowyI.push_back(cwiczenie_dzienI);
                jsonPlan_treningowyII.push_back(cwiczenie_dzienII);

                cout << "json plan pushback works" << endl;
            }

        }

        else // push-pull
        {
            for (int j=0; j<2; j++)
            {

                  int i = 1;
                    for(auto mapIt = begin(trening); mapIt != std::prev(end(trening)); ++mapIt)// prev(prev)
                {

                    json::value cwiczenie_dzienI;
                    json::value cwiczenie_dzienII;

                    if ((i%2 == 0 and poziom != "basic") or (i%2 != 0 and poziom == "basic"))
                    {
                        cwiczenie_dzienI[mapIt->first] = json::value::string(mapIt->second[j]+" "+serie+powtorzenia);
                        jsonPlan_treningowyI.push_back(cwiczenie_dzienI);
                    }

                    else
                    {
                        if((mapIt->first == "klatka") and (j == 1) and (poziom == "basic" or poziom == "medium"))
                            cwiczenie_dzienII["triceps"] = json::value::string(triceps[poziom]+" "+serie+powtorzenia);
                        else
                            cwiczenie_dzienII[mapIt->first] = json::value::string(mapIt->second[j]+" "+serie+powtorzenia);

                        jsonPlan_treningowyII.push_back(cwiczenie_dzienII);
                    }
                    i++;

                }

                json::value cwiczenie_brzuch_dzienI;
                json::value cwiczenie_brzuch_dzienII;
                json::value cwiczenie_akcesoria_plecy;
                if ((poziom == "medium" or poziom == "advanced") and j == 1)
                {
                    cwiczenie_akcesoria_plecy["plecy gora"] = json::value::string(plecy_akcesoria[poziom]+" "+serie+powtorzenia);
                    jsonPlan_treningowyI.push_back(cwiczenie_akcesoria_plecy);
                }
                cwiczenie_brzuch_dzienI["brzuch"] = json::value::string(trening["zbrzuch"][j]+" "+serie+powtorzenia);
                cwiczenie_brzuch_dzienII["brzuch"] = json::value::string(trening["zbrzuch"][j]+" "+serie+powtorzenia);
                jsonPlan_treningowyII.push_back(cwiczenie_brzuch_dzienII);
                jsonPlan_treningowyI.push_back(cwiczenie_brzuch_dzienI);


            }


        }


        generatedPlan["Dzien I"] = json::value::array(jsonPlan_treningowyI);
        generatedPlan["Dzien II"] = json::value::array(jsonPlan_treningowyII);

}
