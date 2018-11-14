#include <iostream>

#include "core/core.hpp"


dizzy::dizzy(float length, float width) {
    m_xlength = length;
    m_ylength = width;
}

void dizzy::add_microphone(float position_x, float position_y) {
    microphone *mic = (microphone *)malloc(sizeof(microphone));

    mic->position_x = position_x;
    mic->position_y = position_y;

    mic->nposition_x = normalize_coord(m_xlength ,position_x);
    mic->nposition_y = normalize_coord(m_xlength ,position_y);
    m_microphones.push_back(mic);

    m_field.microphones.push_back(mic);
}

void dizzy::add_camera(float position_x, float position_y, float direction) {
    camera *cam = (camera*)malloc(sizeof(camera));

    cam->position_x = position_x;
    cam->position_y = position_y;

    cam->nposition_x = normalize_coord(m_xlength, position_x);
    cam->nposition_y = normalize_coord(m_ylength, position_y);

    cam->direction = direction;
    
    cam->ndirection = normalize_direction(direction);

    m_field.cameras.push_back(cam);
}

void dizzy::update_norms() {
    
}

float dizzy::normalize_coord(float total_size, float input) {
    return (total_size - input) / input;
}

float dizzy::normalize_direction(float direction) {
    return (360 - direction) / direction;
}

float dizzy::get_length_x() {
    return m_xlength;
}

float dizzy::get_length_y() {
    return m_ylength;
}

field *dizzy::get_config() {
    return &m_field;
}