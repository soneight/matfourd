#ifndef SON8_MATFOURD_VEC_SWIZZLES_HXX
#define SON8_MATFOURD_VEC_SWIZZLES_HXX
// son8
#include <son8/matfourd/core.hxx>
#include <son8/matfourd/vec/type.hxx>
// just less typing
#define SON8_MATFOURD_SWIZZLES_COORDS swizzles::Coord Crd1, swizzles::Coord Crd2, swizzles::Coord Crd3, swizzles::Coord Crd4
// each entry should use only one letter
#define SON8_MATFOURD_SWIZZLES_VARS_1( a, ReqS ) \
inline constexpr Impl_< 2, ReqS, Coord::a, Coord::a > a##a;\
inline constexpr Impl_< 3, ReqS, Coord::a, Coord::a, Coord::a > a##a##a;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::a, Coord::a, Coord::a > a##a##a##a
// each entry should use all two letters
#define SON8_MATFOURD_SWIZZLES_VARS_2( a, b, ReqS ) \
inline constexpr Impl_< 2, ReqS, Coord::a, Coord::b > a##b;\
\
inline constexpr Impl_< 2, ReqS, Coord::b, Coord::a > b##a;\
\
inline constexpr Impl_< 3, ReqS, Coord::a, Coord::a, Coord::b > a##a##b;\
inline constexpr Impl_< 3, ReqS, Coord::a, Coord::b, Coord::a > a##b##a;\
inline constexpr Impl_< 3, ReqS, Coord::a, Coord::b, Coord::b > a##b##b;\
\
inline constexpr Impl_< 3, ReqS, Coord::b, Coord::a, Coord::a > b##a##a;\
inline constexpr Impl_< 3, ReqS, Coord::b, Coord::a, Coord::b > b##a##b;\
inline constexpr Impl_< 3, ReqS, Coord::b, Coord::b, Coord::a > b##b##a;\
\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::a, Coord::a, Coord::b > a##a##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::a, Coord::b, Coord::a > a##a##b##a;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::a, Coord::b, Coord::b > a##a##b##b;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::a, Coord::a > a##b##a##a;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::a, Coord::b > a##b##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::b, Coord::a > a##b##b##a;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::b, Coord::b > a##b##b##b;\
\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::a, Coord::a > b##a##a##a;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::a, Coord::b > b##a##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::b, Coord::a > b##a##b##a;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::b, Coord::b > b##a##b##b;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::b, Coord::a, Coord::a > b##b##a##a;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::b, Coord::a, Coord::b > b##b##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::b, Coord::b, Coord::a > b##b##b##a
// each entry should use all three letters
#define SON8_MATFOURD_SWIZZLES_VARS_3( a, b, c, ReqS )\
inline constexpr Impl_< 3, ReqS, Coord::a, Coord::b, Coord::c > a##b##c;\
inline constexpr Impl_< 3, ReqS, Coord::a, Coord::c, Coord::b > a##c##b;\
inline constexpr Impl_< 3, ReqS, Coord::b, Coord::a, Coord::c > b##a##c;\
inline constexpr Impl_< 3, ReqS, Coord::b, Coord::c, Coord::a > b##c##a;\
inline constexpr Impl_< 3, ReqS, Coord::c, Coord::a, Coord::b > c##a##b;\
inline constexpr Impl_< 3, ReqS, Coord::c, Coord::b, Coord::a > c##b##a;\
\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::a, Coord::b, Coord::c > a##a##b##c;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::a, Coord::c, Coord::b > a##a##c##b;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::a, Coord::c > a##b##a##c;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::b, Coord::c > a##b##b##c;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::c, Coord::a > a##b##c##a;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::c, Coord::b > a##b##c##b;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::c, Coord::c > a##b##c##c;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::c, Coord::a, Coord::b > a##c##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::c, Coord::b, Coord::a > a##c##b##a;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::c, Coord::b, Coord::b > a##c##b##b;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::c, Coord::b, Coord::c > a##c##b##c;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::c, Coord::c, Coord::b > a##c##c##b;\
\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::a, Coord::c > b##a##a##c;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::b, Coord::c > b##a##b##c;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::c, Coord::a > b##a##c##a;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::c, Coord::b > b##a##c##b;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::c, Coord::c > b##a##c##c;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::b, Coord::a, Coord::c > b##b##a##c;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::b, Coord::c, Coord::a > b##b##c##a;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::c, Coord::a, Coord::a > b##c##a##a;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::c, Coord::a, Coord::b > b##c##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::c, Coord::a, Coord::c > b##c##a##c;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::c, Coord::b, Coord::a > b##c##b##a;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::c, Coord::c, Coord::a > b##c##c##a;\
\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::a, Coord::a, Coord::b > c##a##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::a, Coord::b, Coord::b > c##a##b##b;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::a, Coord::b, Coord::c > c##a##b##c;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::a, Coord::b, Coord::a > c##a##b##a;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::a, Coord::c, Coord::b > c##a##c##b;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::b, Coord::a, Coord::a > c##b##a##a;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::b, Coord::a, Coord::b > c##b##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::b, Coord::b, Coord::a > c##b##b##a;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::b, Coord::a, Coord::c > c##b##a##c;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::b, Coord::c, Coord::a > c##b##c##a;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::c, Coord::a, Coord::b > c##c##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::c, Coord::b, Coord::a > c##c##b##a
// each entry should use all four letters
#define SON8_MATFOURD_SWIZZLES_VARS_4( a, b, c, d, ReqS )\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::c, Coord::d > a##b##c##d;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::b, Coord::d, Coord::c > a##b##d##c;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::c, Coord::b, Coord::d > a##c##b##d;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::c, Coord::d, Coord::b > a##c##d##b;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::d, Coord::b, Coord::c > a##d##b##c;\
inline constexpr Impl_< 4, ReqS, Coord::a, Coord::d, Coord::c, Coord::b > a##d##c##b;\
\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::c, Coord::d > b##a##c##d;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::a, Coord::d, Coord::c > b##a##d##c;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::c, Coord::a, Coord::d > b##c##a##d;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::c, Coord::d, Coord::a > b##c##d##a;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::d, Coord::a, Coord::c > b##d##a##c;\
inline constexpr Impl_< 4, ReqS, Coord::b, Coord::d, Coord::c, Coord::a > b##d##c##a;\
\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::a, Coord::b, Coord::d > c##a##b##d;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::a, Coord::d, Coord::b > c##a##d##b;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::b, Coord::a, Coord::d > c##b##a##d;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::b, Coord::d, Coord::a > c##b##d##a;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::d, Coord::a, Coord::b > c##d##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::c, Coord::d, Coord::b, Coord::a > c##d##b##a;\
\
inline constexpr Impl_< 4, ReqS, Coord::d, Coord::a, Coord::b, Coord::c > d##a##b##c;\
inline constexpr Impl_< 4, ReqS, Coord::d, Coord::a, Coord::c, Coord::b > d##a##c##b;\
inline constexpr Impl_< 4, ReqS, Coord::d, Coord::b, Coord::a, Coord::c > d##b##a##c;\
inline constexpr Impl_< 4, ReqS, Coord::d, Coord::b, Coord::c, Coord::a > d##b##c##a;\
inline constexpr Impl_< 4, ReqS, Coord::d, Coord::c, Coord::a, Coord::b > d##c##a##b;\
inline constexpr Impl_< 4, ReqS, Coord::d, Coord::c, Coord::b, Coord::a > d##c##b##a
// TODO maybe find a better way to do this instead of using macro
#define SON8_MATFOURD_SWIZZLES_FUNC_BODY( ReqS )\
using Ret = Vec< Type, Size, Layt >;\
using Swiz = swizzles::Impl_< Size, ReqS, Crd1, Crd2, Crd3, Crd4 >;\
if/*_*/ constexpr ( Size == 2 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ) };\
else if constexpr ( Size == 3 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ) };\
else if constexpr ( Size == 4 ) return Ret{ Swiz::c1( vec ), Swiz::c2( vec ), Swiz::c3( vec ), Swiz::c4( vec ) }

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
                if/*_*/ constexpr ( Crd == Coord::x ) return vec.x( );
                else if constexpr ( Crd == Coord::y ) return vec.y( );
                else if constexpr ( Crd == Coord::z ) return vec.z( );
                else if constexpr ( Crd == Coord::w ) return vec.w( );
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
        // variables (is alias types needed?)
        SON8_MATFOURD_SWIZZLES_VARS_1( x, 2 );
        SON8_MATFOURD_SWIZZLES_VARS_1( y, 2 );
        SON8_MATFOURD_SWIZZLES_VARS_1( z, 3 );
        SON8_MATFOURD_SWIZZLES_VARS_1( w, 4 );
        SON8_MATFOURD_SWIZZLES_VARS_2( x, y, 2 );
        SON8_MATFOURD_SWIZZLES_VARS_2( x, z, 3 );
        SON8_MATFOURD_SWIZZLES_VARS_2( x, w, 4 );
        SON8_MATFOURD_SWIZZLES_VARS_2( y, z, 3 );
        SON8_MATFOURD_SWIZZLES_VARS_2( y, w, 4 );
        SON8_MATFOURD_SWIZZLES_VARS_2( z, w, 4 );
        SON8_MATFOURD_SWIZZLES_VARS_3( x, y, z, 3 );
        SON8_MATFOURD_SWIZZLES_VARS_3( x, y, w, 4 );
        SON8_MATFOURD_SWIZZLES_VARS_3( x, z, w, 4 );
        SON8_MATFOURD_SWIZZLES_VARS_3( y, z, w, 4 );
        SON8_MATFOURD_SWIZZLES_VARS_4( x, y, z, w, 4 );

    } // namespace swizzles
    // TODO too much repeat, maybe find a better implementation of restricting swizzle requirements
    //      IMORTANT not forget about static header with asserts)
    //      all this done to allow catching wrong swizzles with Vec combo when including static.hxx
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 2, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        SON8_MATFOURD_SWIZZLES_FUNC_BODY( 2 );
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 3, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        SON8_MATFOURD_SWIZZLES_FUNC_BODY( 2 );
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 3, Layt > const &vec, swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 > ) {
        SON8_MATFOURD_SWIZZLES_FUNC_BODY( 3 );
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 2, Crd1, Crd2, Crd3, Crd4 > ) {
        SON8_MATFOURD_SWIZZLES_FUNC_BODY( 2 );
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 3, Crd1, Crd2, Crd3, Crd4 > ) {
        SON8_MATFOURD_SWIZZLES_FUNC_BODY( 3 );
    }
    template< typename Type, bool Layt, unsigned Size, SON8_MATFOURD_SWIZZLES_COORDS >
    SON8_MATFOURD_FUNC operator/( Vec< Type, 4, Layt > const &vec, swizzles::Impl_< Size, 4, Crd1, Crd2, Crd3, Crd4 > ) {
        SON8_MATFOURD_SWIZZLES_FUNC_BODY( 4 );
    }

} // namespace son8::matfourd

#endif//SON8_MATFOURD_VEC_SWIZZLES_HXX

// Ⓒ 2025 Oleg'Ease'Kharchuk ᦒ
