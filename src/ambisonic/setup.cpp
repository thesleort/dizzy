#include "ambisonic/setup.hpp"

dizzy::ambisonic::Setup::Setup(dimension dim) {
    m_dimension = dim;
}

void dizzy::ambisonic::Setup::add_microphone(microphone &mic) {
    m_mic = &mic;
    add_signal(W);
    add_signal(X);
    add_signal(Y);
    add_signal(Z);
}

void dizzy::ambisonic::Setup::add_signal(signal_type sig) {

    if (m_mic->sources.size() <= 4) {
        signal s;
        s.source_signal = sig;
        m_mic->sources.push_back(s);
    }
}
