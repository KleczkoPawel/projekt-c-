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
