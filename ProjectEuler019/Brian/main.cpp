// You are given the following information, but you may prefer to do some
// research for yourself.
//
//  - 1 Jan 1900 was a Monday
//  - Thirty days has September,
//    April, June, and November.
//    All the rest have thirty-one,
//    saving February alone,
//    which has twenty-eight, rain or shine.
//    And on leap years, twenty-nine.
//  - A leap year occurs on any year evenly divisible by 4,
//    but not on a century unless it is divisible by 400.
//
// How many Sundays fell on the first of the month during the twentieth
// century? (1 Jan 1901 to 31 Dec 2000)

#include <stdio.h>
#include <stdlib.h>

// array holding the number of days in each month
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// program entry point
int main(int argc, char **argv) {

	// loop through all of the years in the 20th century
	int day = 2, mondays = 0; /* Jan 01 2001 is a Tuesday */
	for (int year = 1901; year < 2001; year ++) {
		// update the days in february based on the year
		if (year % 4 == 0) {
			// check if the year is a century
			if (year % 100 == 0) {
				// check if the century is divisible by 4
				if (year % 400 == 0) {
					// this year is a leap year
					days[1] = 29;
				} else {
					// this year is not a leap year
					days[1] = 28;
				}
			} else {
				// this year is a leap year
				days[1] = 29;
			}
		} else {
			// this year is not a leap year
			days[1] = 28;
		}
		// loop through all of the months in the year
		for (int month = 0; month < 12; month ++) {
			// add the number of days for the current month
			day = (day + days[month]) % 7;
			// check if this is a monday
			if (day == 0) mondays ++;
		}
	}

	// output the solution
	printf("the answer is %d.\n", mondays);

}
