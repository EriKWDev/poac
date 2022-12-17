#pragma once

// std
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

// internal
#include "poac/util/semver/token.hpp"

namespace semver {

constexpr auto is_whitespace(const char c) noexcept -> bool {
  switch (c) {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
      return true;
    default:
      return false;
  }
}

constexpr auto is_digit(const char c) noexcept -> bool {
  return '0' <= c && c <= '9';
}

constexpr auto is_alphabet(const char c) noexcept -> bool {
  return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

constexpr auto is_alpha_numeric(const char c) noexcept -> bool {
  return is_digit(c) || is_alphabet(c);
}

constexpr auto str_to_uint(std::string_view s) noexcept
    -> std::optional<std::uint_fast64_t> {
  std::uint_fast64_t i = 0;
  std::uint_fast64_t digit = 1;
  for (int size = s.size() - 1; size >= 0; --size) {
    const char c = s[size];
    if (is_digit(c)) {
      i += (c - '0') * digit;
    } else {
      return std::nullopt;
    }
    digit *= 10;
  }
  return i;
}

class Lexer {
public:
  using SizeType = std::size_t;
  using StringType = std::string_view;
  using ValueType = StringType::value_type;
  using TraitsType = StringType::traits_type;
  using ConstIterator = StringType::const_iterator;
  using ConstReverseIterator = StringType::const_reverse_iterator;

  StringType str;
  SizeType c1_index{0};

  explicit Lexer(StringType s) : str(s) {}

  auto next() -> Token;

  [[nodiscard]] constexpr auto size() const noexcept -> SizeType {
    return str.size();
  }
  [[nodiscard]] constexpr auto max_size() const noexcept -> SizeType {
    return str.max_size();
  }
  [[nodiscard]] constexpr auto empty() const noexcept -> bool {
    return str.empty();
  }

private:
  inline void step() noexcept { ++c1_index; }

  void step_n(const SizeType& n) noexcept;

  /// Access the one character, or set it if it is not set.
  [[nodiscard]] inline auto one() const noexcept -> ValueType {
    return str[c1_index];
  }

  /// Access two characters.
  [[nodiscard]] inline auto two() const noexcept
      -> std::pair<ValueType, ValueType> {
    return {str[c1_index], str[c1_index + 1]};
  }

  /// Consume a component.
  ///
  /// A component can either be an alphanumeric or numeric.
  /// Does not permit leading zeroes if numeric.
  auto component() -> Token;

  /// Consume whitespace.
  auto whitespace() -> Token;
};

} // end namespace semver
