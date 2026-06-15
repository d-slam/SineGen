#pragma once

#include <JuceHeader.h>
#include "SliderComponent.h"
#include "AudioState.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    AudioState audioState;

    SliderComponent sliderComponent{ audioState };

    double currentSampleRate = 0.0, currentAngle = 0.0, angleDelta = 0.0; // [1]

    void updateAngleDelta()
    {
        auto cyclesPerSample = sliderComponent.freqSlider->getValue() / currentSampleRate; 
        //auto cyclesPerSample = static_cast<double>(audioState.freq.load()) / currentSampleRate; 

        angleDelta = cyclesPerSample * 2.0 * juce::MathConstants<double>::pi; // [3]
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
