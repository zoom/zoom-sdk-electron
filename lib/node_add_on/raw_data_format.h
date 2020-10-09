#ifndef _raw_data_format_h_
#define _raw_data_format_h_
#if (defined _WIN32)
#include "win/h/zoom_sdk_raw_data_def.h"
#include "win/h/zoom_sdk_platform.h"
#endif
#include "uv_ipc_common.h"

#define TYPE_NONE  0
#define TYPE_VIDEO 1
#define TYPE_SHARE 2
#define TYPE_AUDIO 3
#if (defined _WIN32)
#define VIDEO_PIPE_NAME "\\\\.\\pipe\\videoPipe"
#define SHARE_PIPE_NAME "\\\\.\\pipe\\sharePipe"
#define AUDIO_PIPE_NAME "\\\\.\\pipe\\audioPipe"
#else
#define VIDEO_PIPE_NAME "/tmp/videoPipe"
#define SHARE_PIPE_NAME "/tmp/sharePipe"
#define AUDIO_PIPE_NAME "/tmp/audioPipe"
#endif
struct RawDataCommonHeader
{
	unsigned int type;
	RawDataCommonHeader()
	{
		type = TYPE_NONE;
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 
struct VideoRawDataHeader
{
	RawDataCommonHeader common_header;
	unsigned int dataBufferLen;
	unsigned long long recvHandle;
	unsigned int isLimitedI420;
	unsigned int width;
	unsigned int height;
	unsigned int rotation;
	unsigned long long y_offset;
	unsigned long long u_offset;
	unsigned long long v_offset;
	unsigned int source_id;
	VideoRawDataHeader()
	{
		memset(this, 0, sizeof(*this));
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 

struct AudioRawDataHeader
{
	RawDataCommonHeader common_header;
	unsigned int node_id;
	unsigned int dataBufferLen;
	unsigned int sampleRate;
	unsigned int channelNum;
	AudioRawDataHeader()
	{
		memset(this, 0, sizeof(*this));
	}
}
#ifdef _WIN32
;
#else
__attribute__((aligned(1)));
#endif 
#ifdef _WIN32
UVIPCMessage* MakeUVIPCMsg(YUVRawDataI420* data_, unsigned long long recv_handle, unsigned int type);
UVIPCMessage* MakeUVIPCMsg(AudioRawData* data_, unsigned int node_id_, unsigned int type);
#else
struct ZoomNodeYUVRawdataI420
{
	char* buff;
	char* ybuff;
	char* ubuff;
	char* vbuff;
	unsigned int dataBufferLen;
	unsigned long long recvHandle;
	unsigned int isLimitedI420;
	unsigned int streamWidth;
	unsigned int streamHeight;
	unsigned int rotation;
	unsigned int source_id;
	ZoomNodeYUVRawdataI420()
	{
		buff = NULL;
		ybuff = NULL;
		ubuff = NULL;
		vbuff = NULL;
		dataBufferLen = 0;
		recvHandle = 0;
		isLimitedI420 = 0;
		streamWidth = 0;
		streamHeight = 0;
		rotation = 0;
		source_id = 0;
	}
}
__attribute__((aligned(1)));


struct ZoomNodeAudioRawdata
{
	char* buff;
	unsigned int dataBufferLen;
	unsigned int sampleRate;
	unsigned int channelNum;
	ZoomNodeAudioRawdata()
	{
		buff = NULL;
		dataBufferLen = 0;
		sampleRate = 0;
		channelNum = 0;
	}
}
__attribute__((aligned(1)));



UVIPCMessage* MakeUVIPCMsg(ZoomNodeYUVRawdataI420* data_, unsigned long long recv_handle, unsigned int type);
UVIPCMessage* MakeUVIPCMsg(ZoomNodeAudioRawdata* data_, unsigned int node_id_, unsigned int type);
#endif

#endif // !_raw_data_format_h_
