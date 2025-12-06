#ifndef SON8_MATFOURD_VEC_EQUALITY_HXX
#define SON8_MATFOURD_VEC_EQUALITY_HXX

#include <son8/matfourd/vec/type.hxx>

namespace son8::matfourd {
    // Vec (column vector) equality: (any)v == (any)v = bool
    template< typename Type, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator==( Vec< Type, Size, LaytL > const &vecL, Vec< Type, Size, LaytR > const &vecR )
    -> bool {
        bool ret = vecL.x( ) == vecR.x( ) and vecL.y( ) == vecR.y( );
        if ( !ret ) return ret;
        if constexpr ( Size > 2 ) { ret = ret and vecL.z( ) == vecR.z( ); }
        if ( !ret ) return ret;
        if constexpr ( Size > 3 ) { ret = ret and vecL.w( ) == vecR.w( ); }
        return ret;
    }
    // Vec (column vector) inequality: (any)v != (any)v = bool
    template< typename Type, unsigned Size, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator!=( Vec< Type, Size, LaytL > const &vecL, Vec< Type, Size, LaytR > const &vecR )
    -> bool {
        return not (vecL == vecR);
    }
} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_EQUALITY_HXX
