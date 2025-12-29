#ifndef SON8_MATFOURD_LAYOUT_HXX
#define SON8_MATFOURD_LAYOUT_HXX

#ifndef SON8_MATFOURD_INCLUDE_DEPRECATED
#error "son8::matfourd: layout is subject to be removed/changed use <son8/matfourd/order.hxx> instead or define (or set cmake option) SON8_MATFOURD_INCLUDE_DEPRECATED"
#else
#include <son8/matfourd/order.hxx>
namespace son8::matfourd {
    using Layout [[deprecated("son8::matfourd: Layout is subject to be removed/changed use Order instead")]] = Order;
}
#endif//SON8_MATFOURD_INCLUDE_DEPRECATED

#endif//SON8_MATFOURD_LAYOUT_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
