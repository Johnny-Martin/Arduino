#ifndef _KEYBOARDPROXYEx_H_
#define _KEYBOARDPROXYEx_H_

#include <stdint.h>
#include <HID.h>
#include "..\Matrix\Matrix.h"
#include "..\Matrix\Adapter.h"
#include "..\Encoder\Encoder.h"

namespace EKEY{
	class HIDKeyReport
	{
	public:
		HIDKeyReport();
		HIDKeyReport(const HIDKeyReport& src);
		HIDKeyReport& operator=(const HIDKeyReport& src);
		bool operator==(const HIDKeyReport& src) const;
		bool operator!=(const HIDKeyReport& src) const;
		void PushKey(uint8_t key);
		void Clear();
		void Report();
	private:
		void DeepCopy(const HIDKeyReport& src);
		bool IsEqual(const HIDKeyReport& src);
		KeyReport* pReportStruct;
	};
}

//////////////////////////////////////////////////////////////////////////////////////////////
namespace EKEY{
	HIDKeyReport::HIDKeyReport(){
		pReportStruct = new KeyReport();
	}
	HIDKeyReport::HIDKeyReport(const HIDKeyReport& src){
		pReportStruct = new KeyReport();
		DeepCopy(src);
	}
	HIDKeyReport& HIDKeyReport::operator=(const HIDKeyReport& src){
		if(&src == this) return *this;
		DeepCopy(src);
		return *this;
	}
	bool HIDKeyReport::operator==(const HIDKeyReport& src)const{
		return IsEqual(src);
	}
	bool HIDKeyReport::operator!=(const HIDKeyReport& src)const{
		return !IsEqual(src);
	}
	
	void HIDKeyReport::DeepCopy(const HIDKeyReport& src){
		pReportStruct->modifiers = src.pReportStruct->modifiers;
		for(uint8_t i=0; i<6; ++i){
			pReportStruct->keys[i] = src.pReportStruct->keys[i];
		}
	}
	bool HIDKeyReport::IsEqual(const HIDKeyReport& src){
		if(pReportStruct->modifiers != src.pReportStruct->modifiers)
			return false;
		
		for(uint8_t i=0; i<6; ++i){
			if(pReportStruct->keys[i] != src.pReportStruct->keys[i])
				return false;
		}
		return true;
	}
	
	void HIDKeyReport::PushKey(uint8_t k)
	{
		if (k > KEY_RIGHT_GUI) {
			k = k - 136;
		} else if (k >= KEY_LEFT_CTRL) {
			pReportStruct->modifiers |= (1<<(k-128));
			k = 0;
		} else {
			k = ASC2HID[k];
		}
		
		if(k != 0){
			for(uint8_t i=0; i<6; ++i){
				if(pReportStruct->keys[i] == 0){
					pReportStruct->keys[i] = k;
					break;
				}	
			}
		}
	}
	void HIDKeyReport::Clear(){
		pReportStruct->modifiers = 0;
		for(uint8_t i=0; i<6; ++i){
			pReportStruct->keys[i] = 0;
		}
	}
	void HIDKeyReport::Report(){
		HID().SendReport(2, pReportStruct, sizeof(KeyReport));
	}
}
#endif