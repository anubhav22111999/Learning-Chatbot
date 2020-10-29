#ifndef _LEARNER_H
#define _LEARNER_H

#include <iostream>
#include <fstream>
#include "voice.h"

using namespace std;

class Learner {
public:
    void respond(string phrase);    // Used to get, or teach a response
   // void say(string phrase);    // Used to textually and audibly communicate a phrase
   void respond1(string phrase);

    Voice voice;    // The learner's voice that will audibly communicate a response
};

#endif
