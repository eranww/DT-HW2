
#include "wet1.h"
#include "Player.h"
#include "Clan.h"
#include "AVLTree.h"
#include "System.h"
using namespace hw2;

    void* init(){
        System sys();
        return *sys;
    }

    StatusType addPlayer(void *DS, int playerID, int initialCoins){
        System* sys= DS;
        if(DS == NULL || initialCoins < 0 || playerID <= 0){
            return INVALID_INPUT;
        }
        if(sys->getPlayer(playerID) != NULL){
            return FAILURE;
        }
        try {
            Player player(playerID, initialCoins);
            sys->addPlayerSystem(player);
        } catch (std::bad_alloc& e) {
            return ALLOCATION_ERROR;
        }
        return SUCCESS;
    }

    StatusType addClan(void *DS, int clanID){
        System* sys=DS;
        if(DS == NULL || clanID <= 0){
            return INVALID_INPUT;
        }
        if(sys->getClan(clanID) != NULL){
            return FAILURE;
        }
        try {
            Clan clan(clanID);
            sys->addClanSystem(clan);
        } catch (std::bad_alloc& e) {
            return ALLOCATION_ERROR;
        }
        return SUCCESS;
    }

    StatusType joinClan(void *DS, int playerID, int clanID){
        System* sys=DS;
        if(DS==NULL || playerID <= 0 || clanID <= 0){
            return INVALID_INPUT;
        }
        if(sys->getPlayer(playerID)==NULL || sys->getClan(clanID)==NULL || sys->getPlayer(playerID).getClanPlayer()!=-1){
            return FAILURE;
        }
        try {
            Player player = sys->getPlayer(playerID);
            Clan players_clan = sys->getClan(clanID);
            players_clan.addPlayer(player);
            player.updateClan(playerID, *players_clan);
        }catch(std::bad_alloc& e){
            return ALLOCATION_ERROR;
        }
        return SUCCESS;
    }

    StatusType getBestPlayer(void *DS, int clanID, int *playerID){
        System* sys= DS;
        if(clanID == 0 || DS == NULL || playerID == NULL){
            return INVALID_INPUT;
        }
        if(clanID < 0){
            *playerID=sys->getMaxSystem()->getPlayerId();
            return SUCCESS;
        }
        if(sys->getClan(clanID)==NULL){
            return FAILURE;
        }
        *playerID=sys->getClan(clanID).getBestPlayer()->getPlayerId();
        return SUCCESS;
    }

    StatusType completeChallange(void *DS, int playerID, int coins){
        System* sys= DS;
        if(coins <= 0 || DS == NULL || playerID <= 0){
            return INVALID_INPUT;
        }
        if(sys->getPlayer(playerID)==NULL){
            return FAILURE;
        }
        //we have to find the player from the tree of ids and then according to his coins we have to put it out from
        //the tree of coins and then update the player and then put it in the tree of coins (after updates of coins)
        Player player=sys->getPlayerAccID(playerID));

        sys->getCoinsTree()->getOut(player);
        if(player.getClanPlayer()!=-1){
            player.getClanPointer()->getCoinsTree()->getOut(player);
        }
        player.addChallenge(coins);
        try {
            sys->getCoinsTree()->addNode(player);
            if (player.getClanPlayer() != -1) {
                player.getClanPointer()->getCoinsTree()->addNode(player);
            }
        }catch (std::bad_alloc& e) {
            return ALLOCATION_ERROR;
        }
        player.getClanPointer()->updateMaxPlayer(player); //in case of need it update the new max player (player
        //with most challenges)
        return SUCCESS;
    }



    StatusType getScoreboard(void *DS, int clanID, int **players, int *numOfPlayers){

    }



    StatusType uniteClans(void *DS, int clanID1, int clanID2){

    }


