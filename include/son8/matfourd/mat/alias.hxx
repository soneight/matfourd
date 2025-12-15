#ifndef SON8_MATFOURD_MAT_ALIAS_HXX
#define SON8_MATFOURD_MAT_ALIAS_HXX

#include <son8/matfourd/layout.hxx>
#include <son8/matfourd/mat/type.hxx>

namespace son8::matfourd {
    // default Mat (column matrix) aliases
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2   = Mat< Type, 2, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3   = Mat< Type, 3, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4   = Mat< Type, 4, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2x3 = Mat< Type, 2, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat2x4 = Mat< Type, 2, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3x2 = Mat< Type, 3, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat3x4 = Mat< Type, 3, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4x2 = Mat< Type, 4, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Mat4x3 = Mat< Type, 4, 3, Layt >;
    // col (column-major) aliases
    template< typename Type, bool Layt = Layout::ColMajor > using Col2x2 = Mat< Type, 2, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col3x3 = Mat< Type, 3, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col4x4 = Mat< Type, 4, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col2x3 = Mat< Type, 2, 3, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col2x4 = Mat< Type, 2, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col3x2 = Mat< Type, 3, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col3x4 = Mat< Type, 3, 4, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col4x2 = Mat< Type, 4, 2, Layt >;
    template< typename Type, bool Layt = Layout::ColMajor > using Col4x3 = Mat< Type, 4, 3, Layt >;
    // row (row-major) aliases
    template< typename Type, bool Layt = Layout::RowMajor > using Row2x2 = Mat< Type, 2, 2, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row3x3 = Mat< Type, 3, 3, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row4x4 = Mat< Type, 4, 4, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row2x3 = Mat< Type, 2, 3, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row2x4 = Mat< Type, 2, 4, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row3x2 = Mat< Type, 3, 2, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row3x4 = Mat< Type, 3, 4, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row4x2 = Mat< Type, 4, 2, Layt >;
    template< typename Type, bool Layt = Layout::RowMajor > using Row4x3 = Mat< Type, 4, 3, Layt >;
} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_ALIAS_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
