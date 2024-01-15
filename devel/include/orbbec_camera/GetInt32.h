// Generated by gencpp from file orbbec_camera/GetInt32.msg
// DO NOT EDIT!


#ifndef ORBBEC_CAMERA_MESSAGE_GETINT32_H
#define ORBBEC_CAMERA_MESSAGE_GETINT32_H

#include <ros/service_traits.h>


#include <orbbec_camera/GetInt32Request.h>
#include <orbbec_camera/GetInt32Response.h>


namespace orbbec_camera
{

struct GetInt32
{

typedef GetInt32Request Request;
typedef GetInt32Response Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetInt32
} // namespace orbbec_camera


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::orbbec_camera::GetInt32 > {
  static const char* value()
  {
    return "1e06c77f31583d55c01571a573d75b9f";
  }

  static const char* value(const ::orbbec_camera::GetInt32&) { return value(); }
};

template<>
struct DataType< ::orbbec_camera::GetInt32 > {
  static const char* value()
  {
    return "orbbec_camera/GetInt32";
  }

  static const char* value(const ::orbbec_camera::GetInt32&) { return value(); }
};


// service_traits::MD5Sum< ::orbbec_camera::GetInt32Request> should match
// service_traits::MD5Sum< ::orbbec_camera::GetInt32 >
template<>
struct MD5Sum< ::orbbec_camera::GetInt32Request>
{
  static const char* value()
  {
    return MD5Sum< ::orbbec_camera::GetInt32 >::value();
  }
  static const char* value(const ::orbbec_camera::GetInt32Request&)
  {
    return value();
  }
};

// service_traits::DataType< ::orbbec_camera::GetInt32Request> should match
// service_traits::DataType< ::orbbec_camera::GetInt32 >
template<>
struct DataType< ::orbbec_camera::GetInt32Request>
{
  static const char* value()
  {
    return DataType< ::orbbec_camera::GetInt32 >::value();
  }
  static const char* value(const ::orbbec_camera::GetInt32Request&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::orbbec_camera::GetInt32Response> should match
// service_traits::MD5Sum< ::orbbec_camera::GetInt32 >
template<>
struct MD5Sum< ::orbbec_camera::GetInt32Response>
{
  static const char* value()
  {
    return MD5Sum< ::orbbec_camera::GetInt32 >::value();
  }
  static const char* value(const ::orbbec_camera::GetInt32Response&)
  {
    return value();
  }
};

// service_traits::DataType< ::orbbec_camera::GetInt32Response> should match
// service_traits::DataType< ::orbbec_camera::GetInt32 >
template<>
struct DataType< ::orbbec_camera::GetInt32Response>
{
  static const char* value()
  {
    return DataType< ::orbbec_camera::GetInt32 >::value();
  }
  static const char* value(const ::orbbec_camera::GetInt32Response&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ORBBEC_CAMERA_MESSAGE_GETINT32_H