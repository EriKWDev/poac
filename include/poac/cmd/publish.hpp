#ifndef POAC_CMD_PUBLISH_HPP_
#define POAC_CMD_PUBLISH_HPP_

// external
#include <structopt/app.hpp>
#include <toml.hpp>

// internal
#include "poac/poac.hpp"

namespace poac::cmd::publish {

struct Options : structopt::sub_command {
  /// API Token obtained on poac.pm
  Option<String> token;

  /// Perform all checks without uploading
  Option<bool> dry_run = false;

  /// Allow dirty working directories to be packaged
  Option<bool> allow_dirty = false;
};

using APITokenNotFound = Error<
    "API token not found; please provide it through `--token "
    "$YOUR_TOKEN` or `poac login $YOUR_TOKEN`. If you do not have "
    "it yet, try signing up into poac.pm and generate a token at:\n"
    "  https://poac.pm/settings/tokens">;
using FailedToReadCred = Error<
    "failed to read credentials from {0}; do not edit it manually "
    "and use the `poac login` command.",
    Path>;
using FailedToReadManifest = Error<
    "failed to read a manifest file ({0}) for this package. Make "
    "sure to the current directory was set up using Poac.",
    Path>;

[[nodiscard]] anyhow::result<toml::value>
get_manifest();

[[nodiscard]] anyhow::result<String>
get_token(const Options& opts);

using NotImplemented = Error<
    "failed to publish; `publish` command is currently under development">;

[[nodiscard]] anyhow::result<void>
exec(const Options& opts);

} // namespace poac::cmd::publish

STRUCTOPT(poac::cmd::publish::Options, token, dry_run, allow_dirty);

#endif // POAC_CMD_PUBLISH_HPP_
