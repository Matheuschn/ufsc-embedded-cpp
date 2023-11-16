#include "Safe.h"

Safe::Safe() {
    setupDone = false;
}

void Safe::run() {
    if (!setupDone) {
        setup();
    }
    
    while(true) {
        
    }
}

void Safe::setup() {

}
