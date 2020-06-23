#include "Dai.h"



int main()
{
    Dai bd;

    bd.Add(9999, "Over speed");
    bd.Add(9999, "Drive red traffic light");
    bd.Add(2993, "Lack of license plates");
    bd.Add(9999, "Parking in the wrong place");
    bd.Add(6666, "Participation in illegal racing");
    

    bd.PrintRangeNumber(1000, 10000);
    bd.PrintNumber(2993);


    return 0;
}