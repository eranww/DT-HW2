
#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H

#include <iostream>
#include "Clan.h"
#include "cmake-build-debug/Clan.h"

namespace hw2 {

    class Player {
        int player_id;
        int coins;
        int clan_id;
        int challenges;
        Clan* clan_pointer;

    public:
        Player(int player_id, int coins);
        Player(const Player& player)=default;
        int getPlayerId();
        int getCoins();
        int getClanPlayer();
        //returns the number of challenges that the player validated
        int getChallenges();
        Clan* getClanPointer();
        //add to a specific player a challenges (the player get coins)
        void addChallenge(int coins_add);
        //update the clan of a specific player (if you want to put this player in a new clan)
        void updateClan(int id, Clan* pointer);
        bool operator==(const Player &player) const;
        bool operator!=(const Player &player) const;
        bool operator<(const Player &player) const;
        bool operator>(const Player &player) const;
        //function of comparaison that compares according to the number of coins of the players
        //in case of same amount of coins the comparaison is done according to the ID of the players
        bool isBigger(const Player &player) const;

    };
}


#endif //UNTITLED2_PLAYER_H