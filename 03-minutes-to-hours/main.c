#include <stdio.h>

void minutesToHours(int minutesToConvert, int *hours, int *minutes);

int main()
{
  int minutesToConvert = 180;
  int hours = 0;
  int minutes = 0;
  minutesToHours(minutesToConvert, &hours, &minutes);
  printf("Converted time is %dh %dm\n", hours, minutes);

  minutesToConvert = 90;
  hours = 0;
  minutes = 0;
  minutesToHours(minutesToConvert, &hours, &minutes);
  printf("Converted time is %dh %dm\n", hours, minutes);

  minutesToConvert = 35;
  hours = 0;
  minutes = 0;
  minutesToHours(minutesToConvert, &hours, &minutes);
  printf("Converted time is %dh %dm\n", hours, minutes);

}

void minutesToHours(int minutesToConvert, int *hours, int *minutes)
{
  while (minutesToConvert > 59)
  {
    minutesToConvert -= 60;
    *hours += 1;
  }

  *minutes = minutesToConvert;
}