#include <iostream>
#include <string>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
using namespace std;

int main() {
	cout << "Welcome to Bonemeal!" << endl;
	cout << "You are a corpse who must restore their humanity." << endl;
	cout << "But to do so you must first realize what it is to be human." << endl;
	cout << "+++++++++" << endl << "COMMANDS" << endl << "+++++++++" << endl;
	cout << "Travel" << endl << "Take" << endl << "Examine" << endl << "Talk To" << endl << "+++++++++" << endl;
	


	cout << "Before we begin, tell me, what is your name?" << endl;

	string player_name = "";
	string player_command = "";
	while (player_name.compare("") == 0) {
		getline(cin, player_name);
	}
	

	cout << "Alright, " + player_name + ", your story begins where all good stories begin. At the end..." << endl;
	
	bool player_alive = true;
	int current_room = 0;
	//values for room0
	bool room0_visited = false;
	bool room0_torch_taken = false;
	//values for room1
	bool room1_visited = false;
	bool room1_sword_taken = false;
	bool room1_door_unlocked = false;
	bool room1_talking = false;
	bool room1_chester_visited = false;
	bool room1_chester_dead = false;
	//values for room2
	bool room2_visited = false;
	//values for room3
	bool room3_visited = false;
	bool room3_bandit_dead = false;

	while (player_alive) {
		//ROOM 0
		while (current_room == 0) {
			//if this is the first time the player has entered room0
			if (!room0_visited) {
				cout << "You awaken in a cold, dark ROOM made of stone. You are slow to rise" << endl;
				cout << "Your dry flesh is sallow and peeling. Your limbs are numb and stiff." << endl;
				cout << "You vaguely recall vision of a gun and your own blood." << endl;
				cout << "You don't know where you are but you feel you should not linger here." << endl;
				
				room0_visited = true;
			}
			else {
				cout << "You are in a cold dark, ROOM made of stone." << endl;
			}
			if (!room0_torch_taken) {
				cout << "The only light comes from a flickering TORCH on the wall to your right." << endl;
			}
			cout << "There is a wide doorway to the NORTH." << endl;
			cout << "What will you do?" << endl;
			getline(cin, player_command);

			if (player_command.compare("Travel North") == 0){
				

				if (!room1_visited) {
					cout << "As you approach the doorway a cold wind blows against you." << endl;
					cout << "The wind curls about your ears and you believe you hear a whispering voice." << endl;
					cout << "\"Curiosity is the downfall of many great men.\"" << endl;
				}
				cout << "You travel through the NORTH doorway." << endl;
				if (!room0_torch_taken) {
					cout << "The darkness of the passage surrounds you." << endl;
					cout << "In the darkness you hear a quick whistling of air." << endl;
					cout << "A blade has found your Heart and the darkness becomes eternal." << endl;
					player_alive = false;
					break;
				}
				current_room = 1;
			}
			else if (player_command.compare("Take Torch") == 0) {
				room0_torch_taken = true;
				cout << "You take the TORCH." << endl;
			}
			else if (player_command.compare("Examine Room") == 0) {
				if (room0_torch_taken) {
					cout << "There is nothing to see here. The small stone ROOM is barren." << endl;
				}
				if (!room0_torch_taken) {
					cout << "The only object in the room is the TORCH on the wall." << endl;
				}

			}
			else {
				cout << "I don't understand, try something else." << endl;
			}
		}
		//ROOM 1
		while (current_room == 1) {
			cout << "You are in a ROOM much like the one you awoke in." << endl;
			cout << "A robed FIGURE sits in the North Eastern corner of this ROOM." << endl;
			if (!room1_sword_taken) {
				cout << "A SWORD lays accross the FIGURE's knees." << endl;
			}
			cout << "To the EAST there is a wide wooden door." << endl;
			cout << "What will you do?" << endl;

			getline(cin, player_command);

			if (player_command.compare("Travel East") == 0){
				if (!room1_door_unlocked) {
					cout << "You push the wooden door but it does not budge, it seems to be locked." << endl;
				}
				else {
					cout << "You push the wooden door. Blue light snakes through the grain of the door." << endl;
					cout << "The blue light conforms into a single message." << endl;
					cout << "\"Your fellow man will be your closest ally, and your greatest enemy.\"" << endl;
					cout << "The doorway swings open and light blinds you as you pass through." << endl;
					current_room = 2;
				}
			}
			if (player_command.compare("Take Sword") == 0){
				if (room1_sword_taken) {
					cout << "You already have the SWORD." << endl;
				}
				else{
					cout << "As you reach for the SWORD the FIGURE springs to his feet with surprising speed." << endl;
					cout << "Before you can react the FIGURE drives the SWORD through your Heart." << endl;
					cout << "In your final moment the skeletal face of your killer comes close to yours." << endl;
					cout << "\"The theif and the friend are only separated by CONVERSATION.\"" << endl;
					player_alive = false;
				}
			}

			//Talking to Chester
			else if (player_command.compare("Talk To Figure") == 0) {
				if (room1_chester_dead) {
					cout << "Chester is dead. He can not speak with you." << endl;
				}
				else {
					room1_talking = true;
					cout << "The robed FIGURE looks up at you." << endl;
					cout << "His skeletal face is devoid of flesh. Empty eye sockets focus on you as though he still possessed sight." << endl;
					if (!room1_chester_visited) {
						cout << "\"Hello, " << player_name << ", I am Chester.\"" << endl;
						cout << "\"Many come to me in blindness. I am pleased to see that you didn't let your curiousity cloud your judgement.\"" << endl;
						room1_chester_visited = true;
					}
					else {
						cout << "\"Hello again, " << player_name << ".\"" << endl;
					}
					while (room1_talking) {
						cout << "TOPICS: CHESTER---SWORD---DOOR---GOODBYE" << endl;
						cout << "What would you like to discuss?" << endl;

						getline(cin, player_command);
						if (player_command.compare("Chester") == 0) {
							cout << "\"That is I. My purpose is to judge those who enter here.\"" << endl;
						}
						else if (player_command.compare("Sword") == 0) {
							cout << "\"You have entered this place and greeted me. You have shown interest in your fellow man." << endl;
							cout << "\"I shall give you this blade, let it be your key and your guide.\"" << endl;
							cout << "Chester hands you the Sword. Upon accepting his gift blue light escapes from his eye sockets and his skull falls from his body, shattering on the floor." << endl;
							room1_sword_taken = true;
							cout << "The blue light creeps along the floor and seems to soak into the grain of the door." << endl;
							room1_door_unlocked = true;
							room1_chester_dead = true;
							room1_talking = false;
						}
						else if (player_command.compare("Door") == 0) {
							cout << "\"It is locked as it should be to those who do not have the key.\"" << endl;
						}
						else if (player_command.compare("Goodbye") == 0) {
							cout << "\"Goodbye" + player_name << ".\"" << endl;
							room1_talking = false;
						}
					}
				}
			}
			else {
				cout << "I don't understand. Try something else." << endl;
			}

		}
		while (current_room == 2) {
			if (!room2_visited) {
				cout << "You emerge outdoors, with a sky of gray above." << endl;
				cout << "The door to the WEST closes behind you." << endl;
				
			}
			else{
				cout << "You are in an open field." << endl;
				cout << "To the WEST is a wide wooden DOOR." << endl;
				
			}
			cout << "To the EAST the land slopes down into a large forested valley." << endl;
			cout << "What will you do?" << endl;
			getline(cin, player_command);

			if (player_command.compare("Travel East") == 0) {
				cout << "You travel down the slope to the EAST towards the forested valley." << endl;
				current_room = 3;
			}
			else if (player_command.compare("Examine Area") == 0) {
				cout << "There is nothing to see here." << endl;
			}
			else {
				cout << "I don't understand. Try something else." << endl;
			}
		}
		while (current_room == 3) {
			if (!room3_visited) {
				room3_visited = true;
				cout << "You enter a thick forest of bizare trees." << endl;
				cout << "After walking for a while you enter a clearing where a campfire has been recently extinguished." << endl;
				cout << "There is a small path between the trees to the NORTH." << endl;
				cout << "You hear a branch snap from somewhere above you." << endl;
				cout << "You step back in time to avoid the swing of a blade." << endl;
				cout << "It's wielder, a scrawny man in rags, stares at you, he is clearly looking for a fight." << endl;

				cout << "****FIGHT INITIATED****" << endl;
				cout << "Fight by selecting how much energy (0- 10) to exert with your sword swing. Selecting 0 blocks all incoming damage." << endl;
				cout << "The difference in energy determines who is damaged by the bout. Stamina is lost with each attack, and regenerated each turn." << endl;
				int player_choice = 0;
				int player_health = 20;
				int player_stam = 10;
				int enemy_health = 10;
				int enemy_stam = 10;
				int enemy_swing = 0;
				srand(time(NULL));
				while (!room3_bandit_dead){
					if (player_stam < 10) {
						player_stam += 4;
					}
					if (player_stam > 10) {
						player_stam = 10;
					}
					cout << "Your health is: " + player_health << endl;
					cout << "Your stamina is: " + player_stam << endl;
					cout << "Select attack strength." << endl;
					cin >> player_choice;
					if (player_choice > player_stam){
						player_choice = player_stam;
					}
					else if (player_choice < 0) {
						player_choice = 0;
					}
					player_stam -= player_choice;

					enemy_swing = rand() % enemy_stam;

					cout << "The bandit swings with " << enemy_swing << " strength." << endl;
					enemy_stam -= enemy_swing;

					if (player_choice == 0) {
						cout << "You defend and take no damage." << endl;
					}
					else {
						cout << "You swing with " << player_choice << " strength." << endl;
						if (player_choice > enemy_swing) {
							enemy_health -= player_choice - enemy_swing;
							cout << "The bandit took " << player_choice - enemy_swing << " damage!" << endl;
						}
						else if (player_choice < enemy_swing) {
							player_health -= enemy_swing - player_choice;
							cout << "You took " << enemy_swing - player_choice << " damage!" << endl;
						}
						else {
							cout << "Your blades collide with equal strength. No damage is dealt." << endl;
						}
					}
					if (player_health <= 0) {
						cout << "You have been dealt a fatal blow." << endl;
						player_alive = false;
						break;
					}
					else if (enemy_health <= 0) {
						room3_bandit_dead = true;
						cout << "You have dealt a fatal blow to the bandit and he falls over dead." << endl;
						cout << "A voice is brought to you on the wind." << endl;
						cout << "\"Some of those who walk your path will not recognize their bretheren. There is no greater evil.\"" << endl;
					}
					else{
						player_stam += 4;
						enemy_stam += 4;
					}

				}
				//FINISHED BANDIT FIGHT
			}
			//HAS BEEN HERE BEFORE

			
			cout << "You are in a clearing where a campfire has been recently extinguished." << endl;
			cout << "The bandit's dead body lays on the ground here." << endl;
			cout << "There is a small path through the trees to the NORTH." << endl;
				
			
			cout << "What would you like to do?" << endl;
			getline(cin, player_command);
			if (player_command.compare("Travel North") == 0){
				current_room = 4;
				cout << "You work your way NORTH through the tangle of trees." << endl;
			}
			else {
				cout << "You can not do that, try something else." << endl;
			}



		}

		while (current_room == 4) {
			cout << "You come out of the forest to face a deep ravine." << endl;
			cout << "The wind brings another whisper to your ears." << endl;
			cout << "\"Sometimes when we have lost our friends and do not know who our enemy is any more.." << endl;
			cout << "\"We must take a leap of faith.\"" << endl;
			cout << "Looking around you realize the only way to travel is NORTH." << endl;
			cout << "What would you like to do?" << endl;
			getline(cin, player_command);
			if (player_command.compare("Travel North") == 0){
				cout << "You approach the edge of the ravine and let yourself fall over the edge." << endl;
				cout << "As you plumet into the darkness your sword falls away from you, as does your torch." << endl;
				cout << "The darkness begins to glow a light blue and you realize the wind has stopped." << endl;
				cout << "Instead, the sound of sirens fills your ears. You are on a stretcher facing the sky." << endl;
				cout << "Paramedics are lifting you now into an ambulance." << endl;
				cout << "As you lay there, you notice the young paramedic's name tag on his uniform." << endl;
				cout << "It reads: \"CHESTER\"" << endl;
				player_alive = false;
				current_room = 5;
			}
		}
}
	

	//Player has Died
	if (current_room != 5){
		cout << "GAME OVER" << endl;
	}
	else {
		cout << "Congratulations. You have made it back to the world of the living." << endl;
	}
	getline(cin, player_command);
	

	


	return 0;
}