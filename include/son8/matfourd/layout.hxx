#ifndef SON8_MATFOURD_LAYOUT_HXX
#define SON8_MATFOURD_LAYOUT_HXX

namespace son8::matfourd {

    class Layout {
        struct RowMajor_ {
            constexpr operator bool( ) const { return true; }
        };

        struct ColMajor_ {
            constexpr operator bool( ) const { return false; }
        };
    public:
        static constexpr RowMajor_ RowMajor{ };
        static constexpr ColMajor_ ColMajor{ };
    };

}

#endif//SON8_MATFOURD_LAYOUT_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
