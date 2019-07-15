/*****************************************************************************
*
* Copyright (C) 2013, Zoom Video Communications, Inc
*
* History:
*	Nov 2013 - Created - ken.ding@zoom.us
*	
*****************************************************************************/

#ifndef __ANNO_TYPES_H__
#define __ANNO_TYPES_H__

// ----------------------------------------------------------------------------
// Define macro switches for decroration
// ----------------------------------------------------------------------------

#ifndef IN
  #define IN
#endif

#ifndef OUT
  #define OUT
#endif

#ifndef OPTIONAL
  #define OPTIONAL
#endif

#ifndef singleton_static
  #define singleton_static static
#endif

#ifndef var_static
  #define var_static static
#endif

// ----------------------------------------------------------------------------
//	Turn it on to enable factor methods
// ----------------------------------------------------------------------------

#if defined USE_CLASS_INTERFACE && !defined ANNO_DLLEXPORT
  #define ANNO_DLLEXPORT __declspec(dllexport)
#else
  #define ANNO_DLLEXPORT
#endif

// ----------------------------------------------------------------------------
// Define primitive data types that are shared by this module and external
// applications
// ----------------------------------------------------------------------------

#ifndef Bool8
  typedef bool Bool8;
#endif

#ifndef UInt8
  typedef unsigned char UInt8;
#endif

#ifndef Int8
  typedef char Int8;
#endif

#ifndef UInt16
  typedef unsigned short UInt16;
#endif

#ifndef Int16
  typedef short Int16;
#endif

#ifndef UInt32
  #if __LP64__
    typedef unsigned int UInt32;
  #else
    typedef unsigned long UInt32;
  #endif
#endif

#ifndef Int32 
  typedef int Int32;
#endif

#ifndef Float32
  typedef float Float32;
#endif

#ifndef Double64
  typedef double Double64;
#endif

#ifndef NODEID
  typedef UInt32 NODEID;
#endif

#ifndef NULL_NODE_ID
  #define NULL_NODE_ID	0xffffffff
#endif

#ifndef BROADCAST_NODE_ID
  #define BROADCAST_NODE_ID		0x00000000
#endif

#ifndef AnnoWnd
  typedef void *AnnoWnd;	// handle
#endif

#ifndef AnnoGc
  typedef void *AnnoGc;	// handle
#endif

#ifndef WPARAM
  #if defined (__IOS__) || defined (__MACOS__)
    typedef unsigned long WPARAM;
  #elif defined (__LINUX_CLIENT__)
    typedef unsigned long WPARAM;
  #elif defined _WIN64
    typedef unsigned __int64 WPARAM;
  #elif defined __aarch64__  || defined __x86_64__
		typedef unsigned long WPARAM;
  #else
    typedef unsigned int WPARAM;
  #endif
#endif

#ifndef LPARAM
  #if defined (__IOS__) || defined (__MACOS__) 
    typedef unsigned long LPARAM;
  #elif defined _WIN64
	typedef __int64 LPARAM;
  #else
    typedef long LPARAM;
  #endif
#endif
#if defined __aarch64__  || defined __x86_64__
	#define cmm_reinterpret_cast_wparam reinterpret_cast<intptr_t>
#else
	#define cmm_reinterpret_cast_wparam reinterpret_cast<WPARAM>
#endif

typedef struct tagAnnoSize
{
    Int32        width;
    Int32        height;
} AnnoSize;

typedef struct tagAnnoOffset
{
    Int32        x;
    Int32        y;
} AnnoOffset;

#define AnnoOffsetEqual(o1, o2) ((o1.x == o2.x) && (o1.y == o2.y))

typedef struct tagAnnoRect
{
	Int32		left;
	Int32		top;
	Int32		right;
	Int32		bottom;
} AnnoRect;

#define AnnoRectEqual(r1, r2) ((r1.left == r2.left) && (r1.top == r2.top) && (r1.right == r2.right) && (r1.bottom == r2.bottom))

typedef struct tagAnnoWindow
{
	AnnoWnd		wndDrawing;		// the window on which drawing will be made, NULL means it's a whole or portion of monitor on sharer side
	AnnoRect	drawBounding;	// drawing bounding related to wndDrawing's client area, in pixel
	AnnoOffset	contentOffset;	// the x/y offset of content related to drawBounding before zooming takes effective
	Float32		zoomFactor;		// 100% = 1.0, 80% = 0.80
} AnnoWindow;

typedef struct tagAnnoWindowMultiMonitor
{
	AnnoRect	monitorRect;	// the rectangle of monitor on which the whole or portion of monitor is being shared
	AnnoRect	sharedRect;		// the rectangle of area beging shared
	Float32		dpiScaleOfMonitor;	// the DPI scale of the monitor on which the whole or portion of monitor is being shared
}  AnnoWindowMultiMonitor;

// ----------------------------------------------------------------------------
//	Supported Annotation Mode, used by structure AnnoStartupInput
// ----------------------------------------------------------------------------

typedef enum tagAnnoMode
{
	ANNO_MODE_APPSHARE,
	ANNO_MODE_SCREENSHARE_WB,
	ANNO_MODE_DOCSHARE,
	ANNO_MODE_CHAT_SCREENSHOT,
	ANNO_MODE_NONE
} AnnoMode;

// ----------------------------------------------------------------------------
//	Supported annotation tool, used by AnnoBase::SetAnnoCursor, 
//		AnnoBase::SetAnnoTool, AnnoBase::GetAnnoTool
// ----------------------------------------------------------------------------

typedef enum tagAnnoToolType
{
	ANNO_TOOL_TYPE_NONE,
	ANNO_TOOL_TYPE_PEN,
	ANNO_TOOL_TYPE_HIGHLIGHTER,
	ANNO_TOOL_TYPE_SPOTLIGHT,
	ANNO_TOOL_TYPE_ARROW,
	ANNO_TOOL_TYPE_TEXTBOX,
	ANNO_TOOL_TYPE_PICTURE,
	ANNO_TOOL_TYPE_ERASER,
	ANNO_TOOL_TYPE_BRUSH_ERASER,
	ANNO_TOOL_TYPE_PICKER,
	ANNO_TOOL_TYPE_SELECTOR,
	ANNO_TOOL_TYPE_AUTO_LINE,
	ANNO_TOOL_TYPE_AUTO_ARROW1,
	ANNO_TOOL_TYPE_AUTO_ARROW2,
	ANNO_TOOL_TYPE_AUTO_RECTANGLE,
	ANNO_TOOL_TYPE_AUTO_RECTANGLE_SEMI_FILL,
	ANNO_TOOL_TYPE_AUTO_ROUNDEDRECTANGLE,
	ANNO_TOOL_TYPE_AUTO_ROUNDEDRECTANGLE_SEMI_FILL,
	ANNO_TOOL_TYPE_AUTO_ELLIPSE,
	ANNO_TOOL_TYPE_AUTO_ELLIPSE_SEMI_FILL,
	// added 3.6
	ANNO_TOOL_TYPE_AUTO_DOUBLE_ARROW,
	ANNO_TOOL_TYPE_AUTO_RECTANGLE_FILL,
	ANNO_TOOL_TYPE_AUTO_ROUNDEDRECTANGLE_FILL,
	ANNO_TOOL_TYPE_AUTO_ELLIPSE_FILL,
	ANNO_TOOL_TYPE_AUTO_DIAMOND,
	ANNO_TOOL_TYPE_AUTO_STAMP_ARROW,
	ANNO_TOOL_TYPE_AUTO_STAMP_CHECK,
	ANNO_TOOL_TYPE_AUTO_STAMP_X,
	// added for ZRT 2.0 Mar 2017
	ANNO_TOOL_TYPE_MULTI_FLAT_PEN,
	ANNO_TOOL_TYPE_MULTI_FLAT_ERASER,
	ANNO_TOOL_TYPE_MULTI_THICKNESS_PEN,
	// added 6.7 June 2018 
	ANNO_TOOL_TYPE_AUTO_STAMP_STAR,
	ANNO_TOOL_TYPE_AUTO_STAMP_HEART,
	ANNO_TOOL_TYPE_AUTO_STAMP_QM,
	NUMBER_OF_ANNO_TOOL_TYPE
} AnnoToolType;

typedef enum tagAnnoToolState
{
    ANNO_TOOL_STATE_IDLE,
    ANNO_TOOL_STATE_READY,
    ANNO_TOOL_STATE_EDITING_SHAPE,
    ANNO_TOOL_STATE_EDITING_TEXT
} AnnoToolState;

// ----------------------------------------------------------------------------
//	AnnoBase event type, used by AnnoBaseObserver::OnAnnoBaseNotify
// ----------------------------------------------------------------------------

typedef struct tagAnnoKeyboardInfo
{
    AnnoSize    keyboardSize;
    AnnoRect    textInputFrame;
} AnnoKeyboardInfo;

typedef enum tagAnnoWhiteboardEvent
{
	ANNO_WHITEBOARD_EVENT_WINDOW_CREATED,
	ANNO_WHITEBOARD_EVENT_WINDOW_SHOWN,
	ANNO_WHITEBOARD_EVENT_WINDOW_HIDDEN,
	ANNO_WHITEBOARD_EVENT_WINDOW_DESTROYED,
	ANNO_WHITEBOARD_EVENT_WINDOW_MOVED,
	ANNO_WHITEBOARD_EVENT_WINDOW_RESIZED,
	ANNO_WHITEBOARD_EVENT_WINDOW_TO_BE_CLOSED,
	ANNO_WHITEBOARD_EVENT_WINDOW_MINIMIZED,
	ANNO_WHITEBOARD_EVENT_WINDOW_SET_TITLE
} AnnoWhiteboardEvent;

typedef enum tagAnnoEventType
{
	ANNO_EVENT_STARTED_UP           = 0,		// to notify that annotation session has just started up
	ANNO_EVENT_SHUT_DOWN            = 1,		// to notify that annotation session has just shut down
	ANNO_EVENT_ROOT_WND             = 2,		// to notify that annotation windows has been created to ensure other windows to be on top of it
	ANNO_EVENT_TOOL_CHANGED         = 3,		// to notify that current annotation tool has been changed (by mouse right click or whatever means that unknown to uppper layer)
	ANNO_EVENT_CAN_UNDO_REDO        = 4,		// to notify if or not undo/redo are available so that UI can enable/disable menu/toolbar respondingly
	ANNO_EVENT_HAS_ANNOTATION       = 5,		// to notify if or not current page has annotation so that UI can enable/disable menu/toolbar icon "Clear All"
	ANNO_EVENT_REMOTE_DRAW_FINISHED = 6,		// to notify that a remote drawing command has been just executed on local so that uppper layer (AS) sampling program knows where to retrive the dirty region for best perofrmance
	ANNO_EVENT_LOCAL_DRAWING_STATE  = 7,		// to notify that local drawing has been started (ready to accpet local mouse or touch events to draw, or drawing is in progress, etc.) or stopped (not to accpet local mouse or touch events, for example "Mouse" mode)
    ANNO_EVENT_KEYBOARD_STATE       = 8,		// to notify container window that keyboard will show or hide on iOS and Android
	ANNO_EVENT_WB_WINDOW_STATE	    = 9,		// to notify that WB window has been showed up or hidden
	ANNO_EVENT_DRAW_CHANGED			= 10,		// to notify that draw changed
	ANNO_EVENT_REMOTE_DRAWING_TO_START = 11,	// to notify AS module know that remote participants are going to add annotation to presenter's shared screen.
    ANNO_EVENT_APPLE_STYLUS_DETECTED= 12,		// to notify that an stylus type input detected on IOS
	ANNO_EVENT_ZR_WINDOW_CHANGED	= 13,		// to notify that ZR windows has been changed
	ANNO_EVENT_REQUEST_ANNOTATOR_NAME  = 14,	// to notify that current drawing changed
	ANNO_EVENT_ZR_DRAW_ANNOTATE		= 15,		// to notify that zr draw annotate
	ANNO_EVENT_PAGE_CHANGED			= 16,		// to notify that page number has changed
	NUMBER_OF_ANNO_EVENT_TYPE
} AnnoEventType;

// ----------------------------------------------------------------------------
//	AnnoBase input type: an abstraction of mouse, touch and keyboard input on 
//   all platforms
// ----------------------------------------------------------------------------

typedef enum tagAnnoInputType
{
	ANNO_INPUT_TYPE_NONE		= 0,

	ANNO_INPUT_TYPE_FOCUS		= 0x0007,	// WM_SETFOCUS
	ANNO_INPUT_TYPE_KILLFOCUS	= 0x0008,	// WM_KILLFOCUS
	ANNO_INPUT_TYPE_SETCURSOR	= 0x0020,	// WM_SETCURSOR

	ANNO_INPUT_TYPE_KEYDOWN		= 0x0100,	// WM_KEYDOWN
	ANNO_INPUT_TYPE_KEYUP		= 0x0101,	// WM_KEYUP
	ANNO_INPUT_TYPE_CHAR		= 0x0102,	// WM_CHAR

	ANNO_INPUT_TYPE_MOVE		= 0x0200,	// WM_MOUSEMOVE
	ANNO_INPUT_TYPE_LDOWN		= 0x0201,	// WM_LBUTTONDOWN
	ANNO_INPUT_TYPE_LUP			= 0x0202,	// WM_LBUTTONUP
	ANNO_INPUT_TYPE_LDCLICK		= 0x0203,	// WM_LBUTTONDBLCLK
	ANNO_INPUT_TYPE_RDOWN		= 0x0204,	// WM_RBUTTONDOWN
	ANNO_INPUT_TYPE_RUP			= 0x0205,	// WM_RBUTTONUP
	ANNO_INPUT_TYPE_RDCLICK		= 0x0206,	// WM_RBUTTONDBLCLK
	ANNO_INPUT_TYPE_MDOWN		= 0x0207,	// WM_MBUTTONDOWN
	ANNO_INPUT_TYPE_MUP			= 0x0208,	// WM_MBUTTONUP
	ANNO_INPUT_TYPE_MDCLICK		= 0x0209,	// WM_MBUTTONDBLCLK

	ANNO_INPUT_TYPE_POINTER_UPDATE			= 0x0245,
	ANNO_INPUT_TYPE_POINTER_DOWN			= 0x0246,
	ANNO_INPUT_TYPE_POINTER_UP				= 0x0247,
	ANNO_INPUT_TYPE_POINTER_ENTER			= 0x0249,
	ANNO_INPUT_TYPE_POINTER_LEAVE			= 0x024A,
	ANNO_INPUT_TYPE_POINTER_ACTIVATE		= 0x024B,
	ANNO_INPUT_TYPE_POINTER_CAPTURECHANGED	= 0x024C,
    
    ANNO_INPUT_TYPE_USER_BEGIN           = 0x0400 + 501,  // 0x400 = WM_USER
	ANNO_INPUT_TYPE_USER_LBUTTONDOWN,
	ANNO_INPUT_TYPE_USER_LBUTTONUP,
	ANNO_INPUT_TYPE_USER_MOUSEMOVE,
	ANNO_INPUT_TYPE_USER_RBUTTONDOWN,
	ANNO_INPUT_TYPE_USER_RBUTTONUP,
	ANNO_INPUT_TYPE_USER_END,

	ANNO_INPUT_TYPE_CANCEL		= 0x0500,
    
    ANNO_INPUT_TYPE_FLAGS_CHANGED   = 0x600, // Mac OSX flagsChanged
    
    ANNO_INPUT_TYPE_STYLUS = 0x700, // IOS Stylus
    ANNO_INPUT_TYPE_PENCIL_TAP = 0x701
} AnnoInputType;

typedef enum tagAnnoVirtualKey
{
	ANNO_VIRTUAL_KEY_BACK		= 0x08,
	ANNO_VIRTUAL_KEY_SHIFT		= 0x10,
	ANNO_VIRTUAL_KEY_CONTROL	= 0x11,
	ANNO_VIRTUAL_KEY_ALT		= 0x12,
	ANNO_VIRTUAL_KEY_DELETE		= 0x2E
} AnnoVirtualKey;

// ----------------------------------------------------------------------------
//	Type used by AnnoBase::SetAnnoColor
// ----------------------------------------------------------------------------

typedef enum tagAnnoColorIndex
{
	ANNO_COLOR_INDEX_ALL			= 0,
	ANNO_COLOR_INDEX_PEN			= 1,
	ANNO_COLOR_INDEX_HIGHLIGHTER	= 2,
	ANNO_COLOR_INDEX_ARROW			= 3,
	ANNO_COLOR_INDEX_SPOTLIGHT		= 4,
	ANNO_COLOR_INDEX_TEXT			= 5,
	ANNO_COLOR_INDEX_AUTO_RECTANGLE	= 6,
	ANNO_COLOR_INDEX_AUTO_ELLIPSE	= 7,
	ANNO_COLOR_INDEX_AUTO_ARROW1	= 8,
	ANNO_COLOR_INDEX_AUTO_ARROW2	= 9,
	NUMBER_OF_ANNO_COLOR_INDEX
} AnnoColorIndex;

// ----------------------------------------------------------------------------
//	Type used by all methods for return result
// ----------------------------------------------------------------------------

typedef enum tagAnnoError
{
	ANNO_OK						= 0
} AnnoError;

// ----------------------------------------------------------------------------
//	Type used by AnnoBase::AnnoStartup and AnnoBase::NewWhiteboard
// ----------------------------------------------------------------------------

typedef struct tagAnnoStartupInput
{
	AnnoMode		annoMode;
	bool			isPresenter;
	NODEID			appId;
	const wchar_t*	appName;		// NULL ended unicode string
	NODEID			sharerId;
	UInt16          undoLevel;
} AnnoStartupInput;

typedef struct tagAnnoInput
{
	AnnoInputType	inputType;
	WPARAM          wParam;
	LPARAM          lParam;
} AnnoInput;

// ----------------------------------------------------------------------------
//	Configurations
// ----------------------------------------------------------------------------

typedef enum tagWbConfigMask
{
	WB_CONFIG_NO_WINDOW_FRAME			= 0x00000001,
	WB_CONFIG_ALWAYS_FULLSCREEN			= 0x00000002,
	WB_CONFIG_NEEDS_VIRTUAL_KEYBOARD	= 0x00000004,
	WB_CONFIG_TOPMOST_WINDOW			= 0x00000008,
	WB_CONFIG_ENABLE_MULTI_TOUCH		= 0x00000010
} WbConfigMask;

typedef UInt32 WbConfig;

typedef enum tagAnnoConfigMask
{
	ANNO_CONFIG_NULL					= 0x00000000,
	ANNO_CONFIG_NEEDS_VIRTUAL_KEYBOARD	= 0x00000001,
	ANNO_CONFIG_ENABLE_MULTI_TOUCH		= 0x00000002,
	ANNO_CONFIG_DISABLE_DESKTOP_HOOK	= 0x00000004,
	ANNO_CONFIG_DISABLE_ARROW_WINDOW	= 0x00000008,
	ANNO_CONFIG_ENABLE_DIRTY_REFRESH	= 0x00000010,
	ANNO_CONFIG_MOBILE_SHARE_WB			= 0x00000020
} AnnoConfigMask;

typedef UInt32 AnnoConfig;

#endif // __ANNO_TYPES_H__
