//
//  ZoomSDKPTUI.hpp
//  SaasBeePTUIModule
//
//  Created by TOTTI on 8/3/17.
//  Copyright © 2017 Zipow. All rights reserved.
//

#ifndef ZoomSDKPTUI_h
#define ZoomSDKPTUI_h

#include <stdio.h>
#include "SBPTUI.h"
#include "SaasBeePTAppInterface.h"
#include "../../common/cmmconfmgr/include/CmmConfAPI.h"

class ZoomSDKPTUI : public CSBPTUI
{
public:
    ZoomSDKPTUI();
    virtual ~ZoomSDKPTUI();
    
public:
    void setPTAPI(ISBPTAppAPI* pPTAppApi);
    void setConfAPI(ICmmConfMgrAPI* pConfAppApi);
    
};


#endif /* ZoomSDKPTUI_h */
