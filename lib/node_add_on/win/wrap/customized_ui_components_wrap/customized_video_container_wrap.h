#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE

BEGIN_CLASS_DEFINE_WITHCALLBACK(ICustomizedVideoContainer, ICustomizedVideoContainerEvent)
NORMAL_CLASS(ICustomizedVideoContainer)
~ICustomizedVideoContainerWrap();
void Init(ICustomizedVideoContainer* pObj);
void UnInit();
//virtual SDKError SetEvent(ICustomizedVideoContainerEvent* pEvent) = 0;
DEFINE_FUNC_1(SetEvent, SDKError, ICustomizedVideoContainerEvent*, pEvent)
//virtual SDKError CreateVideoElement(IVideoRenderElement** ppElement, VideoRenderElementType type_) = 0;
DEFINE_FUNC_2(CreateVideoElement, SDKError, IVideoRenderElement**, ppElement, VideoRenderElementType, type_)
//virtual SDKError DestroyVideoElement(IVideoRenderElement* ppElement) = 0;
DEFINE_FUNC_1(DestroyVideoElement, SDKError, IVideoRenderElement*, ppElement)
//virtual SDKError DestroyAllVideoElement() = 0;
DEFINE_FUNC_0(DestroyAllVideoElement, SDKError)
//virtual SDKError Show() = 0;
DEFINE_FUNC_0(Show, SDKError)
//virtual SDKError Hide() = 0;
DEFINE_FUNC_0(Hide, SDKError)
//virtual SDKError Resize(RECT rc) = 0;
DEFINE_FUNC_1(Resize, SDKError, RECT, rc)
//virtual IList<IVideoRenderElement* >* GetVideoElementList() = 0;
DEFINE_FUNC_0(GetVideoElementList, IList<IVideoRenderElement* >*)

//virtual void onRenderUserChanged(IVideoRenderElement* pElement, unsigned int userid) = 0;
CallBack_FUNC_2(onRenderUserChanged, IVideoRenderElement*, pElement, unsigned int, userid)
//virtual void onRenderDataTypeChanged(IVideoRenderElement* pElement, VideoRenderDataType dataType) = 0;
CallBack_FUNC_2(onRenderDataTypeChanged, IVideoRenderElement*, pElement, VideoRenderDataType, dataType)
//virtual void onLayoutNotification(RECT wnd_client_rect) = 0;
CallBack_FUNC_1(onLayoutNotification, RECT, wnd_client_rect)
//virtual void onVideoRenderElementDestroyed(IVideoRenderElement* pElement) = 0;
CallBack_FUNC_1(onVideoRenderElementDestroyed, IVideoRenderElement*, pElement)
//virtual void onWindowMsgNotification(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
CallBack_FUNC_3(onWindowMsgNotification, UINT, uMsg, WPARAM, wParam, LPARAM, lParam)
//virtual void onSubscribeUserFail(int iErrorCode, IVideoRenderElement* pElement) = 0;
CallBack_FUNC_2(onSubscribeUserFail, int, iErrorCode, IVideoRenderElement*, pElement)
END_CLASS_DEFINE(ICustomizedVideoContainer)
END_ZOOM_SDK_NAMESPACE