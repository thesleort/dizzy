#ifndef __TYPES_HPP
#define __TYPES_HPP

#include <vector>

// namespace dizzy

struct microphone {
    unsigned id;

    // Coordinates
    int position_x;
    int position_y;
    // Normalized coordinates
    float nposition_x;
    float nposition_y;
};

struct camera {
    unsigned id;

    // Coordinates
    int position_x;
    int position_y;
    // Normalized coordinates
    float nposition_x;
    float nposition_y;

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

    std::vector<microphone*> microphones;
    std::vector<camera*> cameras;
    // std::vector<recorder> recorders;
};

struct sound {
    unsigned id;
    float volume;
    float delay;
};

struct sound_levels {
    std::vector<sound> mic_levels;
};

struct relative_position {
    float distance;
    float direction;
};


#endif