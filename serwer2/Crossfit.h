
#ifndef CROSSFIT_H
#define CROSSFIT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Service.h"
#include <stdlib.h>

class Crossfit
{
    public:
        Crossfit(string,string,string,string);
        void trening_creator();
        json::value generatedPlan;
        std::map <string, vector<string> > trening;

    protected:

    private:

    string poziom;
    string izometria;
    string cel;
    string schem;
    string wytrzymalosc_komunikat = "Ćwiczenia zamykamy w obwód i wykonujemy je kolejno z przerwą 5s między ćwiczeniami i 120s między obwodami";

    std::map <string, string> is_isometric {{"medium","medium_izometria"},{"advanced","advanced_izometria"}};
    std::map <string, string> cel_treningu {{"sila","ilość powtórzeń: 4"},{"masa","ilość powtórzeń: 8"},{"wytrzymalosc","ilość powtórzeń: 12"}};
    std::map <string, string> serie_treningu {{"obw"," | 4 serie "},{"push_pull"," | 3 serie "}};

    vector <string> klatka_basic  = {"pompki z rękoma na podwyższeniu","pompki szwedzkie"};
    vector <string> klatka_medium = {"wycislanie leżąc","dipy"};// + akcesoria po 2 serie
    vector <string> klatka_advanced = {"pompki z ciężarem","wyciskanie leżąc","dipy","wyciskanie na ujemnym skosie"};
    vector <string> klatka_akcesoria = {"dipy","pompki z ciężarem"};

    vector <string> nogi_basic = {"front squat","Kettlebell Swings"};
    vector <string> nogi_medium = {"zarzut sztangi","burpees"}; //+akcesoria + akcesoria po 2 serie
    vector <string> nogi_advanced = {"wskoki na skrzynie","przysiady bułgarskie z hantlami","martwy ciąg","front squat"};

    vector <string> nogi_akcesoria = {"wykroki w przód z hantlami","żurawie na maszynie"};

    string zurawie = {"żurawie na maszynie"};
    string zurawie_izometria = {"żurawie na maszynie z pauzą 5s w połowie ruchu"};

    vector <string> plecy_basic = {"wiosłowanie w opadzie tułowia","podciągnięcia negatywne"};
    vector <string> plecy_medium = {"podciągnianie na drążku szerokim chwytem","wiosłowanie hantlem"};// + akcesoria
    vector <string> plecy_advanced = {"przyciągania górnej części ramion zza głowy w kierunku tułowia leżąc (sztanga)","wiosłowanie sztangą w opadzie tułowia","wiosłowanie hantlem","podciąganie na drążku podchwytem"}; // + akcesoria

    vector <string> brzuch_basic = {"spięcia brucha leżąc","uginanie oderwanych od ziemi nóg leżąc"};
    vector <string> brzuch_medium = {"krzesełka z użyciem drażka","scyzoryki z ugiętymi nogami"};
    vector <string> brzuch_advanced = {"wznosy prostych nóg do pozycji L-sit z użyciem drążka","tzw. wycieraczki na drążku"};

    vector <string> brzuch_skos = {"spacer farmera jednorącz", "plank bokiem"};
    vector <string> brzuch_izometria_skos = {"plank bokiem","plank bokiem"};

    vector <string> barki_medium = {"wyciskanie żołnierskie","pompki pike"};
    vector <string> barki_advanced = {"Landmine press","pompki na rękach"};

    vector <string> biceps_basic = {"uginanie przedramion z hantlami","uginanie przedramion na modlitewniku"};
    vector <string> biceps_medium = {"uginanie przedramion z hantlami chwytem młotkowym ","uginanie przedramion na modlitewniku"};
    vector <string> biceps_advanced = {"uginanie przedramion ułożonych za linią tułowia leżąc na dodatnim skosie - hantle","uginanie przedramion ze sztangą"};

    std::map <string, string> plecy_akcesoria = {{"medium","face pulls"},{"advanced","Y - raises"}}; // moze 1 dla medium a 2 dla advanced
    std::map <string, string> triceps {{"basic","prostowanie przedramion na wyciągu"},{"medium","Prostowanie przedramion na TRX"},{"advanced","wyciskanie francuskie"}};
    std::map <string, vector<string>> basic {{"klatka",klatka_basic},{"nplecy",plecy_basic},{"pnogi",nogi_basic},{"biceps",biceps_basic},{"zbrzuch",brzuch_basic}};//,{"brzuch",brzuch_basic}
    std::map <string, vector<string>> medium {{"klatka",klatka_medium},{"pnogi",nogi_medium},{"biceps",biceps_medium},{"barki",barki_medium},{"nplecy",plecy_medium},{"zbrzuch",brzuch_medium}};//,{"brzuch",brzuch_medium}};
    std::map <string, vector<string>> advanced {{"klatka",klatka_advanced},{"nplecy",plecy_advanced},{"pnogi",nogi_advanced},{"biceps",biceps_advanced},{"barki",barki_advanced},{"zbrzuch",brzuch_advanced}};//{"brzuch",brzuch_advanced},


    std::map<string, std::map <string, vector<string> >> trening_map = {{"basic",basic}, {"medium",medium}, {"advanced",advanced}};

};

#endif // CROSSFIT_H
