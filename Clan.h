

#ifndef UNTITLED2_CLAN_H
#define UNTITLED2_CLAN_H

#include "Player.h"
#include "AVLTree.h"

namespace hw2 {
    class Clan {
    private:
        int clan_id;
        int players_number;
        AVLTree <Player> *players_tree;
        AVLTree <Player> *coins_tree;
        Player* max_player; //pointer to the player with the most challenges

    public:
        Clan(int id);

        Clan(const Clan &clan) = default;

        int getClanId() const;
        //returns the number of players of a specific clan
        int getNumPlayer() const;
        //returns the tree of the players of the clan (ordered by player ID)
        AVLTree <Player> *getPlayersTree() const;
        //returns the tree of the players of the clan (ordered by player coins)
        AVLTree <Player> *getCoinsTree() const;
        //the function returns the best player of the clan according to challenges amount
        Player *getBestPlayer();
        //add a player to the clan
        void addPlayer(const Player &player);
        // returns in the array players all the players of the clan ordered by coins amount
        //returns in  number the size of the array, ie the number of players in the clan
        void scoreBoardClan(int **players, int *number);
        //the function gets a player and if this player has more challenges than the current max, it uptadtes tha max
        void updateMaxPlayer(Player player);
    };
}
#endif //UNTITLED2_CLAN_H
