cmake_minimum_required(VERSION 3.22)
project(AudioPluginExample VERSION 0.0.1)


juce_add_plugin(${PROJECT_NAME}
  IS_SYNTH TRUE
  NEEDS_MIDI_INPUT FALSE
  NEEDS_MIDI_OUTPUT FALSE
  PLUGIN_CODE AUPL
  FORMATS VST3
  PRODUCT_NAME "${PROJECT_NAME} plugin"
)

target_sources(${PROJECT_NAME}
  PRIVATE
  src/PluginEditor.cpp
  src/PluginProcessor.cpp
  PUBLIC
  include/equalizer/PluginEditor.h
  include/equalizer/PluginProcessor.h
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
  include
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  juce::juce_audio_utils
  PUBLIC
  juce::juce_recommended_config_flags
  juce::juce_recommended_lto_flags
  juce::juce_recommended_warning_flags
)

target_compile_definitions(${PROJECT_NAME} PUBLIC
  JUCE_WEB_BROWSER=0
  JUCE_USE_CURL=0
  JUCE_VST3_CAN_REPLACE_VST2=0
)
