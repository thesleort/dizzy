#ifndef __TYPES_HPP
#define __TYPES_HPP

#include <vector>

// namespace dizzy
enum Signal_type {
    W, X, Y, Z
};

enum Source {
    MONO,
    STEREO,
    SURROUND50,
    SURROUND51,
    SURROUND70,
    SURROUND71
};

enum Placement {
    ROOF, 
    GOAL, 
    PENALTY_HOME, 
    PENALTY_AWAY, 
    REFEREE,
    BENCH_HOME,
    BENCH_AWAY,
    COACH_HOME,
    COACH_AWAY
};

struct Signal {
    Signal_type source_signal;
    float signal;
};

struct Sound {
    float volume;
    float delay;    // Milliseconds
    float zoom;     // Future implementation
    float distance; // Distance to camera
    Signal signal;
};

struct Microphone {
    unsigned id;

    // Coordinates
    float position_x;
    float position_y;
    float position_z; //height

    // Normalized coordinates
    float nposition_x;
    float nposition_y;
    float nposition_z;

    Placement placement;

    Source source;

    std::vector<Sound> sources;

    // std::vector<Signal> sources;
    float max_delay;
};

struct Camera {
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

union Recorder {
    Microphone mic;
    Camera cam;
};

struct Field {
    float length_x;
    float length_y;
    float height; 
    
    std::vector<Microphone*> microphones;
    std::vector<Camera*> cameras;
    // std::vector<recorder> recorders;
};

struct Sound_levels {
    std::vector<Sound> mic_levels;
    float max_delay;
};

// struct Relative_position {
//     float distance;
//     float direction;
// };


#endif