#pragma once

#include <equalizer/PluginProcessor.h>


class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor {
public:
  ~AudioPluginAudioProcessorEditor() override;
  explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor&);

  void paint(juce::Graphics&) override;
  void resized() override;

private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  AudioPluginAudioProcessor& processorRef;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
