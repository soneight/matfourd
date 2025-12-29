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

} // namespace son8::matfourd

#endif//SON8_MATFOURD_ORDER_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
