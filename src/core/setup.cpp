#include <iostream>

#include "core/setup.hpp"

dizzy::setup::setup(float length, float width) {
    m_field = (field*)malloc(sizeof(field));
    m_field->length_x = length;
    m_field->length_y = width;
}

void dizzy::setup::add_microphone(float position_x, float position_y, float position_z, placement place) {
    microphone *mic = (microphone *)malloc(sizeof(microphone));

    mic->position_x = position_x;
    mic->position_y = position_y;
    mic->position_z = position_y;

    mic->m_placement = place;

    mic->nposition_x = normalize_coord(m_field->length_x ,position_x);
    mic->nposition_y = normalize_coord(m_field->length_x ,position_y);
    mic->nposition_z = normalize_coord(m_field->height, position_z);
    m_field->microphones.push_back(mic);

    m_field->microphones.push_back(mic);
}

void dizzy::setup::add_camera(float position_x, float position_y, float position_z, float direction) {
    if(position_x < m_field->length_x || position_x < 0 || position_y < m_field->length_y || position_y > 0) {
        std::cout << "Cannot add camera outside specified area\n";
        // update_norms();
        return;
    }
    camera *cam = (camera*)malloc(sizeof(camera));

    cam->position_x = position_x;
    cam->position_y = position_y;
    cam->position_z = position_z;

    cam->nposition_x = normalize_coord(m_field->length_x, position_x);
    cam->nposition_y = normalize_coord(m_field->length_y, position_y);
    cam->nposition_z = normalize_coord(m_field->height, position_z);

    cam->direction = direction;
    
    cam->ndirection = normalize_direction(direction);

    m_field->cameras.push_back(cam);
}

void dizzy::setup::update_norms() {
    // TODO: Add device out of bound and update normalization for all devices.
    // for(unsigned i = 0; i < m_field->microphones.size(); ++i) {
    //     normalize_coord(m_field->microphones[i]->)
    // }
}

float dizzy::setup::normalize_coord(float total_size, float input) {
    return (total_size - input) / input;
}

float dizzy::setup::normalize_direction(float direction) {
    return (360 - direction) / direction;
}

float dizzy::setup::get_length_x() {
    return m_field->length_x;
}

float dizzy::setup::get_length_y() {
    return m_field->length_y;
}

field *dizzy::setup::get_config() {
    return m_field;
}