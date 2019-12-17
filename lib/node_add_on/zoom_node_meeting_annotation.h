#ifndef _ZOOM_NODE_MEETING_ANNOTATION_H_
#define _ZOOM_NODE_MEETING_ANNOTATION_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingAnnotationWrap :
	public ZoomWrapObject<ZoomNodeMeetingAnnotationWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingAnnotationWrap >;
private:
	ZoomNodeMeetingAnnotationWrap() {};
	~ZoomNodeMeetingAnnotationWrap() {};
public:
	/// \brief Determine if the annotation tools are disabled or not during the current meeting.
	/// \return FALSE indicates enabled while TRUE indicates disabled.
	static void IsAnnoataionDisable(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Display annotation toolbar.
	/// \param 1. type(number) Specify which view to display the toolbar. For more details, see \link ZNSDKViewType \endlink enum.
	/// \param 2. left(string) Specify X-axis coordinate of the upper-left corner for the toolbar.
	/// \param 3. top(string) Specify Y-axis coordinate of the upper-left corner for the toolbar.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS. 
	///Otherwise failed. For extended error information, see \link ZNSDKError \endlink enum.
	static void StartAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Close the current annotation toolbar.
	/// \param 1. type(number) Specify which view to close the toolbar. For more details, see \link ZNSDKViewType \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. For extended error information, see \link ZNSDKError \endlink enum.
	static void StopAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Choose annotation tool.
	/// \param 1. viewtype(number) Specify which view to display the toolbar. For more details, see \link ZNSDKViewType \endlink enum.
	/// \param 2. tooltype(number) Specify the annotation tool to be used.
	///For the definitions of the tools, see \link ZNAnnotationToolType \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetTool(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Clear present annotations. 
	/// \param 1. viewtype(number) Specify on which view to clear the annotations. For more details, see \link ZNSDKViewType \endlink enum.
	/// \param 2. cleartype(number) Specify the ways to clear annotations. For the definitions of the tools, see \link ZNAnnotationClearType \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Clear(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the colors of annotation tools.
	/// \param 1. viewtype(number) The specified color is used on which view. For more details, see \link ZNSDKViewType \endlink enum. 
	/// \param 2. color(string) Specify the color of the annotation tools in RGB format.  
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetColor(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the line width of annotation tools.
	/// \param 1. viewtype(number) The specified line width is used on which view. For more details, see \link ZNSDKViewType \endlink enum. 
	/// \param 2. lineWidth(string) Specify the line width to annotate.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetLineWidth(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Undo the last annotation.
	/// \param 1. viewtype(number) Specify on which view to undo the last annotation. For more details, see \link ZNSDKViewType \endlink enum. 
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Undo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Redo the last-undo annotation.
	/// \param 1. viewtype(number) Specify on which view to redo the last-undo annotation. For more details, see \link ZNSDKViewType \endlink enum.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void Redo(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingAnnotationWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingAnnotationWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAnnoataionDisable", ZoomNodeMeetingAnnotationWrap::IsAnnoataionDisable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAnnotation", ZoomNodeMeetingAnnotationWrap::StartAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopAnnotation", ZoomNodeMeetingAnnotationWrap::StopAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetTool", ZoomNodeMeetingAnnotationWrap::SetTool);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Clear", ZoomNodeMeetingAnnotationWrap::Clear);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetColor", ZoomNodeMeetingAnnotationWrap::SetColor);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLineWidth", ZoomNodeMeetingAnnotationWrap::SetLineWidth);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Undo", ZoomNodeMeetingAnnotationWrap::Undo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Redo", ZoomNodeMeetingAnnotationWrap::Redo);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingAnnotationWrap >() {
	return &ZoomNodeMeetingAnnotationWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#endif
