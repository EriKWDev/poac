#pragma once

// std
#include <string>

// external
#include <openssl/evp.h> // NOLINT(build/include_order)
#include <openssl/sha.h> // SHA256_DIGEST_LENGTH // NOLINT(build/include_order)

// internal
#include "poac/util/format.hpp"
#include "poac/util/log.hpp"
#include "poac/util/result.hpp"
#include "poac/util/rustify.hpp"

namespace poac::util::sha256 {

using FailedToReadFile = Error<"Failed to read file: `{}`", String>;
using FailedToCreateSha256Digest = Error<"Failed to create a sha256 digest">;

inline constexpr i32 BUF_SIZE = 32768;
inline constexpr i32 HASH_SIZE = 65;

// ref: https://stackoverflow.com/a/2458382
Fn hash_string(const Vec<unsigned char>& hash)->String;

// ref: https://stackoverflow.com/a/34289358
[[nodiscard]] Fn sum(const Path& path)->Result<String>;

} // namespace poac::util::sha256
