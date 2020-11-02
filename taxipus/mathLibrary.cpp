#include "mathLibrary.h"

int cost_trip(int distance, Tarif tarif, int trafficJams)
{
    int base_cost = 50;
    int cost_km = 0;
    if (tarif == Econom)
        cost_km = 10;
    else if (tarif == Comfort)
        cost_km = 15;
    else
        cost_km = 20;

    int cost = base_cost + cost_km * distance;
    if (trafficJams > 3 && trafficJams < 5)
        cost += cost * 0.2;
    else if (trafficJams >= 5)
        cost += cost * 0.5;

    return cost;
}
