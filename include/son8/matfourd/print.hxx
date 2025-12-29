#ifndef SON8_MATFOURD_PRINT_HXX
#define SON8_MATFOURD_PRINT_HXX
// son8
#include <son8/matfourd/core.hxx>
#include <son8/matfourd/vec/type.hxx>
#include <son8/matfourd/mat/type.hxx>
// std
#include <ostream>

namespace son8::matfourd {
    // Vec (column vector) print function
    template< typename Type, unsigned Size, bool RowMajor >
    SON8_MATFOURD_DISC operator<<( std::ostream &os, Vec< Type, Size, RowMajor > const &vec ) -> std::ostream & {
        if constexpr ( RowMajor ) os << "~";
        os << "Vec" << Size << "[" << vec.x( ) << ", " << vec.y( );
        if constexpr ( Size > 2 ) { os << ", " << vec.z( ); }
        if constexpr ( Size > 3 ) { os << ", " << vec.w( ); }
        os << "]";
        return os;
    }
    // Mat (column matrix) print function
    template< typename Type, unsigned Cols, unsigned Rows, bool RowMajor >
    SON8_MATFOURD_DISC operator<<( std::ostream &os, Mat< Type, Cols, Rows, RowMajor > const &mat ) -> std::ostream & {
        using SelfType = Mat< Type, Cols, Rows, RowMajor >;
        os << "\n";
        if constexpr ( RowMajor ) os << "~";
        os << "Mat" << Cols << "x" << Rows << "{";
        os << "\n\t" << mat.v1( ) << ",\n\t" << mat.v2( );

        if constexpr ( SelfType::vecs( ) > 2 ) os << ",\n\t" << mat.v3( );
        if constexpr ( SelfType::vecs( ) > 3 ) os << ",\n\t" << mat.v4( );
        os << "\n}\n";
        return os;
    }
}

#endif//SON8_MATFOURD_PRINT_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
