/*


                          @@@@@@@  @@@  @@@   @@@@@@   @@@@@@@  @@@@@@@@
                          @@@@@@@  @@@@ @@@  @@@@@@@@  @@@@@@@  @@@@@@@@
                            @@!    @@!@!@@@  @@!  @@@    @@!         @@!
                            !@!    !@!!@!@!  !@!  @!@    !@!        !@!
                            @!!    @!@ !!@!  @!@  !@!    @!!       @!!
                            !!!    !@!  !!!  !@!  !!!    !!!      !!!
                            !!:    !!:  !!!  !!:  !!!    !!:     !!:
                            :!:    :!:  !:!  :!:  !:!    :!:    :!:
                             ::    ::   ::   ::::: ::     ::    :: ::::
                             :     ::    :    : :  :      :     : :: : :


___ _  _ ____    _  _ _ ____ _  _ ___    ____ ____    ___ _  _ ____    ___  ____ _  _ ___  _ ____ ____

 |  |__| |___    |\ | | | __ |__|  |     |  | |___     |  |__| |___      /  |  | |\/| |__] | |___ [__ 
 |  |  | |___    | \| | |__] |  |  |     |__| |        |  |  | |___     /__ |__| |  | |__] | |___ ___]
______________________________________________________________________________________________________


Copyright (C) 2018-2026 Stefano Peris

Email: stefanoperis.github@gmail.com
Github repository: <https://github.com/RetroFloppy77/TNOTZ>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://gnu.org>.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>

#include "termcolor.hpp"

using namespace std;

// Prototipi delle funzioni
int randomNum(int max); 
void incorrect(); 
void zHealthCheck();
void pHealthCheck();
void mostraMorteASCII();

// Variabili globali di gioco
int zAttackChance;
int playerAttackChance;
signed int playerHealth = 15;
signed int zombieHealth = 6;

int main() {
    // Inizializzazione del seme dei numeri casuali (eseguita UNA sola volta qui)
    srand(static_cast<unsigned int>(time(0)));

    // Imposta la dimensione del terminale (altezza 40, larghezza 90)
    cout << "\e[8;40;90t";

    // Pulisce lo schermo
    system("cls");

    // Intro ASCII
    cout << R"(
        
        @@@@@@@  @@@  @@@   @@@@@@   @@@@@@@  @@@@@@@@
        @@@@@@@  @@@@ @@@  @@@@@@@@  @@@@@@@  @@@@@@@@
          @@!    @@!@!@@@  @@!  @@@    @@!         @@!
          !@!    !@!!@!@!  !@!  @!@    !@!        !@!
          @!!    @!@ !!@!  @!@  !@!    @!!       @!!
          !!!    !@!  !!!  !@!  !!!    !!!      !!!
          !!:    !!:  !!!  !!:  !!!    !!:     !!:
          :!:    :!:  !:!  :!:  !:!    :!:    :!:
          ::     ::   ::   ::::: ::     ::    :: ::::
          :      ::    :    : :  :      :     : :: : :
        
                  THE NIGHT OF THE ZOMBIES
                            BY
                (C) 2018-2026 STEFANO PERIS

    )" << '\n';

    cout << "\n\n\n";

    // Creazione del personaggio
    cout << "Enter your name: ";
    char playerName[20];
    cin.getline(playerName, 20);

    string gender;
    cout << "Enter your gender <m,f>: ";
    cin >> gender;
    while (gender != "m" && gender != "f" && gender != "female" && gender != "male") {
        incorrect();
        cin >> gender;
    }

    if (gender == "male") gender = "m";
    else if (gender == "female") gender = "f";

    cout << "Enter your age: ";
    int playerAge;
    cin >> playerAge;
    
    // Controlli sull'età del giocatore
    if (playerAge < 18) {
        cout << "Get out of here stalker. You are too young for this apocalypse.\n";
        cin.ignore();
        cin.get();
        return 0;
    } else if (playerAge >= 100) {
        cout << "You're too old, you shouldn't be playing this.\n";
        cin.ignore();
        cin.get();
        return 0;
    }

    system("cls");

    cout << "Your name is " << playerName << " (" << gender << "), you are " << playerAge << " years old." << endl;
    cout << "Press [Enter] to start your nightmare..." << endl;
    cin.ignore(); // Pulisce il buffer rimasto dal cin dell'età
    cin.get();

    // Inizio della storia
    cout << "You're in your apartment, about to go to bed, when you hear a man screaming " << endl << "outside your window. ";
    cout << "You look out finding what looks to be an old " << endl << "man being attacked by two frantic shadows. " << endl;
    cout << endl;

    string choice1;
    cout << "Do you: " << endl << "[1] Go outside and help the man" << endl << "[2] Lock the door and go to bed" << endl << ": ";
    cin >> choice1;
    while (choice1 != "1" && choice1 != "2") {
        incorrect();
        cin >> choice1;
    }

    // SCELTA 1: Andare ad aiutare l'uomo
    if (choice1 == "1") {
        cout << endl << "You should probably take something with you. On your computer desk you see " << endl;
        cout << "a [F]lashlight, a [B]aseball bat, and a [H]unting knife." << endl;
        cout << "Which one of these items do you want to take with you?" << endl << ": ";
        string slot1;
        cin >> slot1;
        
        while (slot1 != "F" && slot1 != "f" && slot1 != "B" && slot1 != "b" && slot1 != "H" && slot1 != "h") {
            incorrect();
            cin >> slot1;
        }

        if (slot1 == "f" || slot1 == "F") slot1 = "flashlight";
        else if (slot1 == "b" || slot1 == "B") slot1 = "baseball bat";
        else if (slot1 == "h" || slot1 == "H") slot1 = "hunting knife";
        
        cout << "\nYou've acquired a " << slot1 << "!" << endl;
        cout << "Press [Enter] to continue" << endl;
        cin.ignore();
        cin.get();
        system("cls");

        cout << "You leave your apartment cautiously, holding your " << slot1 << " firmly." << endl;
        cout << "In the dimly lit corridor, you see a pale woman approaching you sluggishly." << endl;
        cout << "She makes no attempt at communicating and continues walking, groaning deeply." << endl;
        cout << "\nYou come to realize that this is no woman at all, but a zombie hungry for flesh!" << endl;
        cout << "Press [Enter] to fight!" << endl;
        cin.get();

        signed itemDMG = 1;
        string his_her = (gender == "m") ? "his" : "her";

        if (slot1 == "flashlight") itemDMG = 1;
        else if (slot1 == "baseball bat") itemDMG = 2;
        else if (slot1 == "hunting knife") itemDMG = 3;

        // Loop del combattimento principale
        while (playerHealth > 0 && zombieHealth > 0) {
            // Turno dello Zombie (1 possibilità su 4 di colpire)
            zAttackChance = randomNum(4);

            if (zAttackChance == 4) {
                playerHealth -= 3;
                cout << "The zombie lunges and bites " << playerName << "!" << endl;
                cout << "Successful hit! You lose 3 HP." << endl;
                pHealthCheck();
                cout << playerName << " has " << playerHealth << "/15 HP left.\n" << endl;
                
                if (playerHealth <= 0) {
                    system("cls");
                    cout << "The infection spreads through your veins. You have died." << endl;
                    cout << "Press [Enter] to quit";
                    cin.get();
                    return 0;
                }
            } else {
                cout << "The zombie swings wildly but misses " << playerName << "!" << endl;
                cout << playerName << " has " << playerHealth << "/15 HP left.\n" << endl;
            }

            cout << "Press [Enter] to counterattack..." << endl;
            cin.get();

            // Turno del Giocatore (1 possibilità su 2 di colpire)
            playerAttackChance = randomNum(2);

            if (playerAttackChance == 2) {
                zombieHealth -= itemDMG;
                cout << playerName << " strikes the zombie with " << his_her << " " << slot1 << "!" << endl;
                cout << "You dealt " << itemDMG << " HP of damage!" << endl;
                zHealthCheck();
                cout << "The zombie has " << zombieHealth << "/6 HP left.\n" << endl;
            } else {
                cout << playerName << " swings " << his_her << " " << slot1 << " but misses the target!" << endl;
                cout << "The zombie has " << zombieHealth << "/6 HP left.\n" << endl;
            }

            if (zombieHealth > 0) {
                cout << "Press [Enter] to brace yourself for the next round..." << endl;
                cin.get();
            }
        } // Fine del combattimento

        // Vittoria contro il primo zombie
        system("cls");
        cout << playerName << " (" << playerHealth << " HP) has smashed the zombie's head, killing it permanently." << endl;
        cout << "Press [Enter] to catch your breath...";
        cin.get();
        
        system("cls");
        cout << "Your heart is pounding. You take out your cellphone to call for help." << endl;
        cout << "Unfortunately, there is no signal. The grid seems to be collapsing." << endl;
        cout << "\nYou look down at the courtyard. The old man is still down there, fighting." << endl;
        
        string choice2;
        bool validChoice = false;
        
        while (!validChoice) {
            cout << "\nDo you:" << endl;
            cout << "[1] Push forward down the stairs to help the man" << endl;
            cout << "[2] Panic and retreat back inside your apartment" << endl;
            cout << ": ";
            cin >> choice2;

            if (choice2 == "1") {
                validChoice = true;