/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PanimateAudioProcessorEditor::PanimateAudioProcessorEditor (PanimateAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (700, 400);
    
    // add Panimate interface controls
    
    // ComboBox for LFO type selection
    LFOtype.addListener(this);
    LFOtype.setBounds(25, 50, 200, 25);
    LFOtype.addItem("Sine", 1);
    LFOtype.addItem("Square", 2);
    LFOtype.addItem("Triangle", 3);
    LFOtype.addItem("Sawtooth", 4);
    LFOtype.setSelectedId(1);
    LFOtype.setJustificationType(Justification::centred);
    addAndMakeVisible(LFOtype);
    
    LFOtypeLabel.setText("Pan Type", dontSendNotification);
    LFOtypeLabel.attachToComponent(&LFOtype, false);
    LFOtypeLabel.setJustificationType(Justification::left);
    addAndMakeVisible(LFOtypeLabel);
    
    // Slider for depth
    depth.addListener(this);
    depth.setBounds(25, 125, 110, 110);
    depth.setSliderStyle(Slider::RotaryVerticalDrag);
    depth.setRange(0, 100, 1);
    depth.setValue(100);
    depth.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 15);
    depth.setNumDecimalPlacesToDisplay(0);
    depth.setTextValueSuffix("%");
    addAndMakeVisible(depth);
    
    depthLabel.setText("Depth", dontSendNotification);
    depthLabel.attachToComponent(&depth, false);
    depthLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(depthLabel);
    
    
    // Slider for LFO phase offset
    phaseOffset.addListener(this);
    phaseOffset.setBounds(25, 275, 110, 110);
    phaseOffset.setSliderStyle(Slider::RotaryVerticalDrag);
    phaseOffset.setRange(0, 360, 1);
    phaseOffset.setValue(0);
    phaseOffset.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 15);
    phaseOffset.setNumDecimalPlacesToDisplay(0);
    addAndMakeVisible(phaseOffset);
    
    phaseOffsetLabel.setText("Phase Offset", dontSendNotification);
    phaseOffsetLabel.attachToComponent(&phaseOffset, false);
    phaseOffsetLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(phaseOffsetLabel);
    
    // Slider for rate
    rate.addListener(this);
    rate.setBounds(550, 125, 110, 110);
    rate.setSliderStyle(Slider::RotaryVerticalDrag);
    rate.setRange(0, 10000);
    rate.setValue(0);
    rate.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 15);
    rate.setNumDecimalPlacesToDisplay(3);
    addAndMakeVisible(rate);
    
    rateLabel.setText("Rate (ms)", dontSendNotification);
    rateLabel.attachToComponent(&rate, false);
    rateLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(rateLabel);
    
    // ComboBox for rateBars
    // not visible by default
    rateBars.addListener(this);
    rateBars.setBounds(560, 110, 90, 40);
    rateBars.addItem("1", 1);
    rateBars.addItem("2", 2);
    rateBars.addItem("3", 3);
    rateBars.addItem("4", 4);
    rateBars.addItem("5", 5);
    rateBars.addItem("6", 6);
    rateBars.addItem("7", 7);
    rateBars.addItem("8", 8);
    rateBars.setSelectedId(1);
    rateBars.setJustificationType(Justification::centred);
    addChildComponent(&rateBars);
    
    barsLabel.setText("Bars:", dontSendNotification);
    barsLabel.attachToComponent(&rateBars, false);
    barsLabel.setJustificationType(Justification::centred);
    addChildComponent(&barsLabel);
    
    // ComboBox for rateBeats
    // not visible by default
    rateBeats.addListener(this);
    rateBeats.setBounds(560, 190, 90, 40);
    rateBeats.addItem("1/2", 1);
    rateBeats.addItem("1/4", 2);
    rateBeats.addItem("1/8", 3);
    rateBeats.addItem("1/16", 4);
    rateBeats.addItem("1/32", 5);
    rateBeats.addItem("1/64", 6);
    rateBeats.setSelectedId(1);
    rateBeats.setJustificationType(Justification::centred);
    addChildComponent(&rateBeats);
    
    beatsLabel.setText("Beats:", dontSendNotification);
    beatsLabel.attachToComponent(&rateBeats, false);
    beatsLabel.setJustificationType(Justification::centred);
    addChildComponent(&beatsLabel);
    
    // Slider for pan position starting point
    positionOffset.addListener(this);
    positionOffset.setBounds(550, 275, 110, 110);
    positionOffset.setSliderStyle(Slider::RotaryVerticalDrag);
    positionOffset.setRange(-100, 100, 1);
    positionOffset.setValue(0);
    positionOffset.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 15);
    positionOffset.setNumDecimalPlacesToDisplay(0);
    addAndMakeVisible(positionOffset);
    
    positionOffsetLabel.setText("Start Position", dontSendNotification);
    positionOffsetLabel.attachToComponent(&positionOffset, false);
    positionOffsetLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(positionOffsetLabel);
    
    // Toggle button for phase inversion
    phaseInvert.addListener(this);
    phaseInvert.setBounds(200, 25, 25, 25);
    phaseInvert.setClickingTogglesState(true);
    phaseInvert.setButtonText(String (CharPointer_UTF8 ("Ø")));
    addAndMakeVisible(phaseInvert);
    
    // Text button for tempo synchronization
    tempoSync.addListener(this);
    tempoSync.setBounds(475, 50, 200, 25);
    tempoSync.setClickingTogglesState(true);
    tempoSync.setButtonText("Tempo Sync : OFF");
    addAndMakeVisible(tempoSync);
    
    speedLabel.setText("Speed", dontSendNotification);
    speedLabel.attachToComponent(&tempoSync, false);
    speedLabel.setJustificationType(Justification::centred);
    addAndMakeVisible(speedLabel);
}

PanimateAudioProcessorEditor::~PanimateAudioProcessorEditor()
{
}

//==============================================================================
void PanimateAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Panimate", getLocalBounds(), Justification::centredTop, 1);
    g.drawFittedText("Panning visualization graphic to go here in later version...", getLocalBounds(), Justification::centred, 5);
}

void PanimateAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void PanimateAudioProcessorEditor::sliderValueChanged(Slider *slider) {
    
}

void PanimateAudioProcessorEditor::buttonClicked(Button *button) {
    
    // change tempo sync button color to show functionality
    if (button == &tempoSync) {
        if (button->getToggleState() == true) {
            // tempoSync is toggled on
            button->setColour(TextButton::ColourIds::buttonOnColourId, Colour(255, 255, 0));
            button->setColour(TextButton::ColourIds::textColourOnId, Colour(0, 0, 0));
            button->setButtonText("Temp Sync : ON");
            rate.setVisible(false);
            rateBars.setVisible(true);
            rateBeats.setVisible(true);
        }
        else {
            // tempoSync is toggled off
            button->setColour(TextButton::ColourIds::buttonColourId, Colour(0, 0, 0));
            button->setColour(TextButton::ColourIds::textColourOnId, Colour(255, 255, 255));
            button->setButtonText("Temp Sync : OFF");
            rate.setVisible(true);
            rateBars.setVisible(false);
            rateBeats.setVisible(false);
        }
    }
    if (button == &phaseInvert) {
        if (button->getToggleState() == true) {
            // phaseInvert is toggled on
            button->setColour(TextButton::ColourIds::buttonOnColourId, Colour(255, 255, 0));
            button->setColour(TextButton::ColourIds::textColourOnId, Colour(0, 0, 0));
        }
        else {
            // phaseInvert is toggled off
            button->setColour(TextButton::ColourIds::buttonColourId, Colour(0, 0, 0));
            button->setColour(TextButton::ColourIds::textColourOnId, Colour(255, 255, 255));
        }
        
    }
}

void PanimateAudioProcessorEditor::comboBoxChanged(ComboBox *comboBox) {
    
}
