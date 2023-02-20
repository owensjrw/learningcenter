#include <stdin.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

define TOTALNAME 102
define LONGPHONE 31
define LONGEMAIL 321
define NAMELEN 51
define MAXSTR 256

struct phones
{
  char name[TOTALNAME];
  char number[LONGPHONE];
  uint8_t phonetype;
  struct phone *next;
};

struct email
{
  char name[TOTALNAME];
  char email[LONGEMAIL];
  uint8_t emailtype;
  struct email *next;
};

struct phone_list
{
  char lname[NAMELEN]; //Required field
  char fname[NAMELEN];
  char mi;
  char company[MAXSTR];
  struct phones *numbers;
  struct email *emails;
};

int main(void)
{
  return 0;
}
