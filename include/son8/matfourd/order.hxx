#ifndef SON8_MATFOURD_ORDER_HXX
#define SON8_MATFOURD_ORDER_HXX

namespace son8::matfourd {

    class Order {
        struct RowMajor_ {
            constexpr operator bool( ) const noexcept { return true; }
        };

        struct ColMajor_ {
            constexpr operator bool( ) const noexcept { return false; }
        };
    public:
        static constexpr RowMajor_ RowMajor{ };
        static constexpr ColMajor_ ColMajor{ };
    };

#   ifdef SON8_MATFOURD_INCLUDE_DEPRECATED
        using Layout [[deprecated("son8::matfourd: Layout is subject to be removed/changed use Order instead")]] = Order;
#   endif
}

#endif//SON8_MATFOURD_ORDER_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
