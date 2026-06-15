/*
  ==============================================================================

    SliderComponent.h
    Created: 15 Jun 2026 11:06:33pm
    Author:  Dami

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "AudioState.h"

class SliderComponent : public juce::Component
{
public:
	SliderComponent(AudioState& state) :audioState(state)
	{
		levelSlider.reset(new juce::Slider("level"));
		addAndMakeVisible(levelSlider.get());
		levelSlider->setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
		levelSlider->setRange(0.0f, 1.0f);
		levelSlider->setBounds(0, 0, 100, 500);
		levelSlider->setValue(0.1f);
		levelSlider->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 100, 20);
		levelSlider->onValueChange = [this] {	audioState.level.store(static_cast<float>(levelSlider->getValue()));	};


		freqSlider.reset(new juce::Slider("freq"));
		addAndMakeVisible(freqSlider.get());
		freqSlider->setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
		freqSlider->setRange(20.0f, 20000.0f);
		freqSlider->setBounds(100, 0, 100, 500);
		freqSlider->setValue(500.0f);
		freqSlider->setSkewFactorFromMidPoint(500.0f);
		freqSlider->setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 100, 20);
		freqSlider->setTextValueSuffix(" Hz");
		freqSlider->onValueChange = [this] {	audioState.freq.store(static_cast<double>(freqSlider->getValue()));	};


	}
	~SliderComponent()
	{
		levelSlider = nullptr;
		freqSlider = nullptr;
	}

	void resize() {}

	std::unique_ptr<juce::Slider> levelSlider;
	std::unique_ptr<juce::Slider> freqSlider;

	juce::Label freqSliderLabel;

private:

	AudioState& audioState;
};


