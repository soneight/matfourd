#ifndef SON8_MATFOURD_PRINT_HXX
#define SON8_MATFOURD_PRINT_HXX

#include "core.hxx"
#include "vec.hxx"

#include <iostream>

namespace son8::matfourd {
    // Vec (column vector) print function
    template< typename Type, unsigned Size, bool Layt >
    SON8_MATFOURD_FUNC operator<<( std::ostream &os, Vec< Type, Size, Layt > const &vec ) -> std::ostream & {
        if constexpr ( Layt ) os << "~";
        os << "Vec" << Size << "([" << vec.x( ) << ", " << vec.y( );
        if constexpr ( Size > 2 ) { os << ", " << vec.z( ); }
        if constexpr ( Size > 3 ) { os << ", " << vec.w( ); }
        os << "])";
        return os;
    }
}

#endif//SON8_MATFOURD_PRINT_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
