#ifndef SON8_MATFOURD_MAT_EQUALITY_HXX
#define SON8_MATFOURD_MAT_EQUALITY_HXX

#include <son8/matfourd/layout.hxx>
#include <son8/matfourd/mat/type.hxx>
#include <son8/matfourd/vec/equality.hxx>

namespace son8::matfourd {
    // Mat (column matrix) layout-aware equality: (any)Mat == (any)Mat = bool
    template< typename Type, unsigned Cols, unsigned Rows, bool Layt >
    SON8_MATFOURD_FUNC operator==( Mat< Type, Cols, Rows, Layt > const &matL, Mat< Type, Cols, Rows, Layt > const &matR )
    -> bool {
        using CompType = Mat< Type, Cols, Rows, Layt >;
        using r = bool;
        if constexpr ( CompType::vecs( ) == 2 ) {
            return r { matL.v1( ) == matR.v1( )
                    && matL.v2( ) == matR.v2( ) };
        } else if constexpr ( CompType::vecs( ) == 3 ) {
            return r { matL.v1( ) == matR.v1( )
                    && matL.v2( ) == matR.v2( )
                    && matL.v3( ) == matR.v3( ) };
        } else if constexpr ( CompType::vecs( ) == 4 ) {
            return r { matL.v1( ) == matR.v1( )
                    && matL.v2( ) == matR.v2( )
                    && matL.v3( ) == matR.v3( )
                    && matL.v4( ) == matR.v4( ) };
        }
    }
    // Mat (column matrix) generic equality: (any)Mat == (any)Mat = bool
    template< typename Type, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator==( Mat< Type, Cols, Rows, LaytL > const &matL, Mat< Type, Cols, Rows, LaytR > const &matR )
    -> bool {
        Mat< Type, Cols, Rows, Layout::ColMajor > const matColL{ matL };
        Mat< Type, Cols, Rows, Layout::ColMajor > const matColR{ matR };
        return matColL == matColR;
    }
    // Mat (column matrix) generic inequality: (any)Mat != (any)Mat = bool
    template< typename Type, unsigned Cols, unsigned Rows, bool LaytL, bool LaytR >
    SON8_MATFOURD_FUNC operator!=( Mat< Type, Cols, Rows, LaytL > const &matL, Mat< Type, Cols, Rows, LaytR > const &matR )
    -> bool {
        return not ( matL == matR );
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_EQUALITY_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
