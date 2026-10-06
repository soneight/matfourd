#include <son8/matfourd.hxx>
// dummy source to trigger cmake generation of compile commands json workaround
namespace son8::dummy_face {
    namespace m4d = matfourd;
    using Col4x4f = m4d::Col4x4< float >;
    using Ref = Col4x4f const &;

    static Col4x4f mvp( Ref m, Ref v, Ref p ) {
        return m * v * p;
    }

}
