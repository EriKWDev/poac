#ifndef POAC_UTIL_TERMCOLOR2_TO_COLOR_HPP_
#define POAC_UTIL_TERMCOLOR2_TO_COLOR_HPP_

// std
#include <cstddef> // std::size_t
#include <string> // std::basic_string
#include <string_view> // std::basic_string_view

// internal
#include "poac/util/termcolor2/color_mode.hpp"
#include "poac/util/termcolor2/presets.hpp"

namespace termcolor2 {

template <typename Fn, typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_color(Fn&& fn, const std::basic_string<CharT>& str) {
  if (should_color()) {
    return fn() + str + reset_v<CharT>();
  } else {
    return str;
  }
}

//
// Foreground manipulators
//
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_gray(const CharT* str) {
  return to_color(gray_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_gray(const CharT* str, std::size_t len) {
  return to_color(gray_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_gray(const std::basic_string<CharT>& str) {
  return to_color(gray_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_gray(const std::basic_string_view<CharT> str) {
  return to_color(gray_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_red(const CharT* str) {
  return to_color(red_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_red(const CharT* str, std::size_t len) {
  return to_color(red_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_red(const std::basic_string<CharT>& str) {
  return to_color(red_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_red(const std::basic_string_view<CharT> str) {
  return to_color(red_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_green(const CharT* str) {
  return to_color(green_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_green(const CharT* str, std::size_t len) {
  return to_color(green_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_green(const std::basic_string<CharT>& str) {
  return to_color(green_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_green(const std::basic_string_view<CharT> str) {
  return to_color(green_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_yellow(const CharT* str) {
  return to_color(yellow_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_yellow(const CharT* str, std::size_t len) {
  return to_color(yellow_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_yellow(const std::basic_string<CharT>& str) {
  return to_color(yellow_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_yellow(const std::basic_string_view<CharT> str) {
  return to_color(yellow_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_blue(const CharT* str) {
  return to_color(blue_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_blue(const CharT* str, std::size_t len) {
  return to_color(blue_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_blue(const std::basic_string<CharT>& str) {
  return to_color(blue_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_blue(const std::basic_string_view<CharT> str) {
  return to_color(blue_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_magenta(const CharT* str) {
  return to_color(magenta_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_magenta(const CharT* str, std::size_t len) {
  return to_color(magenta_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_magenta(const std::basic_string<CharT>& str) {
  return to_color(magenta_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_magenta(const std::basic_string_view<CharT> str) {
  return to_color(magenta_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_cyan(const CharT* str) {
  return to_color(cyan_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_cyan(const CharT* str, std::size_t len) {
  return to_color(cyan_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_cyan(const std::basic_string<CharT>& str) {
  return to_color(cyan_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_cyan(const std::basic_string_view<CharT> str) {
  return to_color(cyan_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_white(const CharT* str) {
  return to_color(white_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_white(const CharT* str, std::size_t len) {
  return to_color(white_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_white(const std::basic_string<CharT>& str) {
  return to_color(white_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_white(const std::basic_string_view<CharT> str) {
  return to_color(white_v<CharT>, std::basic_string<CharT>(str));
}

//
// Background manipulators
//
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_gray(const CharT* str) {
  return to_color(on_gray_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_gray(const CharT* str, std::size_t len) {
  return to_color(on_gray_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_gray(const std::basic_string<CharT>& str) {
  return to_color(on_gray_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_gray(const std::basic_string_view<CharT> str) {
  return to_color(on_gray_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_red(const CharT* str) {
  return to_color(on_red_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_red(const CharT* str, std::size_t len) {
  return to_color(on_red_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_red(const std::basic_string<CharT>& str) {
  return to_color(on_red_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_red(const std::basic_string_view<CharT> str) {
  return to_color(on_red_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_green(const CharT* str) {
  return to_color(on_green_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_green(const CharT* str, std::size_t len) {
  return to_color(on_green_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_green(const std::basic_string<CharT>& str) {
  return to_color(on_green_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_green(const std::basic_string_view<CharT> str) {
  return to_color(on_green_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_yellow(const CharT* str) {
  return to_color(on_yellow_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_yellow(const CharT* str, std::size_t len) {
  return to_color(on_yellow_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_yellow(const std::basic_string<CharT>& str) {
  return to_color(on_yellow_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_yellow(const std::basic_string_view<CharT> str) {
  return to_color(on_yellow_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_blue(const CharT* str) {
  return to_color(on_blue_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_blue(const CharT* str, std::size_t len) {
  return to_color(on_blue_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_blue(const std::basic_string<CharT>& str) {
  return to_color(on_blue_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_blue(const std::basic_string_view<CharT> str) {
  return to_color(on_blue_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_magenta(const CharT* str) {
  return to_color(on_magenta_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_magenta(const CharT* str, std::size_t len) {
  return to_color(on_magenta_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_magenta(const std::basic_string<CharT>& str) {
  return to_color(on_magenta_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_magenta(const std::basic_string_view<CharT> str) {
  return to_color(on_magenta_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_cyan(const CharT* str) {
  return to_color(on_cyan_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_cyan(const CharT* str, std::size_t len) {
  return to_color(on_cyan_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_cyan(const std::basic_string<CharT>& str) {
  return to_color(on_cyan_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_cyan(const std::basic_string_view<CharT> str) {
  return to_color(on_cyan_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_white(const CharT* str) {
  return to_color(on_white_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_white(const CharT* str, std::size_t len) {
  return to_color(on_white_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_white(const std::basic_string<CharT>& str) {
  return to_color(on_white_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_on_white(const std::basic_string_view<CharT> str) {
  return to_color(on_white_v<CharT>, std::basic_string<CharT>(str));
}

//
// Attribute manipulators
//
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_bold(const CharT* str) {
  return to_color(bold_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_bold(const CharT* str, std::size_t len) {
  return to_color(bold_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_bold(const std::basic_string<CharT>& str) {
  return to_color(bold_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_bold(const std::basic_string_view<CharT> str) {
  return to_color(bold_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_dark(const CharT* str) {
  return to_color(dark_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_dark(const CharT* str, std::size_t len) {
  return to_color(dark_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_dark(const std::basic_string<CharT>& str) {
  return to_color(dark_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_dark(const std::basic_string_view<CharT> str) {
  return to_color(dark_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_underline(const CharT* str) {
  return to_color(underline_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_underline(const CharT* str, std::size_t len) {
  return to_color(underline_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_underline(const std::basic_string<CharT>& str) {
  return to_color(underline_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_underline(const std::basic_string_view<CharT> str) {
  return to_color(underline_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_blink(const CharT* str) {
  return to_color(blink_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_blink(const CharT* str, std::size_t len) {
  return to_color(blink_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_blink(const std::basic_string<CharT>& str) {
  return to_color(blink_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_blink(const std::basic_string_view<CharT> str) {
  return to_color(blink_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_reverse(const CharT* str) {
  return to_color(reverse_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_reverse(const CharT* str, std::size_t len) {
  return to_color(reverse_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_reverse(const std::basic_string<CharT>& str) {
  return to_color(reverse_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_reverse(const std::basic_string_view<CharT> str) {
  return to_color(reverse_v<CharT>, std::basic_string<CharT>(str));
}

template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_concealed(const CharT* str) {
  return to_color(concealed_v<CharT>, std::basic_string<CharT>(str));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_concealed(const CharT* str, std::size_t len) {
  return to_color(concealed_v<CharT>, std::basic_string<CharT>(str, len));
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_concealed(const std::basic_string<CharT>& str) {
  return to_color(concealed_v<CharT>, str);
}
template <typename CharT>
inline TERMCOLOR2_CXX20_CONSTEVAL std::basic_string<CharT>
to_concealed(const std::basic_string_view<CharT> str) {
  return to_color(concealed_v<CharT>, std::basic_string<CharT>(str));
}

} // namespace termcolor2

#endif // POAC_UTIL_TERMCOLOR2_TO_COLOR_HPP_
