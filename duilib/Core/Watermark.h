#ifndef UI_WATERMARK_H_
#define UI_WATERMARK_H_

#pragma once

namespace ui
{
	class UILIB_API IWatermark
	{
	public:
		IWatermark() : m_rcMargin_(0, 0, 0, 0){};
		virtual ~IWatermark() {}
	public:
		std::wstring	m_sFontId = L"";
		unsigned int	m_nVStep = 0xFFFF;
		std::wstring	m_strText = L"";
		std::wstring	m_strColor = L"";
		bool			m_bUseWatermark = false;
		ui::UiRect		m_rcMargin_;
		int				m_nType;
	};

	class UILIB_API Watermark : protected IWatermark
	{
	public:
		Watermark()
		{
			m_sFontId = L"1";
			m_nVStep = 100;
			m_rcMargin_ = { 0, 0, 0, 0 };
			m_bUseWatermark = false;
			m_strText = L"null object";
			m_strColor = L"gray";
			m_nType = 0;
		}
		virtual ~Watermark(){}
	public:
		//�����Ƿ�ʹ��ˮӡ
		void SetUseWatermark(bool bUseWatermark);
		//��ȡ�Ƿ�ʹ��ˮӡ
		bool GetUseWatermark();
		//����ˮӡ�����С
		void SetWatermarkFont(std::wstring sFontId);
		//��ȡˮӡ�����С
		std::wstring GetWatermarkFont();
		//����ˮӡ������ɫ
		void SetWatermarkTextColor(const std::wstring& strColor);
		//��ȡˮӡ������ɫ
		std::wstring GetWatermarkTextColor();
		//����ˮӡ������ɫ
		void SetWatermarkTextColor(DWORD dwColor);
		//��ȡˮӡ������ɫ
		DWORD GetDWordWatermarkTextColor();
		//����ˮӡ����
		void SetWatermarkText(const std::wstring& strText);
		//��ȡˮӡ����
		std::wstring GetWatermarkText();
		//����ˮӡ��߾�
		void SetWatermarkMargin(const ui::UiRect rcMargin);
		//��ȡˮӡ��߾�
		ui::UiRect GetWatermarkMargin();
		//����ˮӡ����
		void SetWatermarkVStep(unsigned int nStep);
		//��ȡˮӡ����
		unsigned int GetWatermarkVStep();
		//����ˮӡ����
		void SetWatermarkType(int nType);
		//��ȡˮӡ����
		int  GetWatermarkType();
		//����ˮӡ��Ϣ
		void SetWatermarkInfo(const IWatermark& info);

		//��ˮӡ
		void PaintWatermark(IRenderContext* pRender, const ui::UiRect rcDraw);

	protected:
		virtual void OnWatermarkChange() = 0;
		virtual void SetUseWatermark_i(bool bUse){ m_bUseWatermark = bUse; }
		virtual void SetWatermarkFont_i(std::wstring sFontId){ m_sFontId = sFontId; }
		virtual void SetWatermarkTextColor_i(const std::wstring& strColor);
		virtual void SetWatermarkTextColor_i(DWORD dwColor){ m_dwTextColor = dwColor; }
		virtual void SetWatermarkText_i(const std::wstring& strText){ m_strText = strText; }
		virtual void SetWatermarkMargin_i(const ui::UiRect rcMargin){ m_rcMargin_ = rcMargin; }
		virtual void SetWatermarkVStep_i(unsigned int nStep){ m_nVStep = nStep; }
	private:
		DWORD m_dwTextColor = 0;
	};
}
#endif // UI_CORE_PLACE_HOLDER_H_