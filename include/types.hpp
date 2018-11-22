#ifndef __TYPES_HPP
#define __TYPES_HPP

#include <vector>

// namespace dizzy
enum signal_type {
    W, X, Y, Z
};

struct signal {
    signal_type source_signal;
    float signal;
};

struct microphone {
    unsigned id;

    // Coordinates
    float position_x;
    float position_y;
    float position_z; //height

    // Normalized coordinates
    float nposition_x;
    float nposition_y;
    float nposition_z;

    std::vector<signal> sources;
};

struct camera {
    unsigned id;

    // Coordinates
    float position_x;
    float position_y;
    float position_z; //height
    // Normalized coordinates
    float nposition_x;
    float nposition_y;
    float nposition_z;

    float direction;
    // Normalized direction
    float ndirection;
};

union recorder {
    microphone mic;
    camera cam;
};

struct field {
    float length_x;
    float length_y;
    float height; 
    
    std::vector<microphone*> microphones;
    std::vector<camera*> cameras;
    // std::vector<recorder> recorders;
};

struct sound {
    microphone *mic;
    float volume;
    float delay;    // Milliseconds
    float zoom;     // Future implementation
    float distance;
};

struct sound_levels {
    std::vector<sound> mic_levels;
    float max_delay;
};

struct relative_position {
    float distance;
    float direction;
};


#endif