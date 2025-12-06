#ifndef SON8_MATFOURD_MAT_ALIAS_HXX
#define SON8_MATFOURD_MAT_ALIAS_HXX

#include <son8/matfourd/layout.hxx>
#include <son8/matfourd/mat/type.hxx>

namespace son8::matfourd {
    // Mat (column matrix) aliases
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2 = Mat< Type, 2, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3 = Mat< Type, 3, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4 = Mat< Type, 4, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2x3 = Mat< Type, 2, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2x4 = Mat< Type, 2, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3x2 = Mat< Type, 3, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3x4 = Mat< Type, 3, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4x2 = Mat< Type, 4, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4x3 = Mat< Type, 4, 3, Layt >;

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_ALIAS_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
