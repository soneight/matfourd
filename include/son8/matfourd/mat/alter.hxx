#ifndef SON8_MATFOURD_MAT_ALTER_HXX
#define SON8_MATFOURD_MAT_ALTER_HXX

#include <son8/matfourd/mat/type.hxx>

namespace son8::matfourd {
    // Mat (column matrix) transpose
    template< typename Type, unsigned Cols, unsigned Rows, bool Layt >
    SON8_MATFOURD_FUNC transpose( Mat< Type, Cols, Rows, Layt > const &mat )
    -> Mat< Type, Rows, Cols, Layt > {
        using rswp = Mat< Type, Rows, Cols, not Layt >; // IMPORTANT (not Layt) in necessary here!
        // ~ preserve original layout
        if/*___*/ constexpr ( rswp::vecs( ) == 2 ) {
            return ~rswp{ mat.v1( )
                        , mat.v2( ) };
        } else if constexpr ( rswp::vecs( ) == 3 ) {
            return ~rswp{ mat.v1( )
                        , mat.v2( )
                        , mat.v3( ) };
        } else if constexpr ( rswp::vecs( ) == 4 ) {
            return ~rswp{ mat.v1( )
                        , mat.v2( )
                        , mat.v3( )
                        , mat.v4( ) };
        }
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_ALTER_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
