/*------------------------------------------------------------------------------

   MiniLight C++ : minimal global illumination renderer
   Harrison Ainsworth / HXA7241 : 2006-2011, 2013

   http://www.hxa.name/minilight

------------------------------------------------------------------------------*/


#ifndef Camera_h
#define Camera_h


#include <iosfwd>

#include "Vector3f.hpp"




#include "hxa7241_minilight.hpp"
namespace hxa7241_minilight
{


/**
 * View definition and rasterizer.<br/><br/>
 *
 * getFrame() accumulates a frame of samples to the image.<br/><br/>
 *
 * Constant.
 *
 * @invariants
 * * viewAngle_m is >= VIEW_ANGLE_MIN and <= VIEW_ANGLE_MAX degrees in radians
 * * viewDirection_m is unitized
 * * right_m is unitized
 * * up_m is unitized
 * * above three form a coordinate frame
 */
class Camera
{
/// standard object services ---------------------------------------------------
public:
   explicit Camera( std::istream& );

// use defaults
//         ~Camera();
//          Camera( const Camera& );
// Camera& operator=( const Camera& );


/// commands -------------------------------------------------------------------


/// queries --------------------------------------------------------------------
           Vector3f getEyePoint()                                         const;

           void  getFrame( const Scene&,
                           const Random&,
                           Image& )                                       const;


/// constants ------------------------------------------------------------------
   static  real64 VIEW_ANGLE_MIN();
   static  real64 VIEW_ANGLE_MAX();


/// fields ---------------------------------------------------------------------
private:
   Vector3f viewPosition_m;
   real64   viewAngle_m;

   // view frame
   Vector3f viewDirection_m;
   Vector3f right_m;
   Vector3f up_m;
};


}//namespace




#endif//Camera_h
