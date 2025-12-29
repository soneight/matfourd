#ifndef SON8_MATFOURD_MAT_ALIAS_HXX
#define SON8_MATFOURD_MAT_ALIAS_HXX

#include <son8/matfourd/order.hxx>
#include <son8/matfourd/mat/type.hxx>

namespace son8::matfourd {
    // default Mat (column matrix) aliases
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat2   = Mat< Type, 2, 2, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat3   = Mat< Type, 3, 3, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat4   = Mat< Type, 4, 4, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat2x3 = Mat< Type, 2, 3, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat2x4 = Mat< Type, 2, 4, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat3x2 = Mat< Type, 3, 2, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat3x4 = Mat< Type, 3, 4, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat4x2 = Mat< Type, 4, 2, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Mat4x3 = Mat< Type, 4, 3, RowMajor >;
    // col (column-major) aliases
    template< typename Type > using Col2x2 = Mat< Type, 2, 2, Order::ColMajor >;
    template< typename Type > using Col3x3 = Mat< Type, 3, 3, Order::ColMajor >;
    template< typename Type > using Col4x4 = Mat< Type, 4, 4, Order::ColMajor >;
    template< typename Type > using Col2x3 = Mat< Type, 2, 3, Order::ColMajor >;
    template< typename Type > using Col2x4 = Mat< Type, 2, 4, Order::ColMajor >;
    template< typename Type > using Col3x2 = Mat< Type, 3, 2, Order::ColMajor >;
    template< typename Type > using Col3x4 = Mat< Type, 3, 4, Order::ColMajor >;
    template< typename Type > using Col4x2 = Mat< Type, 4, 2, Order::ColMajor >;
    template< typename Type > using Col4x3 = Mat< Type, 4, 3, Order::ColMajor >;
    // row (row-major) aliases
    template< typename Type > using Row2x2 = Mat< Type, 2, 2, Order::RowMajor >;
    template< typename Type > using Row3x3 = Mat< Type, 3, 3, Order::RowMajor >;
    template< typename Type > using Row4x4 = Mat< Type, 4, 4, Order::RowMajor >;
    template< typename Type > using Row2x3 = Mat< Type, 2, 3, Order::RowMajor >;
    template< typename Type > using Row2x4 = Mat< Type, 2, 4, Order::RowMajor >;
    template< typename Type > using Row3x2 = Mat< Type, 3, 2, Order::RowMajor >;
    template< typename Type > using Row3x4 = Mat< Type, 3, 4, Order::RowMajor >;
    template< typename Type > using Row4x2 = Mat< Type, 4, 2, Order::RowMajor >;
    template< typename Type > using Row4x3 = Mat< Type, 4, 3, Order::RowMajor >;
} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_ALIAS_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
