#ifndef SON8_MATFOURD_VEC_ALIAS_HXX
#define SON8_MATFOURD_VEC_ALIAS_HXX

#include <son8/matfourd/order.hxx>
#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // default Vec (column vector) aliases
    template< typename Type, bool RowMajor = Order::ColMajor > using Vec2 = Vec< Type, 2, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Vec3 = Vec< Type, 3, RowMajor >;
    template< typename Type, bool RowMajor = Order::ColMajor > using Vec4 = Vec< Type, 4, RowMajor >;
    // col (column-major) aliases
    template< typename Type > using Col2 = Vec< Type, 2, Order::ColMajor >;
    template< typename Type > using Col3 = Vec< Type, 3, Order::ColMajor >;
    template< typename Type > using Col4 = Vec< Type, 4, Order::ColMajor >;
    // row (row-major) aliases
    template< typename Type > using Row2 = Vec< Type, 2, Order::RowMajor >;
    template< typename Type > using Row3 = Vec< Type, 3, Order::RowMajor >;
    template< typename Type > using Row4 = Vec< Type, 4, Order::RowMajor >;

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_ALIAS_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
