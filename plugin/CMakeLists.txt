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
  include/AudioPlugin/PluginEditor.h
  include/AudioPlugin/PluginProcessor.h
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
  JUSE_USE_CURL=0
  JUSE_VST3_CAN_REPLACE_VST2=0
)

## `juce_generate_juce_header` will create a JuceHeader.h for a given target, which will be generated
## into your build tree. This should be included with `#include <JuceHeader.h>`. The include path for
## this header will be automatically added to the target. The main function of the JuceHeader is to
## include all your JUCE module headers; if you're happy to include module headers directly, you
## probably don't need to call this.
#
## juce_generate_juce_header(AudioPluginExample)
#
## `target_sources` adds source files to a target. We pass the target that needs the sources as the
## first argument, then a visibility parameter for the sources which should normally be PRIVATE.
## Finally, we supply a list of source files that will be built into the target. This is a standard
## CMake command.
#
#target_sources(AudioPluginExample
#  PRIVATE
#  src/PluginEditor.cpp
#  src/PluginProcessor.cpp)
#
## `target_compile_definitions` adds some preprocessor definitions to our target. In a Projucer
## project, these might be passed in the 'Preprocessor Definitions' field. JUCE modules also make use
## of compile definitions to switch certain features on/off, so if there's a particular feature you
## need that's not on by default, check the module header for the correct flag to set here. These
## definitions will be visible both to your code, and also the JUCE module code, so for new
## definitions, pick unique names that are unlikely to collide! This is a standard CMake command.
#
#target_compile_definitions(AudioPluginExample
#  PUBLIC
#  # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
#  JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
#  JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
#  JUCE_VST3_CAN_REPLACE_VST2=0)
#
## If your target needs extra binary assets, you can add them here. The first argument is the name of
## a new static library target that will include all the binary resources. There is an optional
## `NAMESPACE` argument that can specify the namespace of the generated binary data class. Finally,
## the SOURCES argument should be followed by a list of source files that should be built into the
## static library. These source files can be of any kind (wav data, images, fonts, icons etc.).
## Conversion to binary-data will happen when your target is built.
#
## juce_add_binary_data(AudioPluginData SOURCES ...)
#
## `target_link_libraries` links libraries and JUCE modules to other libraries or executables. Here,
## we're linking our executable target to the `juce::juce_audio_utils` module. Inter-module
## dependencies are resolved automatically, so `juce_core`, `juce_events` and so on will also be
## linked automatically. If we'd generated a binary data target above, we would need to link to it
## here too. This is a standard CMake command.
#
#target_link_libraries(AudioPluginExample
#  PRIVATE
#  # AudioPluginData           # If we'd created a binary data target, we'd link to it here
#  juce::juce_audio_utils
#  PUBLIC
#  juce::juce_recommended_config_flags
#  juce::juce_recommended_lto_flags
#  juce::juce_recommended_warning_flags)
