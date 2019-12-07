#include <stdio.h>
#include <string.h>

#define MAX_STR 50
#define MAX 50

typedef char String50 [MAX_STR];

typedef struct{
  String50 first_name;        // first name
  String50 first_last_name;   // first last name
  String50 second_last_name;  // second last name
} NameType;

typedef struct {
   NameType full_name;       // full name
   String50 address;         // address
   int age;                  // age  } VoterType;
} VoterType;

int main() {
  VoterType votants[MAX];
  int i, numero_votants, voter_age;
  char buf[MAX_STR];

  printf("Input number of voters: ");
  scanf("%d", &numero_votants);

  for(i = 0; i < numero_votants; i++) {
      printf("Input name of voter %d: ",i+1);
      scanf("%s", votants[i].full_name.first_name);
      scanf("%s", votants[i].full_name.first_last_name);
      scanf("%s", votants[i].full_name.second_last_name);
      getchar();
      printf("Input address of voter %d: ", i+1);
      fgets(votants[i].address , MAX_STR, stdin);
      printf("Input ages of voter %d: ", i+1);
      scanf("%d", & votants[i].age);
  }
  printf("Input voting age: ");
  scanf("%d", &voter_age);
  printf("\n");
  printf("Eligible voters:\n");
  for(i = 0; i< numero_votants; i++) {
      if(votants[i].age > voter_age){
        printf("%s, %s (%d)\n", votants[i].full_name.first_last_name,
                votants[i].full_name.first_name, votants[i].age);
      }
  }



  return 0;
}
