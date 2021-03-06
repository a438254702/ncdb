#pragma once
//#include "stdafx.h"
#include "..\PiTypeDef.h"
#include <shlwapi.h>
#include <shellapi.h>
#include <Windows.h>
using std::string;




class CPIUITool
{
public:
	struct tagSELECT_FILE_DIR
	{
		HWND			hParent;			//所属窗口， 可以为空
		const wchar_t*	szInitialDir;			//初始显示目录, 可为空
		const wchar_t*	szInitialFileName;	//初始显示文件名
		const wchar_t*	szTitle;			//窗口标题， 可为空
		const wchar_t*	szBtnOkName;		//ok按钮要替换成的名字，  如果为空则显示为"确定"
		const wchar_t*	szFilter;			//过滤字符串
		const wchar_t*	szDefExt;			//保存对话框使用，默认后缀名, 如rmvb
		bool			bCenterToParent;	//true相对父窗口居中， 否则屏幕居中
		bool			bSelectMulti;		//true为允许选择多个文件
		int				nFilterIndex;		//保存对话框使用， 返回用户选择了第几行的filter

		tagSELECT_FILE_DIR()
			:hParent(nullptr)
			, szInitialDir(nullptr)
			, szInitialFileName(nullptr)
			, szTitle(nullptr)
			, szBtnOkName(nullptr)
            , szFilter(nullptr)
			, szDefExt(nullptr)
			, bCenterToParent(true)
			, bSelectMulti(false)
			, nFilterIndex(0)
		{

		}
	};
	struct tagSAVE_FILE
	{
		HWND			hParent;			//所属窗口， 可以为空
		const wchar_t*	szInitialDir;			//初始显示目录, 可为空
		const wchar_t*	szTitle;			//窗口标题， 可为空
		const wchar_t*	szFilter;			//过滤字符串
		const wchar_t*	szBeginFileName;	//默认文件名
		bool			bCenterToParent;	//true相对父窗口居中， 否则屏幕居中

		tagSAVE_FILE()
			:hParent(nullptr)
			, szInitialDir(nullptr)
			, szTitle(nullptr)
			, szFilter(nullptr)
			, szBeginFileName(nullptr)
			, bCenterToParent(true)
		{}
	};
	/************************************************************************/
	/*	fun: 获取一个拖放文件路径, 窗口需要支持拖放:通过DragAcceptFiles设置
	/************************************************************************/
	static tstring GetOneDragFilePath(const HDROP& hd);
	static tstring SelectDirectory(HWND hParent, tcpchar szBeginDir, tcpchar szTitle);

	/************************************************************************
		fun:	弹出选择对话框，  可选择文件或目录
		param:	szBeginDir, 弹窗后显示的起始目录， 如果目录不存在则显示上次的目录
		memo:	
	************************************************************************/
	static int SelectFileOrDir(tagSELECT_FILE_DIR* pTag);
	static ARR_STRING& GetFileList();
	static void AlterPath();
	static tcpchar QuerySelectFile(UNINT nIndex);

	/************************************************************************
		fun:	保存对话框
		param:	
		memo:	
	************************************************************************/
	static tstring PopSaveDialog(tagSELECT_FILE_DIR* pTag);
	static int SelectFileOrDirVista(tagSELECT_FILE_DIR* pTag);
private:
	static		ARR_STRING		m_FileList;
};
