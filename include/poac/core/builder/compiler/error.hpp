#pragma once

// internal
#include "poac/core/builder/compiler/lang.hpp"
#include "poac/util/cfg.hpp" // compiler
#include "poac/util/format.hpp"
#include "poac/util/log.hpp"
#include "poac/util/result.hpp"
#include "poac/util/rustify.hpp"
#include "poac/util/semver/semver.hpp"

namespace poac::core::builder::compiler::error {

Fn to_string(util::cfg::Compiler comp)->String;

} // namespace poac::core::builder::compiler::error

namespace fmt {

template <>
struct formatter<poac::util::cfg::Compiler> {
  static constexpr Fn parse(format_parse_context& ctx) { return ctx.begin(); }

  template <typename FormatContext>
  inline Fn format(poac::util::cfg::Compiler c, FormatContext& ctx) {
    return format_to(
        ctx.out(), "{}", poac::core::builder::compiler::error::to_string(c)
    );
  }
};

} // namespace fmt

namespace poac::core::builder::compiler::error {

using UnsupportedLangVersion = Error<
    "`{}` ({}) does not support {} edition: `{}`", util::cfg::Compiler,
    semver::Version, poac::core::builder::compiler::lang::Lang, i64>;
using FailedToGetCompilerVersion =
    Error<"failed to get version of compiler `{}`", util::cfg::Compiler>;

} // namespace poac::core::builder::compiler::error
