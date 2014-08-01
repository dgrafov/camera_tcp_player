#include "player.h"
#include "debug/debug.h"
#include <pthread.h>
#include <exception>

int main(void) {
    Player player;
    player.loadConfig("config.xml");
    player.startPlayer();    
    return 0;
}

