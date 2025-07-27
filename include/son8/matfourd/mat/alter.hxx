#ifndef SON8_MATFOURD_MAT_ALTER_HXX
#define SON8_MATFOURD_MAT_ALTER_HXX

#include <son8/matfourd/mat.hxx>

namespace son8::matfourd {
    // Mat (column matrix) transpose
    template< typename Type, unsigned Rows, unsigned Cols, bool Layt >
    SON8_MATFOURD_FUNC transpose( Mat< Type, Rows, Cols, Layt > const &mat )
    -> Mat< Type, Cols, Rows, Layt > {
        using Ret = Mat< Type, Cols, Rows, not Layt >;
        Ret ret;
        ret.v1( ) = mat.v1( );
        ret.v2( ) = mat.v2( );
        if constexpr ( Ret::vecs( ) > 2 ) ret.v3( ) = mat.v3( );
        if constexpr ( Ret::vecs( ) > 3 ) ret.v4( ) = mat.v4( );
        return ~ret; // preserve original layout
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_ALTER_HXX
