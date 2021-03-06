#ifndef _IRREGULARWINDOW_H_
#define _IRREGULARWINDOW_H_
/**
  * 不规则窗体类
*/

#include <windows.h>
#include <string>
#include <tchar.h>
#include <assert.h>

#ifndef __String
	#ifdef UNICODE
		#define __String wstring
	#else
		#define __String string
	#endif
#endif


using namespace std;

const DWORD c_dwTransColor = 0x00ff00ff;

class CIrregularWindow
{
public:

	CIrregularWindow(const TCHAR* pBackImgFullPath,DWORD dwAttachWndTransColor = c_dwTransColor);

	//附加窗体
	bool AttachWindow(HWND hWnd);
	bool SetTransWnd(HWND hWnd);
	//背景图片(全路径 png)
	void SetBackground(const TCHAR* pBackImgFullPath);
	static void SetBackground(HWND hWnd, const TCHAR* pBackImgFullPath);
	static void UpdateLayeredWnd();


	//一般情况 是不用调这个函数的 但是如果出现 
	//被附加的窗体的子窗体 显示不完全的情况 则需要设置这个值
	void SetAttachWndTransColor(DWORD dwColor);
	void SetTransSelf(DWORD dwColor);
	HWND GetHandle(){return m_hWnd;}

	void CenterWindow();

	static void InitGDIplus();

	static void UnInitGDIplus();
	HWND CreateBaseTransparentWnd();
	static void SetWndTransColor( HWND hWnd, COLORREF nColor);
	static bool SetLayeredStyle( HWND m_hWnd );

protected:

	virtual bool RegisterWindowClass();

	virtual bool Create();

public:

private:

	static LRESULT CALLBACK  __WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual bool HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	static LRESULT CALLBACK __HookProc(int nCode,WPARAM wParam,LPARAM lParam);
	static ULONG_PTR gdiplusToken;

	static HHOOK hhk;
	static CIrregularWindow*		g_pIrrglWnd;
protected:

	HWND m_hWnd;
	//被附加的窗体的句柄	
	HWND m_hAttachWnd;

	DWORD m_dwAttachWndTransColor;

	//背景图片(png)
	__String m_strBackImg;
};

#endif