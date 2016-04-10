
// VideoCopyRendererDlg.h : ��� ����
//

#pragma once

#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )

// CVideoCopyRendererDlg ��ȭ ����
class CVideoCopyRendererDlg : public CDialog
{
// �����Դϴ�.
public:
	CVideoCopyRendererDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	~CVideoCopyRendererDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_VIDEOCOPYRENDERER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

	BOOL    Init( HWND hWnd, int nWidth, int nHeight );
    HRESULT InitD3D( HWND hWnd );
    HRESULT InitVB();
    HRESULT InitTexture( int nWidth, int nHeight );

	void    Cleanup();
    void    Render();
    void    DoubleBuffering(void* pvData, UINT uiDataSize);

	BOOL    StartVideoPlayer(TCHAR* pszFilePath);
    void    ClosePipes();
    int     ProcProcessByName(int nCommand, LPCTSTR pszProcName);    // 0 : Find, 1 : Kill

	static VOID					VideoPlayerCallback(void* pUserData, void* pvData, UINT uiDataSize);

	static unsigned __stdcall   VideoStreamPipeThread(void* lpParameter);
    static unsigned __stdcall   VideoPlayerMonitorThread(void* lpParameter);

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	DECLARE_MESSAGE_MAP()

private:
    LPDIRECT3D9             m_pD3D;         // Used to create the D3DDevice
    LPDIRECT3DDEVICE9       m_pD3DDevice;   // Our rendering device
    LPDIRECT3DVERTEXBUFFER9 m_pVB;          // Buffer to hold vertices
    LPDIRECT3DTEXTURE9      m_pTexture;     // Our texture
    LPDIRECT3DSURFACE9		m_pFrontSurface;

	D3DXMATRIX              m_Proj;

	BOOL                    m_bInitComplete;

	HANDLE                  m_hVideoStreamPipe;
    HANDLE                  m_hVideoStreamPipeThread;
    HANDLE                  m_hVideoPlayerMonitorThread;
    BOOL                    m_bStopVideoStreamPipeThread;
    BOOL                    m_bStopVideoPlayerMonitorThread;
    UINT                    m_uiVideoStreamBufferOffset;
    unsigned char*          m_pVideoStreamBuffer;

	CWnd*                   m_pScreenWnd;

    DWORD                   m_dwPipeProcTime;

	ULONG_PTR			    m_gdiplusToken;
public:
	afx_msg void OnBnClickedButtonOpen();
	afx_msg void OnBnClickedButtonPlay();
};
