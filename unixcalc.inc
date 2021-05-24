/*
	Include created by Robson04
	Unix Manager Inc.
*/

#include <a_samp>

forward bool:IsLeapYear(year);
new days_in_month[][] =
{
	{1, 31, "January"},
	{2, 28, "February"},
	{3, 31, "March"},
	{4, 30, "April"},
	{5, 31, "May"},
	{6, 30, "June"},
	{7, 31, "July"},
	{8, 31, "August"},
	{9, 30, "September"},
	{10, 31, "October"},
	{11, 30, "November"},
	{12, 31, "December"}
};

stock UnixToTimeStamp(unix, &year = 0, &month = 0, &day = 0, &hour = 0, &minute = 0, &second = 0)
{
	new tmp_year = 1970, tmp_month = 1, tmp_day = 1, tmp_hour = 0, tmp_minute = 0;
	if(time_zone == true) tmp_hour++;
	new timestamp = unix;
	if(timestamp > 0)
	{
		for(;;)
		{
			new tmp_index = tmp_month - 1;
			if(tmp_minute >= 60)
			{
				tmp_hour++;
				tmp_minute = 0;
			}
			else if(tmp_hour >= 24)
			{
				tmp_day++;
				tmp_hour = 0;
			}
			else if(tmp_month > 12)
			{
				tmp_year++;
				tmp_month = 1;
				tmp_day = 1;
			}
			else if(tmp_day > days_in_month[tmp_index][1])
			{
				tmp_month++;
				tmp_day = 1;
			}
			else
			{
				if(tmp_month == 2 && IsLeapYear(tmp_year) && timestamp >= 24 * 60 * 60 * (days_in_month[tmp_index][1] + 1))
				{
					tmp_month++;
					timestamp -= 24 * 60 * 60 * (days_in_month[tmp_index][1] + 1);
				}
				else if(timestamp >= 24 * 60 * 60 * days_in_month[tmp_index][1])
				{
					tmp_month++;
					timestamp -= 24 * 60 * 60 * days_in_month[tmp_index][1];
				}
				else if(timestamp >= 24 * 60 * 60)
				{
					tmp_day++;
					timestamp -= 24 * 60 * 60;
				}
				else if(timestamp >= 60 * 60)
				{
					tmp_hour++;
					timestamp -= 60 * 60;
				}
				else if(timestamp >= 60)
				{
					tmp_minute++;
					timestamp -= 60;
				}
				else break;
			}
		}
	}
	year = tmp_year;
	month = tmp_month;
	day = tmp_day;
	hour = tmp_hour;
	minute = tmp_minute;
	second = timestamp;
	return 1;
}

stock bool:IsLeapYear(year)
{
	if(year % 2 == 0)
		return true;
	else return false;
}

stock GetMonthName(month)
{
	if(month >= 1 && month <= 12)
		return tmp_month[month - 1][2];
	else return 0;
}
