#ifndef SON8_MATFOURD_MAT_ADDITIVE_HXX
#define SON8_MATFOURD_MAT_ADDITIVE_HXX

#include <son8/matfourd/mat/type.hxx>
#include <son8/matfourd/vec/additive.hxx>

namespace son8::matfourd {
    // Mat (column matrix) order-aware addition: (same)Mat + (same)Mat = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool RowMajor >
    SON8_MATFOURD_FUNC operator+( Mat< Type, Cols, Rows, RowMajor > const &matL, Mat< Type, Cols, Rows, RowMajor > const &matR ) {
        using r = Mat< Type, Cols, Rows, RowMajor >;
        if/*___*/ constexpr ( r::vecs( ) == 2 ) {
            return r{ matL.v1( ) + matR.v1( )
                    , matL.v2( ) + matR.v2( ) };
        } else if constexpr ( r::vecs( ) == 3 ) {
            return r{ matL.v1( ) + matR.v1( )
                    , matL.v2( ) + matR.v2( )
                    , matL.v3( ) + matR.v3( ) };
        } else if constexpr ( r::vecs( ) == 4 ) {
            return r{ matL.v1( ) + matR.v1( )
                    , matL.v2( ) + matR.v2( )
                    , matL.v3( ) + matR.v3( )
                    , matL.v4( ) + matR.v4( ) };
        }
    }
    // Mat (column matrix) generic addition: (any)Mat + (any)Mat = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool RowMajorL, bool RowMajorR >
    SON8_MATFOURD_FUNC operator+( Mat< Type, Cols, Rows, RowMajorL > const &matL, Mat< Type, Cols, Rows, RowMajorR > const &matR ) {
        using Ret = Mat< Type, Cols, Rows >;
        Ret ret;
        Mat< Type, Cols, Rows, Order::ColMajor > const matColL{ matL };
        Mat< Type, Cols, Rows, Order::ColMajor > const matColR{ matR };
        return matColL + matColR;
    }
    // Mat (column matrix) generic subtraction: (any)Mat - (any)Mat = Mat
    template< typename Type, unsigned Cols, unsigned Rows, bool RowMajorL, bool RowMajorR >
    SON8_MATFOURD_FUNC operator-( Mat< Type, Cols, Rows, RowMajorL > const &matL, Mat< Type, Cols, Rows, RowMajorR > const &matR )
    -> Mat< Type, Cols, Rows > {
        return matL + ( -matR );
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_MAT_ADDITIVE_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
