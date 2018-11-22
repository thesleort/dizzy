#include <cmath>

#include "ambisonic/encode.hpp"


dizzy::ambisonic::Encode::Encode(microphone &mic, unsigned order) {
    m_mic = &mic;
    m_order = order;
}

void dizzy::ambisonic::Encode::set_coordinates(const float radius, const float azimuth, const float elevation) {
    m_radius = radius;
    m_azimuth = azimuth;
    m_elevation = elevation;
}

void dizzy::ambisonic::Encode::set_radius(const float radius) {
    m_radius = radius;
}

void dizzy::ambisonic::Encode::set_azimuth(const float azimuth) {
    m_azimuth = azimuth;
}

void dizzy::ambisonic::Encode::set_elevation(const float elevation) {
    m_elevation = elevation;
}

void dizzy::ambisonic::Encode::enqueue_signals(std::vector<signal> signals) {
    for(unsigned i = 0; i < signals.size(); ++i) {
        switch(signals[i].source_signal) {
            case W:
                m_mic->sources[i].signal = signals[i].signal * (1 / std::sqrt(2));
                break;
            case X:
                m_mic->sources[i].signal = signals[i].signal * std::cos(m_radius) * std::cos(m_elevation);
                break;
            case Y:
                m_mic->sources[i].signal = signals[i].signal * std::sin(m_radius) * std::cos(m_elevation);
                break;
            case Z:
                m_mic->sources[i].signal = signals[i].signal * std::sin(m_elevation);
                break;
        }
    }
}