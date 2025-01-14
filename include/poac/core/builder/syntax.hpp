// C++ class to generate .ninja files.
// This file is based on ninja_syntax.py from:
// https://github.com/ninja-build/ninja/blob/master/misc/ninja_syntax.py

#ifndef POAC_CORE_BUILDER_SYNTAX_HPP_
#define POAC_CORE_BUILDER_SYNTAX_HPP_

// std
#include <cassert>
#include <sstream>
#include <string>
#include <utility> // std::move

// external
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext/push_back.hpp>

// internal
#include "poac/poac.hpp"

namespace poac::core::builder::syntax {

struct RuleSet {
  Option<String> description = None;
  Option<String> depfile = None;
  bool generator = false;
  Option<String> pool = None;
  bool restat = false;
  Option<String> rspfile = None;
  Option<String> rspfile_content = None;
  Option<String> deps = None;
};

using Variables = HashMap<String, String>;
struct BuildSet {
  Option<Vec<String>> inputs = None;
  Option<Vec<Path>> implicit = None;
  Option<Path> order_only = None;
  Option<Variables> variables = None;
  Option<Path> implicit_outputs = None;
  Option<String> pool = None;
  Option<String> dyndep = None;
};

inline Path
escape_path(Path p) {
  String s = p.string();
  boost::replace_all(s, "$ ", "$$ ");
  boost::replace_all(s, " ", "$ ");
  boost::replace_all(s, ":", "$:");
  return s;
}

/// Escape a string such that it can be embedded into a Ninja file without
/// further interpretation.
inline void
escape(String& s) {
  assert(s.find('\n') == None); // Ninja syntax does not allow newlines
  // We only have one special metacharacter: '$'.
  boost::replace_all(s, "$", "$$");
}

/// Expand a string containing $vars as Ninja would.
///
/// Note: doesn't handle the full Ninja variable syntax, but it's enough
/// to make configure.py's use of it work.
String
expand(
    const String& text, const Variables& vars, const Variables& local_vars = {}
);

/// ref: https://stackoverflow.com/a/46379136
String
operator*(const String& s, usize n);

class Writer {
  std::ostringstream output;
  usize width;

  /// Returns the number of '$' characters right in front of s[i].
  usize
  count_dollars_before_index(StringRef s, usize i) const;

  // Export this function for testing
#if __has_include(<boost/ut.hpp>)
public:
#endif
  /// Write 'text' word-wrapped at self.width characters.
  void
  _line(String text, usize indent = 0);

public:
  explicit Writer(std::ostringstream&& o, usize w = 78)
      : output(std::move(o)), width(w) {}

  inline String
  get_value() const {
    return output.str();
  }

  inline void
  newline() {
    output << '\n';
  }

  void
  comment(const String& text);

  void
  variable(StringRef key, StringRef value, usize indent = 0);

  inline void
  variable(StringRef key, Vec<String> values, usize indent = 0) {
    const String value =
        boost::algorithm::join_if(values, " ", [](const auto& s) {
          return !s.empty();
        });
    _line(format("{} = {}", key, value), indent);
  }

  inline void
  pool(StringRef name, StringRef depth) {
    _line(format("pool {}", name));
    variable("depth", depth, 1);
  }

  void
  rule(StringRef name, StringRef command, const RuleSet& rule_set = {});

  Vec<String>
  build(
      const Vec<String>& outputs, StringRef rule, const BuildSet& build_set = {}
  );

  inline void
  include(const Path& path) {
    _line(format("include {}", path));
  }

  inline void
  subninja(const Path& path) {
    _line(format("subninja {}", path));
  }

  inline void
  default_(const Vec<String>& paths) {
    _line(format("default {}", boost::algorithm::join(paths, " ")));
  }

  inline friend std::ostream&
  operator<<(std::ostream& os, const Writer& w) {
    return os << w.get_value();
  }
};

} // namespace poac::core::builder::syntax

#endif // POAC_CORE_BUILDER_SYNTAX_HPP_
