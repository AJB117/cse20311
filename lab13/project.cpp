// Patrick Soga
// Lab 13, Section 2
// 15 Dec 2019
// project.cpp: Pokemon battle simulator

#include <iostream>
#include <string>
#include <unistd.h>
#include <sstream>
#include <cmath>

#include "gfx2.h"
#include "pokemon.h"

using namespace std;

bool menu(int, int, vector<Pokemon>);
bool battle(Pokemon, vector<Pokemon>, int, int);
bool turn(Pokemon &, Pokemon&, int, Move);
int damageCalc(Move, Pokemon, Pokemon);
void statusCalc(Move, Pokemon&, Pokemon&);
void addMoves(vector<Move>&, Move, Move, Move, Move);
vector<Pokemon> initializePokemon();
float typeEffectiveness(string, string, string);

int main() {
    int xdim = 320;
    int ydim = 288;
    gfx_open(xdim, ydim, "Pokemon Simulator");
    char choice;
    vector<Pokemon> pkmn = initializePokemon();
    while(true) {
        gfx_text(xdim/6 + xdim/5, ydim/3 + ydim/6, "Pokemon Simulator");
        gfx_text( xdim/6 + xdim/9, ydim/3 + ydim/5, "Press any key to continue");
        choice = gfx_wait();
        if (choice) {
            gfx_flush();
            gfx_clear();
            if (!menu(xdim, ydim, pkmn)) {
                bool finished = true;
                while(finished) {
                    gfx_color(0,0,0);
                    gfx_text(xdim/4, ydim/2.5, "Game end - Press any key to exit");
                    if (gfx_event_waiting())
                        finished = false;
                }
                break;
            }
        }
    }
    return 0;
}

bool menu(int xdim, int ydim, vector<Pokemon> pkmn) {
    gfx_clear();
    Pokemon playerPkmn;
    bool loop = true;
    while (loop) {
        gfx_text(xdim/3 + 10, ydim/3 - 4, "Choose a Pokemon");
        gfx_line(xdim/3, ydim/3, 2*xdim/3, ydim/3);
        gfx_text(xdim/3 + 13, ydim/3 + 20, "1 - Charizard");
        gfx_text(xdim/3 + 13, ydim/3 + 40, "2 - Venusaur");
        gfx_text(xdim/3 + 13, ydim/3 + 60, "3 - Blastoise");
        gfx_text(xdim/3 + 13, ydim/3 + 80, "4 - Dragonite");
        gfx_text(xdim/3 + 13, ydim/3 + 100, "5 - Lapras");
        gfx_text(xdim/3 + 13, ydim/3 + 120, "6 - Mewtwo");

        char choice = gfx_wait();
        switch(choice) {
            case '1':
                playerPkmn = pkmn[0];
                loop = false;
                break;
            case '2':
                playerPkmn = pkmn[1];      
                loop = false;          
                break;
            case '3':
                playerPkmn = pkmn[2];
                loop = false;
                break;
            case '4':
                playerPkmn = pkmn[3];       
                loop = false;         
                break;
            case '5':
                playerPkmn = pkmn[4];
                loop = false;
                break;
            case '6':
                playerPkmn = pkmn[5];
                loop = false;
                break;
        }
        if (((int) choice) - 48 < 7 && ((int) choice) - 48 > 0) {
            if (!battle(playerPkmn, pkmn, xdim, ydim))
                return false;
        }
    }
    return 1;
}

bool battle(Pokemon playerPokemon, vector<Pokemon> pkmn, int xdim, int ydim) {
    gfx_clear_color(255, 255, 255);
    gfx_clear();
    Move move;
    vector<Move> moves = playerPokemon.getMoves();
    srand(time(NULL));
    int index = rand() % 6;
    Pokemon foePokemon = pkmn[index];
    cout << foePokemon.getName() << " appeared!" << endl;
    cout << "your pokemon: " << playerPokemon << endl;
    cout << "foe pokemon: " << foePokemon << endl << endl;
    
    playerPokemon.draw(10, ydim*0.62 - playerPokemon.backColors.rows, 0);
    foePokemon.draw(xdim*0.97 - foePokemon.frontColors.rows, 0, 1);
    gfx_color(0,0,0);
    gfx_rectangle(3, ydim*0.65, xdim-6, ydim*0.34);
    
    while (true) {
        vector<Move> moves = playerPokemon.getMoves();
        gfx_color(0,0,0);
        gfx_text(25, ydim*0.75, ("1 " + moves[0].getName()).c_str());
        gfx_text(5 + xdim*0.62, ydim*0.75, ("2 " + moves[1].getName()).c_str());
        gfx_text(25, ydim*0.8, ("3 " + moves[2].getName()).c_str());
        gfx_text(5 + xdim*0.62, ydim*0.8, ("4 " + moves[3].getName()).c_str());
        cout << endl << "HP: " << playerPokemon.getHp() << endl;
        cout << "Foe HP: " << foePokemon.getHp() << endl;
        char choice = gfx_wait();
        int moveIndex = ((int) choice) - 48;
        cout << moveIndex-1 << endl;
        if (moveIndex >= 1 && moveIndex <= 4) { 
            move = moves[moveIndex - 1];
            if (foePokemon.getSpd() > playerPokemon.getSpd()) {
                if (!turn(foePokemon, playerPokemon, 0, move)) {
                    return false;
                }
                if (!turn(playerPokemon, foePokemon, 1, move)) {
                    return false;
                }
            }
            else if (playerPokemon.getSpd() > foePokemon.getSpd()) {
                if (!turn(playerPokemon, foePokemon, 1, move)) {
                    return false;
                }
                if (!turn(foePokemon, playerPokemon, 0, move)) {
                    return false;
                }
            }
            else {
                int t = rand() % 2;
                if (t == 0) {
                    if (!turn(playerPokemon, foePokemon, 1, move)) {
                        return false;
                    }
                    if (!turn(foePokemon, playerPokemon, 0, move)) {
                        return false;
                    }
                }
                else {
                    if (!turn(foePokemon, playerPokemon, 0, move)) {
                        return false;
                    }
                    if (!turn(playerPokemon, foePokemon, 1, move)) {
                        return false;
                    }
                }
            }
        }
    }
}

bool turn(Pokemon &pokemon, Pokemon &target, int player, Move move) {
    int damage = 0;
    char choice;
    if (player) {
        cout << pokemon.getName() << " used " << move.getName() << "!" << endl;
        damage = damageCalc(move, pokemon, target);
        if (damage > target.getHp()) damage = target.getHp();
        if (damage == -1)
            pokemon.status(move, target, 0);
        else {
            target.damage(damage, 1);
            if (target.getHp() == 0) {
                cout << target.getName() << " fainted!" << endl;
                return false;
            }
        }
    }
    else {
        int foeChoice = rand() % 4;
        cout << "foeChoice: " << foeChoice << endl;
        vector<Move> moves = pokemon.getMoves();
        move = moves[foeChoice];
        cout << "The foe " << pokemon.getName() << " used " << move.getName() << "!" << endl;
        damage = damageCalc(move, pokemon, target);
        if (damage > target.getHp()) damage = target.getHp();
        if (damage == -1)
            pokemon.status(move, target, 1);
        else {
            target.damage(damage, 0);
            if (target.getHp() <= 0) {
                cout << target.getName() << " fainted!" << endl;
                return false;
            }
        }
    }
    return true;
}

int damageCalc(Move move, Pokemon attacker, Pokemon target) {
    // Damage equation from Bulbapedia: https://bulbapedia.bulbagarden.net/wiki/Damage
    string moveCategory = move.getCategory();
    if (moveCategory == "status")
        return -1;
    else {
        int level = attacker.getLevel();
        string moveType = move.getType();
        string attackerType1 = attacker.getType1();
        string attackerType2 = attacker.getType2();
        string targetType1 = target.getType1();
        string targetType2 = target.getType2();
        float damage = 0;
        float ad;
        int power = move.getBaseDamage();
        float r = 0.01*(rand() % 15 + 85);
        float stab = 1;
        float typeMult = typeEffectiveness(moveType, targetType1, targetType2);
        if (moveType == attackerType1 || moveType == attackerType2)
            stab = 1.5;
        float modifier = r*stab*typeMult;
        if (moveCategory == "physical")
            ad = attacker.getAtk() / target.getDef();
        else
            ad = attacker.getSpAtk() / target.getSpDef();
        damage = floor(modifier*(((2*level/5) + 2)*(float)power*ad/50));
        return damage;
    }
}

float typeEffectiveness(string moveType, string targetType1, string targetType2) {
    float multiplier = 1;
    if (moveType == "fire") {
        if (targetType1 == "fire" || targetType1 == "dragon" || targetType1 == "water") {
            multiplier *= 0.5;
        } 
        if (targetType2 == "fire" || targetType2 == "dragon"  || targetType2 == "water") {
            multiplier *= 0.5;
        }
        if (targetType1 == "grass") {
            multiplier *= 2;
        } 
        if (targetType2 == "ice") {
            multiplier *= 2;
        }
    }
    if (moveType == "water") {
        if (targetType1 == "water" || targetType1 == "dragon") {
            multiplier *= 0.5;
        } 
        if (targetType2 == "water" || targetType2 == "dragon") {
            multiplier *= 0.5;
        }
        if (targetType1 == "fire" || targetType2 == "fire") {
            multiplier *= 2;
        }
    }
    if (moveType == "grass") {
        if (targetType1 == "grass" || targetType1 == "dragon" || targetType1 == "flying" || targetType1 == "fire") {
            multiplier *= 0.5;
        } 
        if (targetType2 == "grass" || targetType2 == "dragon"  || targetType2 == "flying" || targetType2 == "fire") {
            multiplier *= 0.5;
        }
        if (targetType1 == "water" || targetType2 == "water") {
            multiplier *= 2;
        }
    }
    if (moveType == "normal") {
    }
    if (moveType == "ice") {
        if (targetType1 == "fire" || targetType1 == "ice" || targetType1 == "water") {
            multiplier *= 0.5;
        } 
        if (targetType2 == "fire" || targetType2 == "ice"  || targetType2 == "water") {
            multiplier *= 0.5;
        }
        if (targetType1 == "flying") {
            multiplier *= 2;
        } 
        if (targetType2 == "flying") {
            multiplier *= 2;
        }
        if (targetType1 == "dragon") {
            multiplier *= 2;
        } 
        if (targetType2 == "dragon") {
            multiplier *= 2;
        }
        if (targetType1 == "grass") {
            multiplier *= 2;
        } 
        if (targetType2 == "grass") {
            multiplier *= 2;
        }
    }
    if (moveType == "poison") {
        if (targetType1 == "poison") {
            multiplier *= 0.5;
        } 
        if (targetType2 == "poison") {
            multiplier *= 0.5;
        }
        if (targetType1 == "grass") {
            multiplier *= 2;
        } 
        if (targetType2 == "grass") {
            multiplier *= 2;
        }
    }
    if (moveType == "dragon") {
        if (targetType1 == "dragon") {
            multiplier *= 2;
        } 
        if (targetType2 == "dragon") {
            multiplier *= 2;
        }
    }
    if (moveType == "flying") {
        if (targetType1 == "grass") {
            multiplier *= 2;
        } 
        if (targetType2 == "grass") {
            multiplier *= 2;
        }
    }
    if (moveType == "psychic") {
        if (targetType1 == "poison") {
            multiplier *= 2;
        } 
        if (targetType2 == "poison") {
            multiplier *= 2;
        }
    }
    if (moveType == "fighting") {
        if (targetType1 == "psychic" || targetType1 == "flying") {
            multiplier *= 0.5;
        } 
        if (targetType2 == "psychic" || targetType2 == "flying" || targetType2 == "poison") {
            multiplier *= 0.5;
        }
        if (targetType1 == "ice") {
            multiplier *= 2;
        } 
        if (targetType2 == "ice") {
            multiplier *= 2;
        }
    }
    if (moveType == "electric") {
        if (targetType1 == "grass" || targetType1 == "dragon") {
            multiplier *= 0.5;
        } 
        if (targetType2 == "grass" || targetType2 == "dragon") {
            multiplier *= 0.5;
        }
        if (targetType1 == "flying" || targetType1 == "water") {
            multiplier *= 2;
        } 
        if (targetType2 == "flying" || targetType2 == "water") {
            multiplier *= 2;
        }
    }
    if (multiplier > 1) {
        cout << "It was super-effective!" << endl;
    }
    else if (multiplier < 1) {
        cout << "It wasn't very effective..." << endl;
    }
    return multiplier;
}

vector<Pokemon> initializePokemon() {
    vector<Pokemon> pkmn;
    vector<Move> moves = {Move(), Move(), Move(), Move()};
    Move fireblast("Fire Blast", 120, "fire", "special");
    Move slash("Slash", 70, "normal", "physical");
    Move drgnbreath("Dragon Breath", 60, "dragon", "special");
    Move airslash("Air Slash", 75, "flying", "physical");
    addMoves(moves, fireblast, slash, drgnbreath, airslash);
    Pokemon Charizard = {"Charizard", 100, 360, 293, 280, 348, 295, 328, moves, "fire", "flying", 55, 55, 26, 28};

    Move hydropump("Hydro Pump", 120, "water", "special");
    Move icebeam("Ice Beam", 90, "ice", "special");
    Move rapidspin("Rapid Spin", 60, "normal", "physical");
    Move screech("Screech", 0, "normal", "status");
    addMoves(moves, hydropump, icebeam, rapidspin, screech);
    Pokemon Blastoise("Blastoise", 100, 362, 291, 328, 295, 339, 280, moves, "water", "empty", 54, 54, 21, 28);

    Move solarbeam("Solar Beam", 120, "grass", "special");
    Move sludgebomb("Sludge Bomb", 95, "poison", "special");
    Move earthquake("Earthquake", 100, "ground", "physical");
    Move doubleedge("Double-Edge", 120, "normal", "physical");
    addMoves(moves, solarbeam, sludgebomb, earthquake, doubleedge);
    Pokemon Venusaur("Venusaur", 100, 364, 289, 291, 328, 328, 284, moves, "grass", "poison", 50, 53, 28, 28);

    Move dragonclaw("Dragon Claw", 80, "dragon", "physical");
    Move skyattack("Sky Attack", 140, "flying", "physical");
    Move thndrpunch("Thunder Punch", 75, "electric", "physical");
    Move hyperbeam("Hyper Beam", 150, "normal", "special");
    addMoves(moves, dragonclaw, skyattack, thndrpunch, hyperbeam);
    Pokemon Dragonite("Dragonite", 100, 386, 403, 317, 328, 328, 284, moves, "dragon", "flying", 52, 52, 26, 28);

    Move blizzard("Blizzard", 120, "ice", "special");
    Move recover("Recover", 0, "normal", "status");
    Move thunderbolt("Thunderbolt", 95, "electric", "special");
    addMoves(moves, hydropump, blizzard, recover, thunderbolt);
    Pokemon Lapras("Lapras", 100, 464, 295, 284, 295, 317, 240, moves, "water", "ice", 56, 56, 28, 26);

    Move psychic("Psychic", 90, "psychic", "special");
    Move thunder("Thunder", 120, "electric", "special");
    Move aurasphere("Aura Sphere", 90, "fighting", "special");
    addMoves(moves, psychic, thunder, recover, aurasphere);
    Pokemon Mewtwo("Mewtwo", 100, 416, 350, 306, 447, 306, 394, moves, "psychic", "empty", 56, 56, 27, 28);
    
    pkmn.push_back(Charizard);
    pkmn.push_back(Venusaur);
    pkmn.push_back(Blastoise);
    pkmn.push_back(Dragonite);
    pkmn.push_back(Lapras);
    pkmn.push_back(Mewtwo);
    return pkmn;
}

void addMoves(vector<Move> &moves, Move move1, Move move2, Move move3, Move move4) {
    moves[0] = move1;
    moves[1] = move2;
    moves[2] = move3;
    moves[3] = move4;
}