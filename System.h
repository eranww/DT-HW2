//
// Created by naomie on 11/05/2018.
//

#ifndef UNTITLED2_SYSTEM_H
#define UNTITLED2_SYSTEM_H

#include "Player.h"
#include "Clan.h"
#include "AVLTree.h"

namespace hw2{
    class System{
    private:
        Player* max_challenges_player;
        AVLTree<Player>* players_tree;
        AVLTree<Player>* coins_tree;
        AVLTree<Clan>* clans_tree;
        int players_number;

    public:
        System();
        System(const System& syst)= delete;
        //get the number of players in the system
        int getPlayersNumber();
        //get the player that as the maximum of challenges
        Player* getMaxSystem();
        //add  a player to the system
        void addPlayerSystem(Player player);
        //add a clan to the system
        void addClanSystem(Clan clan);
        //get a player according to his ID (if the player is not in the system the function returns NULL)
        //take the player from the tree of ids
        Player& getPlayerAccId(int player_id);
        //get a player according to his coins amount (the player is for sure in the system)
        //take the player from the tree of coins
        Player& getPlayerAccCoins(int coins);

        //get a clan according to his ID (if the clan is not in the system the function returns NULL)
        Clan& getClan(int clan_id);

        //get the tree of the players by id
        AVLTree<Player>* getIdsTree();
        //get the tree of the players by coins
        AVLTree<Player>* getCoinsTree();
        //get the tree of the clans by id
        AVLTree<Player>* getClansTree();

    };
}

#endif //UNTITLED2_SYSTEM_H
