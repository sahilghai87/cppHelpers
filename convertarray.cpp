#include <type_traits>
#include <concepts>
#include <string_view>
#include <functional>
#include <tuple>
#include <iostream>
#include <utility>
#include <optional>
#include <exception>
#include <span>
#include <iomanip>
#include <unordered_map>
#include <variant>
#include <any>
#include <iterator>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <ranges>
#include <algorithm>

#define fwd(arg) std::forward<decltype(arg)>(arg)

template <class T, std::size_t N>
constexpr std::array<std::remove_cv_t<T>, N> to_array( T (&a)[N] ){
    return [&]<std::size_t ... indexes>(std::index_sequence<indexes...>){
        return std::array<std::remove_cv_t<T>, N>{ a[indexes]... };
    }(std::make_index_sequence<N>{});
}

template< class T, std::size_t N >
constexpr std::array<std::remove_cv_t<T>, N> to_array( T (&&a)[N] ){
    return [&]<std::size_t ... indexes>(std::index_sequence<indexes...>){
        return std::array<std::remove_cv_t<T>, N>{ fwd(a)[indexes]... };
    }(std::make_index_sequence<N>{});
}

auto main() -> int {
    constexpr int values[] = { 1,2,3 };
    static_assert(std::array{1,2,3} == to_array(values));
}
