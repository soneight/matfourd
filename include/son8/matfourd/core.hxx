#ifndef SON8_MATFOURD_CORE_HXX
#define SON8_MATFOURD_CORE_HXX
// std
#include <initializer_list>

#define SON8_MATFOURD_FUNC [[nodiscard]] inline auto
#define SON8_MATFOURD_DISC inline auto

namespace son8::matfourd {
    template< typename Type >
    using ForsakenInitialist_ = std::initializer_list< std::initializer_list< Type > >;
}

#endif//SON8_MATFOURD_CORE_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
