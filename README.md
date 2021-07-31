# Unix Calculator for San Andreas MultiPlayer
The use of unix for date is still popular. This include let you determination data from seconds of 1970-01-01.
It's very easy to use and is very useful.

### Type it to your code:
```pawn
#include "unix-converter.inc"
```

###### Functions:
```pawn
UnixToTimeStamp(unix, &year = 0, &month = 0, &day = 0, &hour = 0, &minute = 0, &second = 0);
bool:IsLeapYear(year);
GetMonthName(month);
```
###### Parameters:

#### UnixToTimeStamp
- unix - seconds int of 1970-01-01
- year - returns unix year of today date
- month - returns unix month of today date
- day - returns unix day of today
- hour, minute, seconds - returs unix time of today.

#### IsLeapYear
- returns boolean if year is leap.

#### GetMonthName
- returns month name.


###### Example ussage:
```pawn
#include "unix-converter.inc"
main()
{
    #define example_unix 1588669331 //Tuesday, 5 May 2020 09:02:11
    new year, month, day, hour, minute, second;
    UnixToTimeStamp(example_unix, year, month, day, hour, minute, second);
    printf("Unix-calc: %i-%i-%i %i:%i:%i", year, month, day, hour, minute, second);
}
```


