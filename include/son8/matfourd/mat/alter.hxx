#ifndef SON8_MATFOURD_MAT_ALTER_HXX
#define SON8_MATFOURD_MAT_ALTER_HXX

#include <son8/matfourd/mat/type.hxx>

namespace son8::matfourd {
    // Mat (column matrix) transpose
    template< typename Type, unsigned Cols, unsigned Rows, bool Layt >
    SON8_MATFOURD_FUNC transpose( Mat< Type, Cols, Rows, Layt > const &mat )
    -> Mat< Type, Rows, Cols, Layt > {
        using Ret = Mat< Type, Rows, Cols, not Layt >; // IMPORTANT (not Layt) in necessary here!
        Ret ret;
        ret.v1( ) = mat.v1( );
        ret.v2( ) = mat.v2( );
        if constexpr ( Ret::vecs( ) > 2 ) ret.v3( ) = mat.v3( );
        if constexpr ( Ret::vecs( ) > 3 ) ret.v4( ) = mat.v4( );
        return ~ret; // preserve original layout
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_ALTER_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
