#ifndef SON8_MATFOURD_VEC_ALIAS_HXX
#define SON8_MATFOURD_VEC_ALIAS_HXX

#include <son8/matfourd/layout.hxx>
#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // default Vec (column vector) aliases
    template< typename Type, bool Layt = Layout::ColMajor > using Vec2 = Vec< Type, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Vec3 = Vec< Type, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Vec4 = Vec< Type, 4, Layt >;
    // col (column-major) aliases
    template< typename Type, bool Layt = Layout::ColMajor > using Col2 = Vec< Type, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col3 = Vec< Type, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col4 = Vec< Type, 4, Layt >;
    // row (row-major) aliases
    template< typename Type, bool Layt = Layout::RowMajor > using Row2 = Vec< Type, 2, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row3 = Vec< Type, 3, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row4 = Vec< Type, 4, Layt >;

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_ALIAS_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
