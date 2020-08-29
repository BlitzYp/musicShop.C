#include <stdio.h>
#include <string.h>

typedef struct instrument
{
  char *name;
  int price;
} instrument;

struct shop
{
  char *name;
  instrument *instruments[10];
};

struct shop createShop();
instrument *createIns();
void printShop(struct shop *s);
int addInstrument(struct shop *s);

int main(void)
{
  char input[20];
  char command[20];
  struct shop *s;
  printf("Enter your first command!: ");
  while (fgets(input, 20, stdin))
  {
    sscanf(input, "%s", command);
    if (!strcmp(command, "createShop"))
    {
      struct shop res = createShop();
      s = &res;
      printf("Shop created: %s\n", s->name);
      printf("Command: ");
      continue;
    }
    else if (!strcmp(command, "addInstrument"))
    {
      int res = addInstrument(s);
      printf("Instrument added!\n");
      printf("Instrument name: %s\nInstrument price: %d\n", s->instruments[res]->name, s->instruments[res]->price);
      printf("Command: ");
    }
    else if (!strcmp(command, "printShop"))
    {
      printShop(s);
      printf("Command: ");
      continue;
    }
    else
    {
      printf("Thanks for using my creation! :)");
      break;
    }
  }
  return 0;
}

struct shop createShop()
{
  struct shop s;
  printf("Shop name: ");
  char name[30];
  fgets(name, 30, stdin);
  s.name = name;
  return s;
}

int addInstrument(struct shop *s)
{
  int i = 0;
  while (i < 10)
  {
    if (s->instruments[i] == NULL)
    {
      struct instrument *ins = createIns();
      s->instruments[i] = ins;
      break;
    }
    else
    {
      i++;
    }
  }
  return i;
}

instrument *createIns()
{
  printf("Instrument name: ");
  char name[30];
  fgets(name, 30, stdin);
  int price;
  printf("price: ");
  scanf("%d", &price);
  struct instrument *ins;
  ins->name = name;
  ins->price = price;
  return ins;
}

void printShop(struct shop *s)
{
  int i = 0;
  printf("%s", s->name);
  while (i < 10)
  {
    if (s->instruments[i] != NULL)
    {
      printf("Instrument name: %s\n", s->instruments[i]->name);
      i++;
    }
  }
}