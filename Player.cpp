
#include "Player.h"

namespace hw2{

    Player::Player(int player_id, int coins) : player_id(player_id), coins(coins), clan_id(-1), challenges(0),
                                       clan_pointer(NULL) {}


    int Player::getPlayerId() {
        return player_id;
    }

    int Player::getCoins() {
        return coins;
    }

    int Player::getClanPlayer() {
        return clan_id;
    }

    int Player::getChallenges() {
        return challenges;
    }

    Clan* Player::getClanPointer() {
        return clan_pointer;
    }

    void Player::addChallenge(int coins_add) {
        coins = coins + coins_add;
        challenges++;
    }

    void Player::updateClan(int id, Clan* pointer) {
        clan_id = id;
        clan_pointer = pointer;
    }

    bool Player::operator==(const Player &player) const {
        return player_id == player.player_id;
    }

    bool Player::operator!=(const Player &player) const {
        return !(*this == player);
    }

    bool Player::operator<(const Player &player) const {
        return player_id < player.player_id;
    }

    bool Player::operator>(const Player &player) const {
        return player_id > player.player_id;
    }

    bool Player::isBigger(const Player &player) const { //operator for the tree of coins
        if (coins > player.coins) {
            return true;
        }
        if (coins < player.coins) {
            return false;
        }
        return *this > player;
    }
}