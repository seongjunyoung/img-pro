
// ImagePro_seongjunyoungDoc.cpp : CImagePro_seongjunyoungDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImagePro_seongjunyoung.h"
#endif

#include "ImagePro_seongjunyoungDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImagePro_seongjunyoungDoc

IMPLEMENT_DYNCREATE(CImagePro_seongjunyoungDoc, CDocument)

BEGIN_MESSAGE_MAP(CImagePro_seongjunyoungDoc, CDocument)
END_MESSAGE_MAP()


// CImagePro_seongjunyoungDoc ����/�Ҹ�

CImagePro_seongjunyoungDoc::CImagePro_seongjunyoungDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CImagePro_seongjunyoungDoc::~CImagePro_seongjunyoungDoc()
{
}

BOOL CImagePro_seongjunyoungDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CImagePro_seongjunyoungDoc serialization

void CImagePro_seongjunyoungDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring()==TRUE)
	{
		ar.Write(resultImg, 256 * 256);
	}
	else
	{
		CFile*fp = ar.GetFile();
		if (fp->GetLength() == 256 * 256)ar.Read(inputImg, 256 * 256);
		else AfxMessageBox("256x256 ũ���� ���ϸ� ��밡���մϴ�.");
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CImagePro_seongjunyoungDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CImagePro_seongjunyoungDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImagePro_seongjunyoungDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImagePro_seongjunyoungDoc ����

#ifdef _DEBUG
void CImagePro_seongjunyoungDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImagePro_seongjunyoungDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImagePro_seongjunyoungDoc ���
