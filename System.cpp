
#include "System.h"
#include "Player.h"
#include "Clan.h"
#include "AVLTree.h"

/*
 class System{
    private:
        Player* max_challenges_player;
        AVLTree<Player>* players_tree;
        AVLTree<Player>* coins_tree;
        AVLTree<Clan>* clans_tree;
        int players_number;

*/

namespace hw2{

    System::System(): players_number(0), max_challenges_player(NULL), players_tree(), coins_tree(), clans_tree(){}

    int System::getPlayersNumber(){
        return players_number;
    }

    Player* getMaxSystem(){
        return max_challenges_player;
    }

    void System::addPlayerSystem(Player player){
        players_tree.addNode(player);
        coins_tree.addNode(player);
        players_number++;
        if(player.getChallenges() > max_challenges_player->getChallenges()) {
            max_challenges_player = *player;
        }
    }

    void System::addClanSystem(Clan clan){
        clans_tree.addNode(clan);
    }
//TO COMPLETE
    Player& System::getPlayerAccId(int player_id){
        //from the tree players_tree
    }

    Player& getPlayerAccCoins(int coins){
        //from the tree coins_tree
    }
//TO COMPLETE
    Clan& System::getClan(int clan_id){
        //from the tree clans_tree
    }

    AVLTree<Player>* getIdsTree(){
        return players_tree;
    }

    AVLTree<Player>* getCoinsTree(){
        return coins_tree;
    }

    AVLTree<Player>* getClansTree(){
        return clans_tree;
    }
}