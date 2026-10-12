/**
 * @file        rex/ui/overlay/simple_settings_restart.h
 *
 * @brief       The simple settings overlay's restart-applied settings, for
 *              other settings front ends.
 */
#pragma once

#include <functional>
#include <string>
#include <vector>

namespace rex::ui {

// A setting the simple settings overlay applies only through Apply & Restart:
// its option labels, the option the current cvars select, and the cvar writes
// for an option. Lets another front end (such as a game's own options menu)
// offer the same settings with the overlay's exact cvar mappings.
struct RestartSetting {
  std::string id;  // stable key, e.g. "render_scale"
  std::string label;
  std::string desc;
  std::vector<std::string> options;
  // Option index the cvars select now.
  std::function<int()> current;
  // Writes the cvars for an option; does not save. The change takes effect
  // after a restart (SaveSimpleSettingsConfig, then restart the app).
  std::function<void(int)> apply;
};

// The restart-applied settings this build offers, in overlay order. Option
// lists are fixed when this is called (graphics device names, the Auto frame
// cap rate). current/apply are safe to call from any thread.
std::vector<RestartSetting> GetRestartSettings();

}  // namespace rex::ui
