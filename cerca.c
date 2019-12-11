
#include <stdio.h>
#include "PGM1-1920-S1-WeeklyExercise-10-TESTING.h"

#define NAME_SIZE 50
#define MAX_PLAYERS 10
#define MAX_CAMPAIGNS 100
typedef char Name[NAME_SIZE];
typedef struct {
     Name character_name;
     Name class_name;
     int level;
     int experience_points;
} Character;
typedef struct {
     Name player_name;
     Character character;
} Player;

typedef struct {     
     Name campaign_name;
     Name game_master;
     int num_players;
     Player players[MAX_PLAYERS];
} Campaign;

int main () {
	Campaign campaigns[MAX_CAMPAIGNS];
	int num_campaigns;

	// Declare your variables here.
    int i, j;

	// This function loads all the information into the array (campaigns) and num_campaigns.
	num_campaigns = loadData(campaigns);

	// 1. Find the average level for all the Characters in all the Campaigns
    int n = 0;
    int lvlAc = 0;
	for(i=0; i<num_campaigns, i++) {
        for(j = 0; j < campaigns[i].num_players; ++j){
            lvlAc += campaigns[i].players[j].character.level;
            n++;
        }
    }
    float media = (float)lvlAc/(float)n;
    printf("The average level for all characters is %f\n", media);
	// 2. Show on the screen, all the information about every player with more than 300000 experience points.
	
    for(i=0; i<num_campaigns, i++) {
        for(j = 0; j < campaigns[i].num_players; ++j){
            if(campaigns[i].players[j].character.experience_points >= 300000){
                printf("\nCampaign name: %s\n",campaigns[i].campaign_name);
                printf("Player name: %s\n", campaigns[i].players[j].player_name);
                printf("Character name: %s\n", campaigns[i].players[j].character.character_name);
                printf("Class name: %s\n", campaigns[i].players[j].character.class_name);
                printf("Level: %d\n", campaigns[i].players[j].character.level);
                printf("Xp: %d", campaigns[i].players[j].character.experience_points);
            }
        }
    }
	return 0;
}
