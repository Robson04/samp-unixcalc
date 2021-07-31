#include "a_samp.inc"
#include "unix-converter.inc"

main()
{
    #define example_unix 1588669331 //Tuesday, 5 May 2020 09:02:11
    new year, month, day, hour, minute, second;
    UnixToTimeStamp(example_unix, year, month, day, hour, minute, second);
    printf("Unix-calc: %i-%i-%i %i:%i:%i", year, month, day, hour, minute, second);
}
