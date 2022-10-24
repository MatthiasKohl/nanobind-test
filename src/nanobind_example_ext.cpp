#include "opaque_ptr.hpp"

#include <nanobind/nanobind.h>

#include <cstdint>

namespace nanobind::detail {
template <>
struct type_caster<opaque_ptr> : type_caster<uintptr_t> {};
}

namespace nb = nanobind;

using namespace nb::literals;

NB_MODULE(nanobind_example_ext, m) {
    m.def("add", [](int a, opaque_ptr b) { return a + reinterpret_cast<uintptr_t>(b); }, "a"_a, "b"_a);
}
