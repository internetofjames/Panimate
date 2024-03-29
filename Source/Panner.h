/*
  ==============================================================================

    Panner.h
    Created: 28 Feb 2019 1:43:53pm
    Author:  James Bertrand

  ==============================================================================
*/

#ifndef PANNER_H
#define PANNER_H

#include <stdio.h>

class Panner {

public:
    // properties
    enum TypeLFO {sine=1,square=2,triangle=3,sawtooth=4};
    TypeLFO LFO = sine;
    
    // methods
    float processSample(float x, int channel);
    
    void setFs(int sampleRate);
    int getFs();
    
    void setBPM(float tempo);
    float getBPM();
    
    void setTimeSignature(int numerator, int denominator);
    int getTimeSigNumerator();
    int getTimeSigDenominator();
    
    void setRate(float rateInMilliseconds);
    void setRate(int numBars, float numBeats);
    float getRate();
    
    void setDepth(float depth);
    float getDepth();
    
    void setPhaseOffset(float phaseOffsetInDegrees);
    float getPhaseOffset();
    
    void setPositonOffset(float panPositionOffset);
    float getPositionOffset();
    
    void setTempoSynced(bool isSynced);
    bool isTempoSynced();
    
    void setPhaseInverted(bool isInverted);
    bool isPhaseInverted();
    
    void setCurrentAngle(float currentPlaybackPosition);
    
    void setLFOType(TypeLFO type);
    TypeLFO getLFOType();
    float getPanPosition();
    
    
private:
    // properties
    int Fs = 48000;
    int channel = 0;
    
    float bpm = 120;
    
    int timeSigNumerator = 4;
    int timeSigDenominator = 4;
    
    float rate = 1.0f; // interpreted as the period of the LFO, in seconds
    float depth = 0.0f;
    float phaseOffset = 0.0f;
    float positionOffset = 0.0f;
    
    float currentAngle = 0.0f;
    float angleChange;
    
    bool tempoSynced = false;
    bool phaseInverted = false;
    
    // methods
    float sineFunction();
    float squareFunction();
    float sawtoothFunction();
    float triangleFunction();
    
    void updateAngle();
    float getNextSample();
    
    void setAngleChange(float rate);
    
    float panPosition;
};

#endif /* Panner.h */
