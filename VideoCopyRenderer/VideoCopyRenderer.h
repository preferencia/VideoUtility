
// VideoCopyRenderer.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CVideoCopyRendererApp:
// �� Ŭ������ ������ ���ؼ��� VideoCopyRenderer.cpp�� �����Ͻʽÿ�.
//

class CVideoCopyRendererApp : public CWinAppEx
{
public:
	CVideoCopyRendererApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CVideoCopyRendererApp theApp;