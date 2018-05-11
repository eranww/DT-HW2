
#include "Clan.h"
#include "Player.h"

namespace hw2{
    Clan(int id): clan_id(id), players_number(0), players_tree(), coins_tree(), max_player(NULL){}

    int Clan::getClanId(){
        return clan_id;
    }

    int Clan::getNumPlayer(){
        return players_number;
    }

    const AVLTree<Player>* Clan::getPlayersTree(){
        return players_tree;
    }

    const AVLTree<Player>* Clan::getCoinsTree(){
        return coins_tree;
    }

    const Player* Clan::getBestPlayer(){
        return max_player;
    }

    void Clan::addPlayer(Player player){
        players_tree.addNode(player);
        coins_tree.addNode(player);
        players_number++;
        if( player.getChallenges() > max_player->getChallenges()){
            max_player=*player;
        }
    }

    //to complete
    void Clan::scoreBoardClan(int** players, int* number){
        *number=players_number;
        players=new Player[players_number];
        //do the in order tour according to the functions of the tree
    }

    void Clan::updateMaxPlayer(Player player){
        if(player.getChallenges() > max_player->getChallenges()){
            max_player=*player;
        }
    }

}