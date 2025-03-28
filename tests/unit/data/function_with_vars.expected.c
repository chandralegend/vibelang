// Generated by VibeLang Compiler

#include "runtime.h"
#include "vibelang.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations for runtime functions
extern VibeValue *vibe_execute_prompt(const char *prompt);
extern char *format_prompt(const char *template, char **var_names,
                           char **var_values, int var_count);

// Weather: weather description
typedef const char *Weather;

Weather getWeather(const char *city, const char *day);

Weather getWeather(const char *city, const char *day) {
  const char *location = city;
  const char *when = day;
  // LLM Prompt: What is the weather like in {location} on {when}?
  {
    VibeValue *prompt_result = NULL;
    const char *prompt_template =
        "What is the weather like in {location} on {when}?";
    int var_count = 4;
    char **var_names = malloc(sizeof(char *) * var_count);
    char **var_values = malloc(sizeof(char *) * var_count);
    var_names[0] = "city";
    var_values[0] = strdup(city ? city : "");
    var_names[1] = "day";
    var_values[1] = strdup(day ? day : "");
    var_names[2] = "location";
    var_values[2] = strdup(location ? location : "");
    var_names[3] = "when";
    var_values[3] = strdup(when ? when : "");
    char *formatted_prompt =
        format_prompt(prompt_template, var_names, var_values, var_count);
    prompt_result = vibe_execute_prompt(formatted_prompt);
    if (prompt_result) {
      // Convert LLM response to the appropriate return type
      return vibe_value_get_string(prompt_result);
    }
    // Free resources
    free(formatted_prompt);
    for (int i = 0; i < var_count; i++) {
      free(var_values[i]);
    }
    free(var_names);
    free(var_values);
    // Default return if prompt fails
    return NULL; // Should be replaced with appropriate default
  }
}
