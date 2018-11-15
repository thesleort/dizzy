#include <iostream>

#include "core/setup.hpp"

setup::setup(float length, float width) {
    m_field = (field*)malloc(sizeof(field));
    m_field->length_x = length;
    m_field->length_y = width;
}

void setup::add_microphone(float position_x, float position_y) {
    microphone *mic = (microphone *)malloc(sizeof(microphone));

    mic->position_x = position_x;
    mic->position_y = position_y;

    mic->nposition_x = normalize_coord(m_field->length_x ,position_x);
    mic->nposition_y = normalize_coord(m_field->length_x ,position_y);
    m_field->microphones.push_back(mic);

    m_field->microphones.push_back(mic);
}

void setup::add_camera(float position_x, float position_y, float direction) {
    if(position_x < m_field->length_x || position_x < 0 || position_y < m_field->length_y || position_y > 0) {
        std::cout << "Cannot add camera outside specified area\n";
        // update_norms();
        return;
    }
    camera *cam = (camera*)malloc(sizeof(camera));

    cam->position_x = position_x;
    cam->position_y = position_y;

    cam->nposition_x = normalize_coord(m_field->length_x, position_x);
    cam->nposition_y = normalize_coord(m_field->length_y, position_y);

    cam->direction = direction;
    
    cam->ndirection = normalize_direction(direction);

    m_field->cameras.push_back(cam);
}

void setup::update_norms() {
    // TODO: Add device out of bound and update normalization for all devices.
    // for(unsigned i = 0; i < m_field->microphones.size(); ++i) {
    //     normalize_coord(m_field->microphones[i]->)
    // }
}

float setup::normalize_coord(float total_size, float input) {
    return (total_size - input) / input;
}

float setup::normalize_direction(float direction) {
    return (360 - direction) / direction;
}

float setup::get_length_x() {
    return m_field->length_x;
}

float setup::get_length_y() {
    return m_field->length_y;
}

field *setup::get_config() {
    return m_field;
}