#include "ambisonic/setup.hpp"

dizzy::ambisonic::Setup::Setup(dimension dim) {
    m_dimension = dim;
}

void dizzy::ambisonic::Setup::add_microphone(Microphone &mic) {
    m_mic = &mic;
    add_signal(W);
    add_signal(X);
    add_signal(Y);
    add_signal(Z);
}

void dizzy::ambisonic::Setup::add_signal(Signal_type sig) {

    // TODO:
    if (m_mic->sources.size() <= 4) {
        Signal s;
        s.source_signal = sig;
        // m_mic->sources.push_back(s);
    }
}
