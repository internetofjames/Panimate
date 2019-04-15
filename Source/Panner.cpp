/*
  ==============================================================================

    Panner.cpp
    Created: 28 Feb 2019 1:43:53pm
    Author:  James Bertrand

  ==============================================================================
*/

#include "Panner.h"

// Set the sample rate that the panner should operate at
// This should be set by your DAW
void Panner::setFs(int sampleRate){
    // check for valid sample rate
    if (sampleRate == 44100 || sampleRate == 48000 || sampleRate == 96000 || sampleRate == 192000){
        Fs = sampleRate;
    }
};

int Panner::getFs(){
    return Fs;
};

// Set the period of the LFO in milliseconds
void Panner::setRate(float rateInMilliseconds){
    rate = rateInMilliseconds;
}

float Panner::getRate(){
    return rate;
};

// Set the max amplitude of the LFO
void Panner::setDepth(float depth){
    this->depth = depth;
};

float Panner::getDepth(){
    return depth;
};

// Set the phase offset that the LFO will begin at
void Panner::setPhaseOffset(float phaseOffsetInDegrees){
    phaseOffset = phaseOffsetInDegrees;
};

float Panner::getPhaseOffset(){
    return phaseOffset;
};

// Set the position offset that the panner will begin within the stereo field
void Panner::setPosiitonOffset(float panPositionOffset){
    positionOffset = panPositionOffset;
};

float Panner::getPositionOffset(){
    return positionOffset;
};

// Set whether or not the LFO is tempo synced
void Panner::setTempoSynced(bool isSynced){
    tempoSynced = isSynced;
}

bool Panner::isTempoSynced(){
    return tempoSynced;
};

void Panner::setPhaseInverted(bool isInverted){
    phaseInverted = isInverted;
};

bool Panner::isPhaseInverted(){
    return phaseInverted;
};

void Panner::setLFOType(TypeLFO type){
    LFO = type;
};

Panner::TypeLFO Panner::getLFOType(){
    return LFO;
};
