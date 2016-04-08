// -------------------------------------------------------------------------
//    @FileName      :   NFCHeroItemConsumeProcessModule.h
//    @Author           :   LvSheng.Huang
//    @Date             :   2013-10-02
//    @Module           :   NFCHeroItemConsumeProcessModule
//    @Desc             :   道具消费机制类--使用物品，获得技能或者道具
//                                  --技能书学习技能,礼包类获得物品,BUFF类得到BUFF,技能类使用技能
// -------------------------------------------------------------------------

#ifndef NFC_HEROITEMCONSUME_PROCESS_MODULE_H
#define NFC_HEROITEMCONSUME_PROCESS_MODULE_H

#include <iostream>
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIPackModule.h"
#include "NFComm/NFPluginModule/NFIElementInfoModule.h"
#include "NFComm/NFPluginModule/NFIItemConsumeProcessModule.h"
#include "NFComm/NFPluginModule/NFIItemConsumeManagerModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIHeroModule.h"

class NFCHeroItemConsumeProcessModule
    : public NFIItemConsumeProcessModule
{

public:
    NFCHeroItemConsumeProcessModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();
    virtual bool AfterInit();

	//物品使用是否合法
	virtual int ConsumeLegal(const NFGUID& self, const std::string& strItemName, const NFGUID& targetID);

	//合法,消耗,那么处理过程[消耗后,nItemRowID已经找不到了，因为可能被清空了]
	virtual int ConsumeProcess(const NFGUID& self, const std::string& strItemName, const NFGUID& targetID);

    bool AwardItemProperty(const NFGUID& self, const NFGUID& xHeroID, const std::string& strID);
private:
    NFIKernelModule* m_pKernelModule;
    NFILogModule* m_pLogModule;
    NFIItemConsumeManagerModule* m_pItemConsumeManagerModule;
    NFIPackModule* m_pPackModule;
    NFIElementInfoModule* m_pElementInfoModule;
    NFIHeroModule* m_pHeroModule;
};

#endif
