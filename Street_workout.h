#ifndef STREET_WORKOUT_T_INCLUDED
#define STREET_WORKOUT_T_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Service.h"
#include <stdlib.h>

using namespace std;

class Street_workout{
public:

Street_workout(string poziom, bool izometria, string cel);


//private:

string poziom = Street_workout::poziom;
string cel = Street_workout::cel;
bool izometria = Street_workout::izometria;
json::value generatedPlan;
std::map <string, vector<string> > trening;
std::map <string, string> is_isometric {{"medium","medium_izometria"},{"advanced","advanced_izometria"}};
std::map <string, string> rodzaj_treningu {{"sila","ilość powtórzeń: 6"},{"masa","ilość powtórzeń: 9"},{"wtrzymałość","zamykamy ćwiczenia w obwód i wykonujemy je kolejno z przerwą 5s między ćwiczeniami i 120s między obwodami"}};

vector <string> klatka_basic  = {"pompki z rękami na podwyższeniu","pompki szwedzkie"};
vector <string> klatka_medium = {"pompki na poręczach","pompki klasyczne"};
vector <string> klatka_advanced = {"pompki na poręczach w pozycji tuck-planche","pompki z wychyleniem tułowia w przód (nadgarstki na wysokości bioder)"};
vector <string> klatka_izometria_medium = {"tuck planche hold - 6s","pompki z pauzą na dole 5s"};
vector <string> klatka_izometria_advanced = {"planche lean hold - 6s","pompi w pozycji tuck planche z pauzą na dole 5s"};

vector <string> nogi_basic = {"przysiady","wykroki w przód"};
vector <string> nogi_medium = {"przysiady bułgarskie","krzesełko"};
vector <string> nogi_advanced = {"przysiad jednonóż","żuraw"};
vector <string> nogi_izometria_medium = {"krzesełko - 20s"};
vector <string> nogi_izometria_advanced = {"krzesełko jednonóż - 20s"};

vector <string> plecy_basic = {"podciągnięcia australijskie","negatywne podciągnięcia"};
vector <string> plecy_medium = {"podciągnięcia nachwytem","podciągnięcia nachwytem szeroko"};
vector <string> plecy_advanced = {"podciągnięcia w pozycji tuck front lever","podciąganie łucznicze"};
vector <string> plecy_izometria_medium = {"tuck front lever hold - 6s","podciągnięcia z pauzą w połowie i na górze ruchu 5s"};
vector <string> plecy_izometria_advanced = {"straddle front lever hold - 6s","podciągnięcia łucznicze z pauzą 5 sec w połowie i na górze ruchu"};

vector <string> brzuch_basic = {"spięcia brucha leżąc","uginanie oderwanych od ziemi nóg leżąc"};
vector <string> brzuch_medium = {"krzesełka z użyciem drażka","scyzoryki z ugiętymi nogami"};
vector <string> brzuch_advanced = {"wznosy prostych nóg do pozycji L-sit z użyciem drążka","tzw. wycieraczki z użyciem drążka"};
vector <string> brzuch_izometria_medium = {"plank hold - 20s","L-sit hold - 5s"};
vector <string> brzuch_izometria_advanced = {"dragon flag hold - 6s","L-sit hold - 8s"};

vector <string> brzuch_skos_medium = {"krzesełka bokiem", "plank bokiem"};
vector <string> brzuch_skos_advanced = {"tzw. wycieraczki z użyciem drążka","wznosy tułowia do pozycji human flag"};
vector <string> brzuch_izometria_skos_medium = {"plank bokiem"};
vector <string> brzuch_izometria_skos_advanced = {"human flag hold - 6s"};

vector <string> barki_medium = {"pompki pike","stanie na rękach z oparciem nóg"};
vector <string> barki_advanced = {"pompki na rękach z oparciem nóg","stanie na jednej ręce z oparciem nóg"};
vector <string> barki_izometria_medium = {"stanie na rękach z oparciem nóg - 10s","tuck human flag hold - 5s"};
vector <string> barki_izometria_advanced = {"stanie na ręce z oparciem nóg - 6s", "human flag hold - 6s"};

vector <string> biceps_medium = {"podciągnięcia podchwytem"};
vector <string> biceps_advanced = {"podciągnięcia podchwytem z wąskim chwytem"};
vector <string> biceps_izometria_medium = {"podciągnięcia podchwytem z pauzą w połogwie i na górze ruchu 5s"};
vector <string> biceps_izometria_advanced = {"podciągnięcia podchwytem wąsko z pauzą w połogwie i na górze ruchu 5s"};

std::map <string, vector<string>> basic {{"klatka",klatka_basic},{"plecy",plecy_basic},{"nogi",nogi_basic},{"brzuch",brzuch_basic}};
std::map <string, vector<string>> medium {{"klatka",klatka_medium},{"plecy",plecy_medium},{"nogi",nogi_medium},{"brzuch",brzuch_medium}};
std::map <string, vector<string>> advanced {{"klatka",klatka_advanced},{"plecy",plecy_advanced},{"nogi",nogi_advanced},{"brzuch",brzuch_advanced},{"barki",barki_advanced},{"biceps",biceps_advanced}};
std::map <string, vector<string>> medium_izometria{{"klatka",klatka_izometria_medium},{"plecy",plecy_izometria_medium},{"nogi",nogi_izometria_medium},{"brzuch",brzuch_izometria_medium},{"barki",barki_izometria_medium},{"biceps",biceps_izometria_medium}};
std::map <string, vector<string>> advanced_izometria{{"klatka",klatka_izometria_advanced},{"plecy",plecy_izometria_advanced},{"nogi",nogi_izometria_advanced},{"brzuch",brzuch_izometria_advanced},{"barki",barki_izometria_advanced},{"biceps",biceps_izometria_advanced}};

std::map<string, std::map <string, vector<string> >> trening_map = {{"basic",basic}, {"medium",medium}, {"advanced",advanced},{"medium_izometria",medium_izometria},{"advanced_izometria",advanced_izometria}};

void treningi();
//std::map <string, vector<string> > trening = trening_map[poziom];
//vector <vector <string>> basic = {klatka_basic,plecy_basic,nogi_basic,brzuch_basic};
//vector <vector <string>> medium = {klatka_medium,plecy_medium,nogi_medium,brzuch_medium,barki_medium,biceps_medium};
//vector <vector <string>> advanced = {klatka_advanced, plecy_advanced, nogi_advanced, brzuch_advanced, barki_advanced, biceps_advanced};

//std::map<string, vector <vector <string>>> basic_map = {{"basic",basic}, {"medium",medium}, {"advanced",advanced}};

};











#endif

