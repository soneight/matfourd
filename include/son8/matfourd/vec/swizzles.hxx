#ifndef SON8_MATFOURD_VEC_SWIZZLES_HXX
#define SON8_MATFOURD_VEC_SWIZZLES_HXX
// son8
#include <son8/matfourd/core.hxx>
#include <son8/matfourd/vec/type.hxx>
// just less typing
#define SON8_MATFOURD_SWIZZLES_COORDS swizzles::Coord Crd1, swizzles::Coord Crd2, swizzles::Coord Crd3, swizzles::Coord Crd4
// each entry should use only one letter
#define SON8_MATFOURD_SWIZZLES_VARS_1( a, ReqS ) \
using a##a##_ = Impl_< 2, ReqS, Coord::a, Coord::a >; inline constexpr a##a##_ a##a;\
using a##a##a##_ = Impl_< 3, ReqS, Coord::a, Coord::a, Coord::a >; inline constexpr a##a##a##_ a##a##a;\
using a##a##a##a##_ = Impl_< 4, ReqS, Coord::a, Coord::a, Coord::a, Coord::a >; inline constexpr a##a##a##a##_ a##a##a##a;
// each entry should use all two letters
#define SON8_MATFOURD_SWIZZLES_VARS_2( a, b, ReqS ) \
using a##b##_ = Impl_< 2, ReqS, Coord::a, Coord::b >; inline constexpr a##b##_ a##b;\
\
using b##a##_ = Impl_< 2, ReqS, Coord::b, Coord::a >; inline constexpr b##a##_ b##a;\
\
using a##a##b##_ = Impl_< 3, ReqS, Coord::a, Coord::a, Coord::b >; inline constexpr a##a##b##_ a##a##b;\
using a##b##a##_ = Impl_< 3, ReqS, Coord::a, Coord::b, Coord::a >; inline constexpr a##b##a##_ a##b##a;\
using a##b##b##_ = Impl_< 3, ReqS, Coord::a, Coord::b, Coord::b >; inline constexpr a##b##b##_ a##b##b;\
\
using b##a##a##_ = Impl_< 3, ReqS, Coord::b, Coord::a, Coord::a >; inline constexpr b##a##a##_ b##a##a;\
using b##a##b##_ = Impl_< 3, ReqS, Coord::b, Coord::a, Coord::b >; inline constexpr b##a##b##_ b##a##b;\
using b##b##a##_ = Impl_< 3, ReqS, Coord::b, Coord::b, Coord::a >; inline constexpr b##b##a##_ b##b##a;\
\
using a##a##a##b##_ = Impl_< 4, ReqS, Coord::a, Coord::a, Coord::a, Coord::b >; inline constexpr a##a##a##b##_ a##a##a##b;\
using a##a##b##a##_ = Impl_< 4, ReqS, Coord::a, Coord::a, Coord::b, Coord::a >; inline constexpr a##a##b##a##_ a##a##b##a;\
using a##a##b##b##_ = Impl_< 4, ReqS, Coord::a, Coord::a, Coord::b, Coord::b >; inline constexpr a##a##b##b##_ a##a##b##b;\
using a##b##a##a##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::a, Coord::a >; inline constexpr a##b##a##a##_ a##b##a##a;\
using a##b##a##b##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::a, Coord::b >; inline constexpr a##b##a##b##_ a##b##a##b;\
using a##b##b##a##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::b, Coord::a >; inline constexpr a##b##b##a##_ a##b##b##a;\
using a##b##b##b##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::b, Coord::b >; inline constexpr a##b##b##b##_ a##b##b##b;\
\
using b##a##a##a##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::a, Coord::a >; inline constexpr b##a##a##a##_ b##a##a##a;\
using b##a##a##b##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::a, Coord::b >; inline constexpr b##a##a##b##_ b##a##a##b;\
using b##a##b##a##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::b, Coord::a >; inline constexpr b##a##b##a##_ b##a##b##a;\
using b##a##b##b##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::b, Coord::b >; inline constexpr b##a##b##b##_ b##a##b##b;\
using b##b##a##a##_ = Impl_< 4, ReqS, Coord::b, Coord::b, Coord::a, Coord::a >; inline constexpr b##b##a##a##_ b##b##a##a;\
using b##b##a##b##_ = Impl_< 4, ReqS, Coord::b, Coord::b, Coord::a, Coord::b >; inline constexpr b##b##a##b##_ b##b##a##b;\
using b##b##b##a##_ = Impl_< 4, ReqS, Coord::b, Coord::b, Coord::b, Coord::a >; inline constexpr b##b##b##a##_ b##b##b##a;
// each entry should use all three letters
#define SON8_MATFOURD_SWIZZLES_VARS_3( a, b, c, ReqS )\
using a##b##c##_ = Impl_< 3, ReqS, Coord::a, Coord::b, Coord::c >; inline constexpr a##b##c##_ a##b##c;\
using a##c##b##_ = Impl_< 3, ReqS, Coord::a, Coord::c, Coord::b >; inline constexpr a##c##b##_ a##c##b;\
using b##a##c##_ = Impl_< 3, ReqS, Coord::b, Coord::a, Coord::c >; inline constexpr b##a##c##_ b##a##c;\
using b##c##a##_ = Impl_< 3, ReqS, Coord::b, Coord::c, Coord::a >; inline constexpr b##c##a##_ b##c##a;\
using c##a##b##_ = Impl_< 3, ReqS, Coord::c, Coord::a, Coord::b >; inline constexpr c##a##b##_ c##a##b;\
using c##b##a##_ = Impl_< 3, ReqS, Coord::c, Coord::b, Coord::a >; inline constexpr c##b##a##_ c##b##a;\
\
using a##a##b##c##_ = Impl_< 4, ReqS, Coord::a, Coord::a, Coord::b, Coord::c >; inline constexpr a##a##b##c##_ a##a##b##c;\
using a##a##c##b##_ = Impl_< 4, ReqS, Coord::a, Coord::a, Coord::c, Coord::b >; inline constexpr a##a##c##b##_ a##a##c##b;\
using a##b##a##c##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::a, Coord::c >; inline constexpr a##b##a##c##_ a##b##a##c;\
using a##b##b##c##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::b, Coord::c >; inline constexpr a##b##b##c##_ a##b##b##c;\
using a##b##c##a##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::c, Coord::a >; inline constexpr a##b##c##a##_ a##b##c##a;\
using a##b##c##b##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::c, Coord::b >; inline constexpr a##b##c##b##_ a##b##c##b;\
using a##b##c##c##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::c, Coord::c >; inline constexpr a##b##c##c##_ a##b##c##c;\
using a##c##a##b##_ = Impl_< 4, ReqS, Coord::a, Coord::c, Coord::a, Coord::b >; inline constexpr a##c##a##b##_ a##c##a##b;\
using a##c##b##a##_ = Impl_< 4, ReqS, Coord::a, Coord::c, Coord::b, Coord::a >; inline constexpr a##c##b##a##_ a##c##b##a;\
using a##c##b##b##_ = Impl_< 4, ReqS, Coord::a, Coord::c, Coord::b, Coord::b >; inline constexpr a##c##b##b##_ a##c##b##b;\
using a##c##b##c##_ = Impl_< 4, ReqS, Coord::a, Coord::c, Coord::b, Coord::c >; inline constexpr a##c##b##c##_ a##c##b##c;\
using a##c##c##b##_ = Impl_< 4, ReqS, Coord::a, Coord::c, Coord::c, Coord::b >; inline constexpr a##c##c##b##_ a##c##c##b;\
\
using b##a##a##c##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::a, Coord::c >; inline constexpr b##a##a##c##_ b##a##a##c;\
using b##a##b##c##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::b, Coord::c >; inline constexpr b##a##b##c##_ b##a##b##c;\
using b##a##c##a##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::c, Coord::a >; inline constexpr b##a##c##a##_ b##a##c##a;\
using b##a##c##b##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::c, Coord::b >; inline constexpr b##a##c##b##_ b##a##c##b;\
using b##a##c##c##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::c, Coord::c >; inline constexpr b##a##c##c##_ b##a##c##c;\
using b##b##a##c##_ = Impl_< 4, ReqS, Coord::b, Coord::b, Coord::a, Coord::c >; inline constexpr b##b##a##c##_ b##b##a##c;\
using b##b##c##a##_ = Impl_< 4, ReqS, Coord::b, Coord::b, Coord::c, Coord::a >; inline constexpr b##b##c##a##_ b##b##c##a;\
using b##c##a##a##_ = Impl_< 4, ReqS, Coord::b, Coord::c, Coord::a, Coord::a >; inline constexpr b##c##a##a##_ b##c##a##a;\
using b##c##a##b##_ = Impl_< 4, ReqS, Coord::b, Coord::c, Coord::a, Coord::b >; inline constexpr b##c##a##b##_ b##c##a##b;\
using b##c##a##c##_ = Impl_< 4, ReqS, Coord::b, Coord::c, Coord::a, Coord::c >; inline constexpr b##c##a##c##_ b##c##a##c;\
using b##c##b##a##_ = Impl_< 4, ReqS, Coord::b, Coord::c, Coord::b, Coord::a >; inline constexpr b##c##b##a##_ b##c##b##a;\
using b##c##c##a##_ = Impl_< 4, ReqS, Coord::b, Coord::c, Coord::c, Coord::a >; inline constexpr b##c##c##a##_ b##c##c##a;\
\
using c##a##a##b##_ = Impl_< 4, ReqS, Coord::c, Coord::a, Coord::a, Coord::b >; inline constexpr c##a##a##b##_ c##a##a##b;\
using c##a##b##b##_ = Impl_< 4, ReqS, Coord::c, Coord::a, Coord::b, Coord::b >; inline constexpr c##a##b##b##_ c##a##b##b;\
using c##a##b##c##_ = Impl_< 4, ReqS, Coord::c, Coord::a, Coord::b, Coord::c >; inline constexpr c##a##b##c##_ c##a##b##c;\
using c##a##b##a##_ = Impl_< 4, ReqS, Coord::c, Coord::a, Coord::b, Coord::a >; inline constexpr c##a##b##a##_ c##a##b##a;\
using c##a##c##b##_ = Impl_< 4, ReqS, Coord::c, Coord::a, Coord::c, Coord::b >; inline constexpr c##a##c##b##_ c##a##c##b;\
using c##b##a##a##_ = Impl_< 4, ReqS, Coord::c, Coord::b, Coord::a, Coord::a >; inline constexpr c##b##a##a##_ c##b##a##a;\
using c##b##a##b##_ = Impl_< 4, ReqS, Coord::c, Coord::b, Coord::a, Coord::b >; inline constexpr c##b##a##b##_ c##b##a##b;\
using c##b##b##a##_ = Impl_< 4, ReqS, Coord::c, Coord::b, Coord::b, Coord::a >; inline constexpr c##b##b##a##_ c##b##b##a;\
using c##b##a##c##_ = Impl_< 4, ReqS, Coord::c, Coord::b, Coord::a, Coord::c >; inline constexpr c##b##a##c##_ c##b##a##c;\
using c##b##c##a##_ = Impl_< 4, ReqS, Coord::c, Coord::b, Coord::c, Coord::a >; inline constexpr c##b##c##a##_ c##b##c##a;\
using c##c##a##b##_ = Impl_< 4, ReqS, Coord::c, Coord::c, Coord::a, Coord::b >; inline constexpr c##c##a##b##_ c##c##a##b;\
using c##c##b##a##_ = Impl_< 4, ReqS, Coord::c, Coord::c, Coord::b, Coord::a >; inline constexpr c##c##b##a##_ c##c##b##a;
// each entry should use all four letters
#define SON8_MATFOURD_SWIZZLES_VARS_4( a, b, c, d, ReqS )\
using a##b##c##d##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::c, Coord::d >; inline constexpr a##b##c##d##_ a##b##c##d;\
using a##b##d##c##_ = Impl_< 4, ReqS, Coord::a, Coord::b, Coord::d, Coord::c >; inline constexpr a##b##d##c##_ a##b##d##c;\
using a##c##b##d##_ = Impl_< 4, ReqS, Coord::a, Coord::c, Coord::b, Coord::d >; inline constexpr a##c##b##d##_ a##c##b##d;\
using a##c##d##b##_ = Impl_< 4, ReqS, Coord::a, Coord::c, Coord::d, Coord::b >; inline constexpr a##c##d##b##_ a##c##d##b;\
using a##d##b##c##_ = Impl_< 4, ReqS, Coord::a, Coord::d, Coord::b, Coord::c >; inline constexpr a##d##b##c##_ a##d##b##c;\
using a##d##c##b##_ = Impl_< 4, ReqS, Coord::a, Coord::d, Coord::c, Coord::b >; inline constexpr a##d##c##b##_ a##d##c##b;\
\
using b##a##c##d##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::c, Coord::d >; inline constexpr b##a##c##d##_ b##a##c##d;\
using b##a##d##c##_ = Impl_< 4, ReqS, Coord::b, Coord::a, Coord::d, Coord::c >; inline constexpr b##a##d##c##_ b##a##d##c;\
using b##c##a##d##_ = Impl_< 4, ReqS, Coord::b, Coord::c, Coord::a, Coord::d >; inline constexpr b##c##a##d##_ b##c##a##d;\
using b##c##d##a##_ = Impl_< 4, ReqS, Coord::b, Coord::c, Coord::d, Coord::a >; inline constexpr b##c##d##a##_ b##c##d##a;\
using b##d##a##c##_ = Impl_< 4, ReqS, Coord::b, Coord::d, Coord::a, Coord::c >; inline constexpr b##d##a##c##_ b##d##a##c;\
using b##d##c##a##_ = Impl_< 4, ReqS, Coord::b, Coord::d, Coord::c, Coord::a >; inline constexpr b##d##c##a##_ b##d##c##a;\
\
using c##a##b##d##_ = Impl_< 4, ReqS, Coord::c, Coord::a, Coord::b, Coord::d >; inline constexpr c##a##b##d##_ c##a##b##d;\
using c##a##d##b##_ = Impl_< 4, ReqS, Coord::c, Coord::a, Coord::d, Coord::b >; inline constexpr c##a##d##b##_ c##a##d##b;\
using c##b##a##d##_ = Impl_< 4, ReqS, Coord::c, Coord::b, Coord::a, Coord::d >; inline constexpr c##b##a##d##_ c##b##a##d;\
using c##b##d##a##_ = Impl_< 4, ReqS, Coord::c, Coord::b, Coord::d, Coord::a >; inline constexpr c##b##d##a##_ c##b##d##a;\
using c##d##a##b##_ = Impl_< 4, ReqS, Coord::c, Coord::d, Coord::a, Coord::b >; inline constexpr c##d##a##b##_ c##d##a##b;\
using c##d##b##a##_ = Impl_< 4, ReqS, Coord::c, Coord::d, Coord::b, Coord::a >; inline constexpr c##d##b##a##_ c##d##b##a;\
\
using d##a##b##c##_ = Impl_< 4, ReqS, Coord::d, Coord::a, Coord::b, Coord::c >; inline constexpr d##a##b##c##_ d##a##b##c;\
using d##a##c##b##_ = Impl_< 4, ReqS, Coord::d, Coord::a, Coord::c, Coord::b >; inline constexpr d##a##c##b##_ d##a##c##b;\
using d##b##a##c##_ = Impl_< 4, ReqS, Coord::d, Coord::b, Coord::a, Coord::c >; inline constexpr d##b##a##c##_ d##b##a##c;\
using d##b##c##a##_ = Impl_< 4, ReqS, Coord::d, Coord::b, Coord::c, Coord::a >; inline constexpr d##b##c##a##_ d##b##c##a;\
using d##c##a##b##_ = Impl_< 4, ReqS, Coord::d, Coord::c, Coord::a, Coord::b >; inline constexpr d##c##a##b##_ d##c##a##b;\
using d##c##b##a##_ = Impl_< 4, ReqS, Coord::d, Coord::c, Coord::b, Coord::a >; inline constexpr d##c##b##a##_ d##c##b##a;

namespace son8::matfourd {
    // opengl-like Vec swizzles
    namespace swizzles {
        // enum helper
        enum class Coord : unsigned { o, x, y, z, w };
        // implementation
        template< unsigned Size, unsigned ReqS, Coord Crd1, Coord Crd2, Coord Crd3 = Coord::o, Coord Crd4 = Coord::o >
        class Impl_ {
            static_assert( 2 <= Size && Size <= 4
                , "son8::matfourd: swizzle implementaion requires size to be in range [2,4]" );
            static_assert( Crd1 != Coord::o && Crd2 != Coord::o
                , "son8::matfourd: swizzle implementaion requires first two coords to be non-zero" );
            template< Coord Crd, typename Type >
            SON8_MATFOURD_FUNC
            static constexpr coord( Type const &vec ) {
                static_assert( Crd != Coord::o, "son8::matfourd: swizzle with incorrect o Coord" );
                if constexpr ( Crd == Coord::x ) return vec.x( );
                if constexpr ( Crd == Coord::y ) return vec.y( );
                if constexpr ( Crd == Coord::z ) return vec.z( );
                if constexpr ( Crd == Coord::w ) return vec.w( );
            }
        public:
            template< typename Type >
            SON8_MATFOURD_FUNC
            static constexpr c1( Type const &vec ) { return coord< Crd1 >( vec ); }
            template< typename Type >
            SON8_MATFOURD_FUNC
            static constexpr c2( Type const &vec ) { return coord< Crd2 >( vec ); }
            template< typename Type >
            SON8_MATFOURD_FUNC
            static constexpr c3( Type const &vec ) { return coord< Crd3 >( vec ); }
            template< typename Type >
            SON8_MATFOURD_FUNC
            static constexpr c4( Type const &vec ) { return coord< Crd4 >( vec ); }
        }; // class Impl_
        // alias variables
        SON8_MATFOURD_SWIZZLES_VARS_1( x, 2 )
        SON8_MATFOURD_SWIZZLES_VARS_1( y, 2 )
        SON8_MATFOURD_SWIZZLES_VARS_1( z, 3 )
        SON8_MATFOURD_SWIZZLES_VARS_1( w, 4 )
        SON8_MATFOURD_SWIZZLES_VARS_2( x, y, 2 )
        SON8_MATFOURD_SWIZZLES_VARS_2( x, z, 3 )
        SON8_MATFOURD_SWIZZLES_VARS_2( x, w, 4 )
        SON8_MATFOURD_SWIZZLES_VARS_2( y, z, 3 )
        SON8_MATFOURD_SWIZZLES_VARS_2( y, w, 4 )
        SON8_MATFOURD_SWIZZLES_VARS_2( z, w, 4 )
        SON8_MATFOURD_SWIZZLES_VARS_3( x, y, z, 3 )
        SON8_MATFOURD_SWIZZLES_VARS_3( x, y, w, 4 )
        SON8_MATFOURD_SWIZZLES_VARS_3( x, z, w, 4 )
        SON8_MATFOURD_SWIZZLES_VARS_3( y, z, w, 4 )
        SON8_MATFOURD_SWIZZLES_VARS_4( x, y, z, w, 4 )

    } // namespace swizzles
    // TODO too much repeat, maybe find a better implementation of restricting swizzle requirements
    //      IMORTANT not forget about static header with asserts)
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 2, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 3, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 3, Layt > const &vec, swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 4, Crd1, Crd2, Crd3, Crd4 > ) {
        using Ret = Vec< Type, Size, Layt >;
        using Swiz = swizzles::Impl_< Size, 4, Crd1, Crd2, Crd3, Crd4 >;
        if constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };
        if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };
        if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) };
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_SWIZZLES_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
