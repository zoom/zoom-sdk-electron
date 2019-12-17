#ifndef _ZOOM_NODE_RAW_DATA_LICENSE_H_
#define _ZOOM_NODE_RAW_DATA_LICENSE_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeRawDataLicenseWrap :
	public ZoomWrapObject<ZoomNodeRawDataLicenseWrap >
{
	friend class ZoomWrapObject<ZoomNodeRawDataLicenseWrap >;
private:
	ZoomNodeRawDataLicenseWrap();
	virtual ~ZoomNodeRawDataLicenseWrap();
public:
	/// \brief Check whether the current account has raw data license.
	/// \return If the function succeeds, the return value is SDKRawDataError_SUCCESS.
	///Otherwise the revalue is SDKRawDataError_NO_LICENSE. To get extended error information, see \link SDKRawDataError \endlink enum.
	static void HasRawDataLicense(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeRawDataLicenseWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeRawDataLicenseWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "HasRawDataLicense", ZoomNodeRawDataLicenseWrap::HasRawDataLicense);
	
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeRawDataLicenseWrap >() {
	return &ZoomNodeRawDataLicenseWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
