#include<stdio.h>
#include<conio.h>

int determineleapyear(int year);
int days_in_month[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
  {
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember"
  };

int determinedaycode(int year)
{
  int d1, d2, d3;
  d1 = year/4.0;
  d2 = year/100.;
  d3 = year/400.;
  return 1 + (year + d1 + d2 + d3 + 1) % 7;
}

int determineleapyear(int year)
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

void calendar(int year, int month, int daycode)
{
    int day;
    printf("%s", months[month]);
    printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

      //Correct the position for the first date
      for (day = 1; day <= 1 + daycode * 5; day++)
    {
      printf(" ");
    }

      //Print all the dates for one month
      for (day = 1; day <= days_in_month[month]; day++)
    {
      printf("%2d", day);

      //Is day before Sat? Else start next line Sun.
      if ((day + daycode) % 7 > 0)
	printf("   ");
      else
	printf("\n ");
    }
      // Set position for next month
      daycode = (daycode + days_in_month[month]) % 7;

      if (determineleapyear(year))
	days_in_month[2] = 29;
      printf("\n     %s %d\n", months[month], year);
}

//------------------------------------------
int main() {
  int daycode, month, year;
  clrscr();

   printf("\nEnter the month: ");
   scanf("%d", &month);
   if (month < 1 || month > 12)
   {
	printf("Error: month must be in range 1..12");
	return printf("\nEnter the month: ");
	scanf("%d", &month);
   }

   printf("\nEnter the year: ");
   scanf("%d", &year);
   if (year < 0)
   {
	printf("Error: year must be > 0");
	return scanf("%d", &year);
   }

   daycode = determinedaycode(year);
   calendar(year, month, daycode);
   printf("\n");

   getch();
   return 0;
}