#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
	setAudioChannels(2, 2);

	setSize(800, 600);

	addAndMakeVisible(&sliderComponent);

	sliderComponent.freqSlider->onValueChange = [this] {	if (currentSampleRate > 0.0) updateAngleDelta();	};

}

MainComponent::~MainComponent()
{
	shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
	currentSampleRate = sampleRate;
	updateAngleDelta();
}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
	//auto level = 0.1f;

	auto level = audioState.level.load();

	auto* leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
	auto* rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);
	for (auto sample = 0; sample < bufferToFill.numSamples; ++sample)
	{
		auto currentSample = (float)std::sin(currentAngle);
		currentAngle += angleDelta;
		leftBuffer[sample] = currentSample * level;
		rightBuffer[sample] = currentSample * level;
	}
}

void MainComponent::releaseResources()
{

}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

}

void MainComponent::resized()
{
	sliderComponent.setBounds(getLocalBounds());
}
