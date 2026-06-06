#include "D2WinAccountList.h"
#include "D2WinAnimImage.h"
#include "D2WinButton.h"
#include "D2WinControlHeader.h"
#include "D2WinEditBox.h"
#include "D2WinFont.h"
#include "D2WinList.h"
#include "D2WinPopUp.h"

#include "D2WinImage.h"

#include "D2WinPalette.h"
#include "D2WinProgressBar.h"
#include "D2WinScrollBar.h"
#include "D2WinSmack.h"
#include "D2WinTextBox.h"
#include "D2WinTimer.h"
#include "D2WRegister.h"

#include "D2Config.h"

// CmnSubtile.h here (not in D2Header_a.cpp) to avoid the D2TileLibraryBlockStrc
// redefinition with D2CMP.h, which is included by D2Header_a.cpp.
#include "CmnSubtile.h"

extern "C" __declspec(dllexport) void t2()
{
    volatile D2WinAccountListStrc D2WinAccountListStrc_ = {};
    volatile D2WinAnimImageStrc   D2WinAnimImageStrc_   = {};
    volatile D2ConfigStrc         D2ConfigStrc_         = {};
    volatile D2WinButtonStrc      D2WinButtonStrc_      = {};

    volatile D2EditBoxFlags   D2EditBoxFlags_   = {};
    volatile D2WinEditBoxStrc D2WinEditBoxStrc_ = {};

    volatile D2CharStrc         D2CharStrc_         = {};
    volatile D2FontStrc         D2FontStrc_         = {};
    volatile D2FontCacheStrc    D2FontCacheStrc_    = {};
    volatile D2SplittedTextStrc D2SplittedTextStrc_ = {};

    volatile D2WinImageClickRectStrc D2WinImageClickRectStrc_ = {};
    volatile D2WinImageStrc          D2WinImageStrc_          = {};
    volatile D2WinImage2Strc         D2WinImage2Strc_         = {};

    volatile D2WinListDataStrc D2WinListDataStrc_ = {};
    volatile D2WinListStrc     D2WinListStrc_     = {};

    volatile D2WinPopUpLineStrc D2WinPopUpLineStrc_ = {};
    volatile D2WinPopUpStrc     D2WinPopUpStrc_     = {};

    volatile D2ShadowLightGammaPaletteStrc D2ShadowLightGammaPaletteStrc_ = {};
    volatile D2WinProgressBarStrc          D2WinProgressBarStrc_          = {};

    volatile D2WinScrollBarStrc       D2WinScrollBarStrc_       = {};
    volatile D2WinSmackStrc           D2WinSmackStrc_           = {};
    volatile D2WinTextBoxLineStrc     D2WinTextBoxLineStrc_     = {};
    volatile D2WinTextBoxStrc         D2WinTextBoxStrc_         = {};
    volatile D2WinTimerStrc           D2WinTimerStrc_           = {};
    volatile D2WinCommandRegisterStrc D2WinCommandRegisterStrc_ = {};

    // --- additional types needed by dev/d2/mo (scripts/d2mpre/a.py) ---
    volatile ButtonFlags    ButtonFlags_    = {};
    volatile D2ControlTypes D2ControlTypes_ = {};
    volatile D2PaletteStrc  D2PaletteStrc_  = {};
}