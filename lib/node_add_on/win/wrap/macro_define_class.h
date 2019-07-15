#pragma once
#define BEGIN_CLASS_DEFINE(Classname) \
class CSDKWrap;\
class CSDKExtWrap;\
class CSDKCustomizedUIWrap;\
class Classname##Wrap \
{\
void* external_cb;
#define BEGIN_CLASS_DEFINE_WITHCALLBACK(Classname, CallBackClass)\
class CSDKWrap;\
class CSDKExtWrap;\
class CSDKCustomizedUIWrap;\
class Classname##Wrap : public CallBackClass \
{\
CallBackClass* external_cb;
#define STAITC_CLASS(Classname) \
friend CSDKWrap;\
friend CSDKExtWrap;\
friend CSDKCustomizedUIWrap;\
private:\
	Classname##Wrap(){m_obj = NULL;external_cb=NULL;};\
	static Classname##Wrap& GetInst(){static Classname##Wrap inst; return inst;};\
public: