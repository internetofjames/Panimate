/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class PanimateAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener, public Button::Listener, public ComboBox::Listener
{
public:
    PanimateAudioProcessorEditor (PanimateAudioProcessor&);
    ~PanimateAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider* slider) override;
    void buttonClicked(Button* button) override;
    void comboBoxChanged(ComboBox* comboBox) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PanimateAudioProcessor& processor;
    
    // Panimate interface controls
    Slider depth;
    Slider phaseOffset;
    Slider rate;    // rotary slider if tempo sync is off
    Slider positionOffset;
    
    // Labels for Sliders
    Label depthLabel;
    Label phaseOffsetLabel;
    Label rateLabel;    // for tempo sync = OFF
    Label positionOffsetLabel;
    

    TextButton phaseInvert;
    TextButton tempoSync;
    Label speedLabel;
    
    ComboBox LFOtype;
    Label LFOtypeLabel;
    
    ComboBox rateBars;    // combo box for number of bars if tempo sync is on
    ComboBox rateBeats;   // combo box for number of beats if tempo sync is on
    Label barsLabel;    // for tempo sync = ON
    Label beatsLabel;   // for tempo sync = ON
    
    // booleans to keep track of plugin feature toggles
    bool tempoSynced = false;
    bool phaseInverted = false;

    // maps (associative array) correlating comboBox ID numbers to numerical values
    std::map<int, int> tempoSyncBarValueMap{
        {1, 0},
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 4},
        {6, 5},
        {7, 6},
        {8, 7},
        {9, 8},
    };
    
    std::map<int, float> tempoSyncBeatValueMap{
        {1, 0.5f},
        {2, 0.25f},
        {3, 0.125f},
        {4, 0.0625f},
        {5, 0.03125f},
        {6, 0.015625f},
        {7, 0.0f}
    };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PanimateAudioProcessorEditor)
};
