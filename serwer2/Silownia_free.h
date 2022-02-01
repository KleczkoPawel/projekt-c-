#ifndef SILOWNIA_FREE_H
#define SILOWNIA_FREE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Service.h"
#include <stdlib.h>

class Silownia_free
{
    public:
        Silownia_free(string,string,string,string);
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

    vector <string> klatka_basic  = {"wyciskanie leżąc","wyciskanie leżąc"};
    vector <string> klatka_medium = {"wycislanie na ujemnym skosie","wyciskanie na ujemnym skosie"};// + akcesoria po 2 serie
    vector <string> klatka_advanced = {"wyciskanie leżąc","rozpiętki","wyciskanie na dodatnim skosie","wyciskanie na ujemnym skosie"};
    vector <string> klatka_izometria_medium = {"wyciskanie leżąc z pauzą 5s w połowie ruchu","rozpiętki z pauzą 5s w fazie największego rozciągnięcia"};
    vector <string> klatka_izometria_advanced = {"wyciskanie na ujemnym skosie z pauzą 5s w połowie ruchu","rozpiętki z pauzą 5s w fazie największego rozciągnięcia","wyciskanie leżąc z pauzą 5s w połowie ruchu","wyciskanie na dodatnim skosie z pauzą 5s w połowie ruchu"};
    vector <string> klatka_akcesoria = {"dipy","pompki z ciężarem"};

    vector <string> nogi_basic = {"front squat","martwy ciąg"};
    vector <string> nogi_medium = {"siady (back squat)","martwy ciąg"}; //+akcesoria + akcesoria po 2 serie
    vector <string> nogi_advanced = {"siady (back squat)","przysiady bułgarskie z hantlami","martwy ciąg","front squat"};
    vector <string> nogi_izometria_medium = {"siady (back squat) z pauzą 5s na dole ruchu","martwy ciąg z pauzą 5s w połowie ruchu"};
    vector <string> nogi_izometria_advanced = {"front squat z pauzą 5s na dole ruchu","martwy ciąg z pauzą 5s w połowie ruchu","siady (back squat) z pauzą 5s na dole ruchu","przysiady bułgarskie z pauzą 5s w połowie ruchu"};
    vector <string> nogi_akcesoria = {"wykroki w przód z hantlami","żurawie na maszynie"};
    string zurawie = {"żurawie na maszynie"};
    string zurawie_izometria = {"żurawie na maszynie z pauzą 5s w połowie ruchu"};

    vector <string> plecy_basic = {"ściągnięcia drążka wyciągu górnego","wiosłowanie w oparciu o ławkę"};
    vector <string> plecy_medium = {"podciągnianie na drążku / podciągnięcia negatywne","wiosłowanie sztangą w opadzie tułowia"};// + akcesoria
    vector <string> plecy_advanced = {"przyciągania górnej części ramion zza głowy w kierunku tułowia leżąc (sztanga)","wiosłowanie sztangą w opadzie tułowia","wiosłowanie hantlem","podciąganie na drążku"}; // + akcesoria
    vector <string> plecy_izometria_medium = {"ściągnięcia drążka wyciągu górnego z pauzą 5s w połowie ruchu","wiosłowanie w oparciu o ławkę z pauzą 5s w połowie ruchu"};
    vector <string> plecy_izometria_advanced = {"podciągnięcia z pauzą w połowie ruchu 5s","wiosłowanie sztangą w opadzie tułowia z pauzą 5s w połowie ruchu"};

    vector <string> brzuch_basic = {"spięcia brucha leżąc","uginanie oderwanych od ziemi nóg leżąc"};
    vector <string> brzuch_medium = {"krzesełka z użyciem drażka","scyzoryki z ugiętymi nogami"};
    vector <string> brzuch_advanced = {"wznosy prostych nóg do pozycji L-sit z użyciem drążka","rotacja boczna na wyciągu"};
    vector <string> brzuch_izometria = {"plank hold - 20s","L-sit hold - 5s"};

    vector <string> brzuch_skos = {"spacer farmera jednorącz", "plank bokiem"};
    vector <string> brzuch_izometria_skos = {"plank bokiem","plank bokiem"};

    vector <string> barki_medium = {"wyciskanie żołnierskie","Landmine press"};
    vector <string> barki_advanced = {"wyciskanie żołnierskie","wznosy hantli bokiem"};
    vector <string> barki_izometria_medium = {"wyciskanie żołnierskie z pauzą 5s w połowie ruchu","wyciskanie żołnierskie z pauzą 5s w połowie ruchu"};
    vector <string> barki_izometria_advanced = {"wyciskanie żołnierskie z pauzą 5s w połowie ruchu","wznosy hantli bokiem z pauzą 5s w połowie ruchu"};

    vector <string> biceps_basic = {"uginanie przedramion z hantlami","uginanie przedramion na modlitewniku"};
    vector <string> biceps_medium = {"uginanie przedramion z hantlami chwytem młotkowym ","uginanie przedramion na modlitewniku"};
    vector <string> biceps_advanced = {"uginanie przedramion ułożonych za linią tułowia leżąc na dodatnim skosie - hantle","podciąganie podchwytem"};
    vector <string> biceps_izometria_medium = {"uginanie przedramion z hantlami chwytem młotkowym z pauzą 5s w połowie ruchu","uginanie przedramion na modlitewniku z pauzą 5s w połowie ruchu"};
    vector <string> biceps_izometria_advanced = {"uginanie przedramion ułożonych za linią tułowia leżąc na dodatnim skosie - hantle z pauzą 5s w połowie ruchu","uginanie przedramion na modlitewniku z pauzą 5s w połowie ruchu"};

    std::map <string, string> plecy_akcesoria = {{"medium","face pulls"},{"advanced","Y - raises"}}; // moze 1 dla medium a 2 dla advanced
    std::map <string, string> triceps {{"basic","prostowanie przedramion na wyciągu"},{"medium","Prostowanie przedramion na TRX"},{"advanced","wyciskanie francuskie"}};
    std::map <string, vector<string>> basic {{"klatka",klatka_basic},{"nplecy",plecy_basic},{"pnogi",nogi_basic},{"biceps",biceps_basic},{"zbrzuch",brzuch_basic}};//,{"brzuch",brzuch_basic}
    std::map <string, vector<string>> medium {{"klatka",klatka_medium},{"pnogi",nogi_medium},{"biceps",biceps_medium},{"barki",barki_medium},{"nplecy",plecy_medium},{"zbrzuch",brzuch_medium}};//,{"brzuch",brzuch_medium}};
    std::map <string, vector<string>> advanced {{"klatka",klatka_advanced},{"nplecy",plecy_advanced},{"pnogi",nogi_advanced},{"biceps",biceps_advanced},{"barki",barki_advanced},{"zbrzuch",brzuch_advanced}};//{"brzuch",brzuch_advanced},
    std::map <string, vector<string>> medium_izometria{{"klatka",klatka_izometria_medium},{"plecy",plecy_izometria_medium},{"nogi",nogi_izometria_medium},{"brzuch",brzuch_izometria},{"barki",barki_izometria_medium},{"biceps",biceps_izometria_medium}};
    std::map <string, vector<string>> advanced_izometria{{"klatka",klatka_izometria_advanced},{"plecy",plecy_izometria_advanced},{"nogi",nogi_izometria_advanced},{"brzuch",brzuch_izometria},{"barki",barki_izometria_advanced},{"biceps",biceps_izometria_advanced}};

    std::map<string, std::map <string, vector<string> >> trening_map = {{"basic",basic}, {"medium",medium}, {"advanced",advanced},{"medium_izometria",medium_izometria},{"advanced_izometria",advanced_izometria}};

};

#endif // SILOWNIA_FREE_H
