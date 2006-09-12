
/*
struct timeZoneTable_
{
  unsigned char name[8];
  int gmtOffset;
  char dstFlag;
};

typedef struct timeZoneTable_ timeZoneTable;
const timeZoneTable tzEntry[] = {
  {"-12", -3600 * 12, 0},
  {"-11", -3600 * 11, 0},
  {"-10", -3600 * 10, 0},
  {"-09", -3600 * 9, 1},
  {"-08", -3600 * 8, 1},
  {"-07 1", -3600 * 7, 0},
  {"-07 2", -3600 * 7, 1},
  {"-06 1", -3600 * 6, 0},
  {"-06 2", -3600 * 6, 1},
  {"-05 1", -3600 * 5, 0},
  {"-05 2", -3600 * 5, 1},
  {"-04 1", -3600 * 4, 0},
  {"-04 2", -3600 * 4, 1},
  {"-03.5", -3600 * 3.5, 1},
  {"-03 1", -3600 * 3, 0},
  {"-03 2", -3600 * 3, 1},
  {"-02", -3600 * 2, 0},
  {"-01", -3600, 2},
  {"+00 1", 0, 0},
  {"+00 2", 0, 2},
  {"+01 1", 3600, 0},
  {"+01 2", 3600, 2},
  {"+02 1", 3600 * 2, 0},
  {"+02 2", 3600 * 2, 2},
  {"+03", 3600 * 3, 0},
  {"+04", 3600 * 4, 0},
  {"+05", 3600 * 5, 0},
  {"+06", 3600 * 6, 0},
  {"+07", 3600 * 7, 0},
  {"+08 1", 3600 * 8, 0},
  {"+08 2", 3600 * 8, 0},
  {"+09", 3600 * 9, 0},
  {"+10 1", 3600 * 10, 0},
  {"+10 2", 3600 * 10, 4},
  {"+11", 3600 * 11, 0},
  {"+12 1", 3600 * 12, 0},
  {"+12 2", 3600 * 12, 4},
};
const int tzEntrySize = sizeof (tzEntry) / sizeof (timeZoneTable);
*/

struct dstTable_
{
  unsigned char startDay[17];
  unsigned char endDay[17];
  unsigned char startMonth;
  unsigned char endMonth;
  unsigned char diffMonth;
  char resv;
  int dstBias;
};
typedef struct dstTable_ dstTable;
	// table mod by Eko, 1.apr.06
const dstTable dstEntry[] = {
  //dst #0: nothing to do
  {{}, {}, 0, 0, 0, 0, 0},
  //dst #1:  3 last sun - 10 last sun, but time diff=0
  { 26, 25, 30, 29, 28, 27, 25, 31, 30, 29, 27, 26, 25, 31, 29, 28, 27},
   {29, 28, 26, 25, 31, 30, 28, 27, 26, 25, 30, 29, 28, 27, 25, 31, 30}, 3, 10, 0, 0, 0},
  //dst #2:  4 first sun - 10 last sun
  {{2, 1, 6, 5, 4, 3, 1, 7, 6, 5, 3, 2, 1, 7, 5, 4, 3},
   {29, 28, 26, 25, 31, 30, 28, 27, 26, 25, 30, 29, 28, 27, 25, 31, 30}, 4, 10, 0, 0, 3600},
  //dst #3:  3 last sun - 10 last sun
  {{26, 25, 30, 29, 28, 27, 25, 31, 30, 29, 27, 26, 25, 31, 29, 28, 27},
   {29, 28, 26, 25, 31, 30, 28, 27, 26, 25, 30, 29, 28, 27, 25, 31, 30}, 3, 10, 0, 0, 3600},
  //dst #4: 10 last sun - 3 last sun
  {{29, 28, 26, 25, 31, 30, 28, 27, 26, 25, 30, 29, 28, 27, 25, 31, 30},
   {26, 25, 30, 29, 28, 27, 25, 31, 30, 29, 27, 26, 25, 31, 29, 28, 27}, 10, 3, 1, 0, 3600},
  //dst #5 US 2007: 2nd Sun Mar --> 1st Sun Nov
  {{12, 11, 9, 8, 14, 13, 11, 10, 9, 8, 13, 12, 11, 10, 8, 14, 13},
   {5, 4, 2, 1, 7, 6, 4, 3, 2, 1, 6, 5, 4, 3, 1, 7, 6}, 3, 11, 0, 0, 3600},
//  06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 <-- year
};
