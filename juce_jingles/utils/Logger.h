#pragma once

#if defined(ENABLE_JINGLE_LOGGER)

  BEGIN_JUCE_JINGLES_NAMESPACE

  #include <juce_core/juce_core.h>

  template<typename... Args>
  static inline void juce_jingles_log(juce::String str, Args&&... args)
  {
    static std::unique_ptr<juce::FileLogger> logger =
      std::unique_ptr<juce::FileLogger>(
        juce::FileLogger::createDefaultAppLogger(
          JUCE_JINGLES_PROJECT,
          JUCE_JINGLES_PROJECT + juce::String(".log"),
          ""));

    const juce::String message = juce::String::formatted(
      std::move(str), std::forward<Args>(args)...);

    logger->logMessage(message);
  }

  END_JUCE_JINGLES_NAMESPACE

  #define LOG(...) do { JUCE_JINGLES_NAMESPACE::juce_jingles_log(__VA_ARGS__); } while (false)

#else

  #define LOG(...)

#endif
