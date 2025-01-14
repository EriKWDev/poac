#ifndef POAC_CORE_BUILDER_MANIFEST_HPP_
#define POAC_CORE_BUILDER_MANIFEST_HPP_

// std
#include <array>

// external
#include <toml.hpp>

// internal
#include "poac/config.hpp"
#include "poac/core/builder/data.hpp"
#include "poac/core/resolver/types.hpp" // ResolvedDeps
#include "poac/data/manifest.hpp"
#include "poac/poac.hpp"

namespace poac::core::builder::manifest {

inline constexpr StringRef manifest_file_name = "ninja.build";
inline constexpr StringRef manifest_headers[] = {
    "This file is automatically generated by Poac.",
    "It is not intended for manual editing."};

inline fs::file_time_type
ninja_manifest_last_modified(const Path& build_dir) {
  return fs::last_write_time(build_dir / manifest_file_name);
}

inline bool
is_outdated(const Path& build_dir) {
  if (!fs::exists(build_dir / manifest_file_name)) {
    return true;
  }
  using poac::data::manifest::poac_toml_last_modified;
  return ninja_manifest_last_modified(build_dir)
         < poac_toml_last_modified(config::path::cwd);
}

bool
rebuild(data::NinjaMain& ninja_main, Status& status, String& err);

Vec<String>
gather_includes(const resolver::ResolvedDeps& resolved_deps);

Vec<toml::table>
get_cfg_profile(const toml::value& poac_manifest);

Vec<String>
gather_flags(
    const toml::value& poac_manifest, const String& name,
    const Option<String>& prefix = None
);

[[nodiscard]] Result<String>
construct(
    const Path& build_dir, const toml::value& poac_manifest,
    const resolver::ResolvedDeps& resolved_deps
);

[[nodiscard]] Result<void>
create(
    const Path& build_dir, const toml::value& poac_manifest,
    const resolver::ResolvedDeps& resolved_deps
);

} // namespace poac::core::builder::manifest

#endif // POAC_CORE_BUILDER_MANIFEST_HPP_
