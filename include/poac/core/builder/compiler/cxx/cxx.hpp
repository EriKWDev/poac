#pragma once

// internal
#include "poac/util/cfg.hpp"
#include "poac/util/format.hpp"
#include "poac/util/log.hpp"
#include "poac/util/result.hpp"
#include "poac/util/rustify.hpp"

namespace poac::core::builder::compiler::cxx {

using CompilerCommandNotFound = Error<
    "either general compilers or environment variable `POAC_CXX` was not found.\n"
    "Please export it like `export POAC_CXX=g++-11`.">;
using UnknownCompilerCommand =
    Error<"unknown compiler command found: {}", String>;
using UnsupportedCompiler = Error<"unsupported compiler found: {}", String>;

[[nodiscard]] Fn
get_compiler_ident(const String& compiler_command, bool is_macos)
    ->Result<util::cfg::Compiler>;

[[nodiscard]] Fn get_std_flag(
    util::cfg::Compiler compiler, const String& compiler_command, i64 edition,
    bool use_gnu_extension
)
    ->Result<String>;

[[nodiscard]] Fn get_compiler_command()->Result<String>;

[[nodiscard]] Fn get_command(i64 edition, bool use_gnu_extension)
    ->Result<String>;

} // namespace poac::core::builder::compiler::cxx
