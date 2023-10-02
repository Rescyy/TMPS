#include "builder.hpp"

int main(){
    PCBuilder pcbuilder;
    PCBuilderDirector director;
    director.buildAtari(&pcbuilder);
    PC atari = pcbuilder.getPC();
    director.buildGamingPC(&pcbuilder);
    PC gamingpc = pcbuilder.getPC();
    director.buildWorkPC(&pcbuilder);
    PC workpc = pcbuilder.getPC();
    atari.inspect();
    gamingpc.inspect();
    workpc.inspect();
    return 0;
}