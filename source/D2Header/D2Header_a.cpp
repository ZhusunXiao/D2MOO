#include "Font.h"
#pragma warning(disable:4189)

// Storm
#include "StormHandles.h"
// #include "Storm.h"

// Fog
#include "Calc.h"
#include "D2BitManip.h"
#include "Fog.h"
#include "Safesock.h"

// D2Net
#include "Client.h"
#include "D2Net.h"
#include "Packet.h"
#include "Server.h"

// D2Lang
#include "D2Crc16.h"
#include "D2Lang.h"
#include "D2StrTable.h"
#include "D2Unicode.h"

// D2Hell
#include "Archive.h"
#include "CRC.h"
#include "Fault.h"
#include "File.h"
#include "Window.h"

// D2CMP
#include "CelCmp.h"
#include "CelDataHash.h"
#include "Codec.h"
#include "Count.h"
#include "D2CMP.h"
#include "DrwCntxt.h"
#include "FastCmp.h"
#include "FindTiles.h"
#include "GfxHash.h"
#include "LRUCache.h"
#include "PalShift.h"
#include "Palette.h"
#include "Raw.h"
#include "SpriteCache.h"
#include "SubTile.h"
#include "TileCache.h"
#include "TileLib.h"
#include "TileProjects.h"
#include "Tilecmp.h"

// D2Gfx
#include "DrawMode.h"
#include "DisplayType.h"
#include "D2Gfx.h"
// #include "CmnSubtile.h"

// D2CommonDefinitions
#include "D2BasicTypes.h"
#include "D2Constants.h"
// #include "D2Dll.h"
#include "D2PacketDef.h"
#include "D2Structs.OtherDLLs.h"

// D2Common
#include "DataTbls/AnimTbls.h"
#include "DataTbls/ArenaTbls.h"
#include "DataTbls/BeltsTbls.h"
#include "DataTbls/DataTbls.h"
#include "DataTbls/FieldTbls.h"
#include "DataTbls/HoradricCube.h"
#include "DataTbls/InvTbls.h"
#include "DataTbls/ItemsTbls.h"
#include "DataTbls/LevelsIds.h"
#include "DataTbls/LevelsTbls.h"
#include "DataTbls/MissilesIds.h"
#include "DataTbls/MissilesTbls.h"
#include "DataTbls/MonsterIds.h"
#include "DataTbls/MonsterTbls.h"
#include "DataTbls/ObjectsIds.h"
#include "DataTbls/ObjectsTbls.h"
#include "DataTbls/OverlayTbls.h"
#include "DataTbls/SequenceTbls.h"
#include "DataTbls/SkillsIds.h"
#include "DataTbls/SkillsTbls.h"
#include "DataTbls/StringIds.h"
#include "DataTbls/TokenTbls.h"
#include "DataTbls/TransformTbls.h"

#include "Drlg/D2DrlgActivate.h"
#include "Drlg/D2DrlgDrlg.h"
#include "Drlg/D2DrlgDrlgAnim.h"
#include "Drlg/D2DrlgDrlgGrid.h"
#include "Drlg/D2DrlgDrlgLogic.h"
#include "Drlg/D2DrlgDrlgRoom.h"
#include "Drlg/D2DrlgDrlgVer.h"
#include "Drlg/D2DrlgDrlgWarp.h"
#include "Drlg/D2DrlgMaze.h"
#include "Drlg/D2DrlgOutDesr.h"
#include "Drlg/D2DrlgOutJung.h"
#include "Drlg/D2DrlgOutPlace.h"
#include "Drlg/D2DrlgOutRoom.h"
#include "Drlg/D2DrlgOutSiege.h"
#include "Drlg/D2DrlgOutWild.h"
#include "Drlg/D2DrlgOutdoors.h"
#include "Drlg/D2DrlgPreset.h"
#include "Drlg/D2DrlgRoomTile.h"
#include "Drlg/D2DrlgTileSub.h"

#include "Path/Path.h"
#include "Path/PathMisc.h"
#include "Path/IDAStar.h"

#include "Units/Item.h"
#include "Units/Missile.h"
#include "Units/MissileStream.h"
#include "Units/Monster.h"
#include "Units/Object.h"
#include "Units/Player.h"
#include "Units/UnitFinds.h"
#include "Units/UnitRoom.h"
#include "Units/Units.h"

// #include "CommonDefinitions.h"
#include "D2Chat.h"
#include "D2Collision.h"
#include "D2Combat.h"
#include "D2Common.h"
#include "D2Composit.h"
#include "D2DataTbls.h"
#include "D2Dungeon.h"
#include "D2Environment.h"
#include "D2Inventory.h"
#include "D2ItemMods.h"
#include "D2Items.h"
#include "D2Log.h"
#include "D2Math.h"
#include "D2Monsters.h"
#include "D2QuestRecord.h"
#include "D2Roster.h"
#include "D2Seed.h"
#include "D2Skills.h"
#include "D2StatList.h"
#include "D2States.h"
#include "D2Text.h"
#include "D2Waypoints.h"
#include "UselessOrdinals.h"

// D2Game
#include "D2Packet.h"

#include "AI/AiBaal.h"
#include "AI/AiGeneral.h"
#include "AI/AiTactics.h"
#include "AI/AiThink.h"
#include "AI/AiUtil.h"

#include "DEBUG/Debug.h"

#include "GAME/Arena.h"
#include "GAME/CCmd.h"
#include "GAME/Clients.h"
#include "GAME/Event.h"
#include "GAME/Game.h"
#include "GAME/Level.h"
#include "GAME/SCmd.h"
#include "GAME/Targets.h"
#include "GAME/Task.h"

#include "INVENTORY/InvMode.h"

#include "ITEMS/ItemMode.h"
#include "ITEMS/Items.h"
#include "ITEMS/ItemsMagic.h"

#include "MISSILES/MissMode.h"
#include "MISSILES/Missiles.h"

#include "MONSTER/Monster.h"
#include "MONSTER/MonsterAI.h"
#include "MONSTER/MonsterChoose.h"
#include "MONSTER/MonsterMode.h"
#include "MONSTER/MonsterMsg.h"
#include "MONSTER/MonsterRegion.h"
#include "MONSTER/MonsterSpawn.h"
#include "MONSTER/MonsterUnique.h"

#include "OBJECTS/ObjEval.h"
#include "OBJECTS/ObjMode.h"
#include "OBJECTS/ObjRgn.h"
#include "OBJECTS/Objects.h"

#include "PLAYER/PartyScreen.h"
#include "PLAYER/Player.h"
#include "PLAYER/PlayerList.h"
#include "PLAYER/PlayerPets.h"
#include "PLAYER/PlayerStats.h"
#include "PLAYER/PlrIntro.h"
#include "PLAYER/PlrModes.h"
#include "PLAYER/PlrMsg.h"
#include "PLAYER/PlrSave.h"
#include "PLAYER/PlrSave2.h"
#include "PLAYER/PlrTrade.h"

#include "QUESTS/Quests.h"
#include "QUESTS/QuestsFX.h"

#include "QUESTS/ACT1/A1Intro.h"
#include "QUESTS/ACT1/A1Q0.h"
#include "QUESTS/ACT1/A1Q1.h"
#include "QUESTS/ACT1/A1Q2.h"
#include "QUESTS/ACT1/A1Q3.h"
#include "QUESTS/ACT1/A1Q4.h"
#include "QUESTS/ACT1/A1Q5.h"
#include "QUESTS/ACT1/A1Q6.h"
#include "QUESTS/ACT1/A1Q7.h"

#include "QUESTS/ACT2/A2Intro.h"
#include "QUESTS/ACT2/A2Q0.h"
#include "QUESTS/ACT2/A2Q1.h"
#include "QUESTS/ACT2/A2Q2.h"
#include "QUESTS/ACT2/A2Q3.h"
#include "QUESTS/ACT2/A2Q4.h"
#include "QUESTS/ACT2/A2Q5.h"
#include "QUESTS/ACT2/A2Q6.h"
#include "QUESTS/ACT2/A2Q7.h"
#include "QUESTS/ACT2/A2Q8.h"

#include "QUESTS/ACT3/A3Intro.h"
#include "QUESTS/ACT3/A3Q0.h"
#include "QUESTS/ACT3/A3Q1.h"
#include "QUESTS/ACT3/A3Q2.h"
#include "QUESTS/ACT3/A3Q3.h"
#include "QUESTS/ACT3/A3Q4.h"
#include "QUESTS/ACT3/A3Q5.h"
#include "QUESTS/ACT3/A3Q6.h"
#include "QUESTS/ACT3/A3Q7.h"

#include "QUESTS/ACT4/A4Q0.h"
#include "QUESTS/ACT4/A4Q1.h"
#include "QUESTS/ACT4/A4Q2.h"
#include "QUESTS/ACT4/A4Q3.h"
#include "QUESTS/ACT4/A4Q4.h"

#include "QUESTS/ACT5/A5Intro.h"
#include "QUESTS/ACT5/A5Q1.h"
#include "QUESTS/ACT5/A5Q2.h"
#include "QUESTS/ACT5/A5Q3.h"
#include "QUESTS/ACT5/A5Q4.h"
#include "QUESTS/ACT5/A5Q5.h"
#include "QUESTS/ACT5/A5Q6.h"

#include "SKILLS/SkillAma.h"
#include "SKILLS/SkillAss.h"
#include "SKILLS/SkillBar.h"
#include "SKILLS/SkillDruid.h"
#include "SKILLS/SkillItem.h"
#include "SKILLS/SkillMonst.h"
#include "SKILLS/SkillNec.h"
#include "SKILLS/SkillPal.h"
#include "SKILLS/SkillSor.h"
#include "SKILLS/Skills.h"

#include "UNIT/Friendly.h"
#include "UNIT/Party.h"
#include "UNIT/SUnit.h"
#include "UNIT/SUnitDmg.h"
#include "UNIT/SUnitEvent.h"
#include "UNIT/SUnitInactive.h"
#include "UNIT/SUnitMsg.h"
#include "UNIT/SUnitNpc.h"
#include "UNIT/SUnitProxy.h"


#include <stdio.h>

extern "C" __declspec(dllexport) void t()
{
    volatile AsyncDataLoadFileCallback AsyncDataLoadFileCallback_;
    volatile HSFILE__                  HSFILE___;
    volatile D2BinFileStrc             D2BinFileStrc_;
    volatile D2BinFieldStrc            D2BinFieldStrc_;
    volatile QServer*                  QServer_;
    volatile D2PacketBufferStrc        D2PacketBufferStrc_;
    volatile D2PacketStrc              D2PacketStrc_;

    volatile D2C_Difficulties         D2C_Difficulties_         = DIFFMODE_NORMAL;
    volatile D2C_TransactionTypes     D2C_TransactionTypes_     = TRANSACTIONTYPE_BUY;
    volatile D2HarcodedConstants      D2HarcodedConstants_      = HARDCODEDCST_MAX_LEVEL;
    volatile D2GameTypeMode           D2GameTypeMode_           = MODE_CLOSED;
    volatile D2GameResolutionMode     D2GameResolutionMode_     = D2GAMERES_800x600;
    volatile D2C_SaveMagicHeaders     D2C_SaveMagicHeaders_     = D2SMAGIC_HEADER;
    volatile D2InteractStates         D2InteractStates_         = INTERACT_NONE;
    volatile D2C_WarpTileTypes        D2C_WarpTileTypes_        = WARPTILE_TOWNENTRY;
    volatile D2C_TownLevels           D2C_TownLevels_           = D2TOWN_ROGUECAMP;
    volatile D2C_Acts                 D2C_Acts_                 = ACT_I;
    volatile D2SaveCharType           D2SaveCharType_           = CHARTYPE_HARDCORE;
    volatile D2C_TxtLinkerIndexTypes  D2C_TxtLinkerIndexTypes_  = TXTLINKER_NONE;
    volatile D2C_ItemsTxtArmorComps   D2C_ItemsTxtArmorComps_   = TXTARMORCOMP_RARM;
    volatile D2Vendors                D2Vendors_                = VENDOR_AKARA;
    volatile D2C_UIvars               D2C_UIvars_               = UI_GAME;
    volatile D2C_UiStates             D2C_UiStates_             = UI_TURNON;
    volatile D2C_AutomapCells         D2C_AutomapCells_         = MAPIMGCELL_REDCROSS;
    volatile D2C_ButtonActions        D2C_ButtonActions_        = TRADEBTN_CANCEL;
    volatile D2C_D2WinMenuEntryTypes  D2C_D2WinMenuEntryTypes_  = MENUENTRY_EDITBOX;
    volatile D2C_GlobalUiStates       D2C_GlobalUiStates_       = UISTATE_NONE;
    volatile D2C_MenuImageLoadType    D2C_MenuImageLoadType_    = MENUIMGTYPE_DC6;
    volatile D2C_NpcMenuIdx           D2C_NpcMenuIdx_           = NPCMENUIDX_AKARA;
    volatile D2C_StringColorCodes     D2C_StringColorCodes_     = STRCOLOR_WHITE;
    volatile D2C_UiButtonModes        D2C_UiButtonModes_        = BTNMODE_ENABLED;
    volatile D2C_VendorInventoryModes D2C_VendorInventoryModes_ = VENDORMODE_NONE;
    volatile D2C_VideoRenderModes     D2C_VideoRenderModes_     = VIDEOMODE_NONE;
    volatile D2C_Language             D2C_Language_             = LANGUAGE_ENGLISH;
    volatile D2C_StringTablesHcidx    D2C_StringTablesHcidx_    = STRTABLE_STRING;
    volatile D2C_ArenaMatchTypes      D2C_ArenaMatchTypes_      = D2ARENAMATCH_DEATHMATCH;
    volatile D2C_PvpFlags             D2C_PvpFlags_             = PVPFLAG_INVITEYOU;
    volatile D2Killtypes              D2Killtypes_              = KILLTYPE_SUICIDE;
    volatile D2C_ChatMessageTypes     D2C_ChatMessageTypes_     = CHAT_NONE;
    volatile D2C_SRV2CLT5A_TYPES      D2C_SRV2CLT5A_TYPES_      = EVENTTYPE_DISCONNECT;
    volatile D2C_SRV2CLT77_PARAMS     D2C_SRV2CLT77_PARAMS_     = UPDATEUI_ASKTOTRADE;
    volatile D2C_SRV2CLT9C_9D_PARAMS  D2C_SRV2CLT9C_9D_PARAMS_  = ITEMACTION_ADDTOGROUND;
    volatile D2C_OriginalQuestFlags   D2C_OriginalQuestFlags_   = QFLAG_REWARDGRANTED;
    volatile D2QuestAlert             D2QuestAlert_             = QALERT_DEFAULT;
    volatile D2QuestEvents            D2QuestEvents_            = QUESTEVENT_NPCACTIVATE;
    volatile D2ScrollMenus            D2ScrollMenus_            = SCROLLMENU_MESSAGE;

    volatile D2DrlgFlags                  D2DrlgFlags_                  = DRLGFLAG_ONCLIENT;
    volatile D2Directions                 D2Directions_                 = DIRECTION_INVALID;
    volatile D2AltDirections              D2AltDirections_              = ALTDIR_WEST;
    volatile D2C_DrlgTypes                D2C_DrlgTypes_                = DRLGTYPE_MAZE;
    volatile D2C_DrlgTileSubstitionMethod D2C_DrlgTileSubstitionMethod_ = DRLGSUBST_NONE;
    volatile D2DrlgLevelFlags             D2DrlgLevelFlags_             = DRLGLEVELFLAG_AUTOMAP_REVEAL;
    volatile D2DrlgLinkStrc               D2DrlgLinkStrc_               = {};
    volatile D2DrlgLevelLinkDataStrc      D2DrlgLevelLinkDataStrc_      = {};
    volatile D2DrlgLinkerParamsStrc       D2DrlgLinkerParamsStrc_       = {};
    volatile D2DrlgRGBStrc                D2DrlgRGBStrc_                = {};
    volatile D2DrlgUnitsStrc              D2DrlgUnitsStrc_              = {};

    volatile D2BoundingBoxStrc     D2BoundingBoxStrc_     = {};
    volatile D2C_CollisionUnitSize D2C_CollisionUnitSize_ = COLLISION_UNIT_SIZE_NONE;
    volatile D2C_CollisionPattern  D2C_CollisionPattern_  = COLLISION_PATTERN_NONE;

    volatile D2InvRectStrc D2InvRectStrc_ = {};

    volatile D2C_ItemInvPage    D2C_ItemInvPage_    = INVPAGE_INVENTORY;
    volatile D2C_NodePages      D2C_NodePages_      = NODEPAGE_STORAGE;
    volatile D2C_InventoryGrids D2C_InventoryGrids_ = INVGRID_BODYLOC;
    volatile D2TradeStates      D2TradeStates_      = TRADESTATE_OTHERNOROOM;
    volatile D2Composits        D2Composits_        = COMPOSIT_HEAD;
    volatile D2CompositStrc     D2CompositStrc_     = {};

    volatile D2DataTablesStrc  D2DataTablesStrc_  = {};
    volatile D2ArenaTxt        D2ArenaTxt_        = {};
    volatile D2CharTemplateTxt D2CharTemplateTxt_ = {};

    volatile D2C_BeltsIndices D2C_BeltsIndices_ = BELT_IDX_Belt;
    volatile D2BeltsTxt       D2BeltsTxt_       = {};

    volatile D2FieldStrc D2FieldStrc_ = {};

    volatile D2C_CubeOps      D2C_CubeOps_      = CUBEOP_COWPORTAL;
    volatile D2C_CubeOutFlags D2C_CubeOutFlags_ = CUBEFLAG_OUT_COPYMODS;
    volatile D2C_CubeInFlags  D2C_CubeInFlags_  = CUBEFLAG_IN_USEANY;

    volatile D2C_UniqueItemsTxtFlags  D2C_UniqueItemsTxtFlags_ = UNIQUEITEMSFLAG_ENABLED;
    volatile D2ItemStatCostDescStrc   D2ItemStatCostDescStrc_  = {};
    volatile D2C_StatOp               D2C_StatOp_              = STAT_OP_NONE;
    volatile D2C_ItemStatCostTxtFlags D2C_ItemStatCostTxtFlags_ = ITEMSTATCOSTFLAG_SEND_OTHER;
    volatile D2GambleTxt   D2GambleTxt_   = {};
    volatile FlagOperation FlagOperation_ = FLAG_OPERATION_OR;

    volatile D2C_LevelSubstitutionType D2C_LevelSubstitutionType_ = LVLSUBTYPE_None;

    volatile D2AutomapTxt D2AutomapTxt_ = {};

    volatile D2C_MissilesTxtFlags D2C_MissilesTxtFlags_ = MISSILESFLAG_LASTCOLLIDE;

    volatile D2InactiveMonsterFlags D2InactiveMonsterFlags_ = INACTIVEMONSTERFLAG_TYPE_OTHER;

    volatile D2C_MonTypeFlags     D2C_MonTypeFlags_     = MONTYPEFLAG_OTHER;
    volatile D2C_MercenaryClasses D2C_MercenaryClasses_ = MERC_A1;
    volatile D2C_PetWarpMode      D2C_PetWarpMode_      = PETMOVE_OWNERROOM;
    volatile D2C_MonUMods         D2C_MonUMods_         = MONUMOD_NONE;

    volatile D2MapAIActions     D2MapAIActions_     = AIACTION_MODE_NU;
    volatile D2HirelingInitStrc D2HirelingInitStrc_ = {};

    volatile D2C_MonStatsTxtFlags           D2C_MonStatsTxtFlags_           = MONSTATSFLAG_ISSPAWN;
    volatile D2C_MonStats2TxtFlags          D2C_MonStats2TxtFlags_          = MONSTATS2FLAG_NOGFXHITTEST;
    volatile D2C_MonStats2TxtComponentFlags D2C_MonStats2TxtComponentFlags_ = MONSTATS2COMPONENTFLAG_HD;
    volatile D2C_MonStats2TxtModeFlags      D2C_MonStats2TxtModeFlags_      = MONSTATS2MODEFLAG_DT;
    volatile D2TreasureClassExTxt           D2TreasureClassExTxt_           = {};
    volatile D2MonStatsInitStrc             D2MonStatsInitStrc_             = {};

    volatile D2ObjectSubClasses D2ObjectSubClasses_ = OBJSUBCLASS_SHRINE;
    volatile D2C_OverlayTypes   D2C_OverlayTypes_   = OVERLAYTYPE_MODECHNG;

    volatile D2C_SkillsTxtFlags      D2C_SkillsTxtFlags_      = SKILLSFLAG_DECQUANT;
    volatile D2C_SkillsTxtItemTarget D2C_SkillsTxtItemTarget_ = SKILLSITEMTARGET_ATTACKER;

    volatile D2PlayerWeaponSequencesStrc D2PlayerWeaponSequencesStrc_ = {};

    volatile D2C_HitClassIds     D2C_HitClassIds_     = HITCLASS_None;
    volatile D2C_PetTypeTxtFlags D2C_PetTypeTxtFlags_ = PETTYPEFLAG_WARP;

    volatile D2C_Levels D2C_Levels_ = LEVEL_NONE;

    volatile D2C_LvlPrestIds D2C_LvlPrestIds_ = LVLPREST_NONE;
    volatile D2C_LvlSubIds   D2C_LvlSubIds_   = LVLSUB_ACT1_BORDER_CLIFFS;
    volatile D2C_LvlTypes    D2C_LvlTypes_    = LVLTYPE_NONE;

    volatile D2PathTypes         D2PathTypes_         = PATHTYPE_IDASTAR;
    volatile D2PathFlags         D2PathFlags_         = PATH_UNKNOWN_FLAG_0x00001;
    volatile D2PathInfoStrc      D2PathInfoStrc_      = {};
    volatile D2LevelFileListStrc D2LevelFileListStrc_ = {};

    volatile D2C_PackedTileInformation D2C_PackedTileInformation_ = {};

    volatile D2UnkOutdoorStrc  D2UnkOutdoorStrc_  = {};
    volatile D2UnkOutdoorStrc2 D2UnkOutdoorStrc2_ = {};
    volatile D2UnkOutdoorStrc3 D2UnkOutdoorStrc3_ = {};

    volatile D2EnvironmentPeriodOfDay D2EnvironmentPeriodOfDay_ = ENVPERIOD_DAY;
    volatile D2EnvironmentDayCycles   D2EnvironmentDayCycles_   = ENVCYCLE_SUNRISE;
    volatile D2EnvironmentConstants   D2EnvironmentConstants_   = ENV_HALF_CIRCLE_DEGREES;
    volatile D2EnvironmentCycleStrc   D2EnvironmentCycleStrc_   = {};

    volatile D2MissileCalcStrc       D2MissileCalcStrc_       = {};
    volatile D2MissileDamageDataStrc D2MissileDamageDataStrc_ = {};
    volatile D2UnkMissileCalcStrc    D2UnkMissileCalcStrc_    = {};
    volatile D2MissileStrc           D2MissileStrc_           = {};

    volatile D2PropertyAssignStrc D2PropertyAssignStrc_ = {};
    volatile D2ItemCalcStrc       D2ItemCalcStrc_       = {};

    volatile D2C_PlayerModes        D2C_PlayerModes_        = PLRMODE_DEATH;
    volatile D2C_PlayerClasses      D2C_PlayerClasses_      = PCLASS_AMAZON;
    volatile D2PlayerCountBonusStrc D2PlayerCountBonusStrc_ = {};
    volatile D2PetArgStrc           D2PetArgStrc_           = {};

    volatile D2C_UnitFlags     D2C_UnitFlags_     = UNITFLAG_DOUPDATE;
    volatile D2C_UnitFlagsEx   D2C_UnitFlagsEx_   = UNITFLAGEX_HASINV;
    volatile D2C_UnitAlignment D2C_UnitAlignment_ = UNIT_ALIGNMENT_EVIL;

    volatile D2C_ItemQualities   D2C_ItemQualities_   = ITEMQUAL_INFERIOR;
    volatile D2C_ItemTypes       D2C_ItemTypes_       = ITEMTYPE_NONE_1;
    volatile D2C_ItemModes       D2C_ItemModes_       = IMODE_STORED;
    volatile D2C_ItemFlags       D2C_ItemFlags_       = IFLAG_NEWITEM;
    volatile D2C_UniqueItemFlags D2C_UniqueItemFlags_ = UNIQUEITEM_ENABLED;
    volatile D2C_ItemDropFlags   D2C_ItemDropFlags_   = ITEMDROPFLAG_ALWAYSETH;
    volatile D2C_ItemCmdFlags    D2C_ItemCmdFlags_    = ITEMCMDFLAG_DELETE;
    volatile D2ItemSaveStrc      D2ItemSaveStrc_      = {};

    volatile D2C_SkillCastType    D2C_SkillCastType_    = SKCASTTYPE_SHIFTLEFT;
    volatile D2C_AuraFilters      D2C_AuraFilters_      = AURAFILTER_FINDPLAYER;
    volatile D2C_SkillFlags       D2C_SkillFlags_       = SKFLAG_PASSIVE;
    volatile D2C_SkillUseStates   D2C_SkillUseStates_   = SKILLUSTATE_USABLE;
    volatile D2SkillCalcStrc      D2SkillCalcStrc_      = {};
    volatile D2SkillTreeChartStrc D2SkillTreeChartStrc_ = {};

    volatile D2C_StateTransformTypes D2C_StateTransformTypes_ = TRANSFORMTYPE_PLAYER;
    volatile D2C_States              D2C_States_              = STATE_NONE;
    volatile D2C_StateMasks          D2C_StateMasks_          = STATEMASK_NOSEND;

    volatile D2C_ItemStats     D2C_ItemStats_     = STAT_INVALID;
    volatile D2C_PropertyModes D2C_PropertyModes_ = PROPMODE_AFFIX;
    volatile D2C_PropertySets  D2C_PropertySets_  = PROPSET_WEAPON;

    volatile D2UnitFindArgStrc  D2UnitFindArgStrc_  = {};
    volatile D2UnitFindDataStrc D2UnitFindDataStrc_ = {};

    volatile D2TextMessageStrc D2TextMessageStrc_ = {};

    volatile D2WaypointActTableStrc   D2WaypointActTableStrc_   = {};
    volatile D2WaypointCoordTableStrc D2WaypointCoordTableStrc_ = {};
    volatile D2WaypointTableStrc      D2WaypointTableStrc_      = {};
    volatile D2WaypointFlagTableStrc  D2WaypointFlagTableStrc_  = {};

    volatile D2C_DamageApplyTypes D2C_DamageApplyTypes_ = DMGAPPLYTYPE_DURATION;
    volatile D2C_ElemTypes        D2C_ElemTypes_        = ELEMTYPE_NONE;

    volatile D2pSpellTblStrc D2pSpellTblStrc_ = {};

    volatile D2PacketTypeAdmin         D2PacketTypeAdmin_         = PACKET_ADMIN_GETINFO;
    volatile D2ServerCallbackFunctions D2ServerCallbackFunctions_ = {};
    volatile D2GameInfoStrc            D2GameInfoStrc_            = {};
    volatile D2GameStatisticsStrc      D2GameStatisticsStrc_      = {};

    volatile GAMEDATALOCKEDHANDLE GAMEDATALOCKEDHANDLE_ = {};

    volatile D2AiTableStrc D2AiTableStrc_ = {};

    volatile D2BaalThroneAiCallbackArgStrc   D2BaalThroneAiCallbackArgStrc_   = {};
    volatile D2UnkAiCallbackArgStrc          D2UnkAiCallbackArgStrc_          = {};
    volatile D2UnkAiCallbackArgStrc2         D2UnkAiCallbackArgStrc2_         = {};
    volatile D2AiCallback7ArgStrc            D2AiCallback7ArgStrc_            = {};
    volatile D2AiCallback11ArgStrc           D2AiCallback11ArgStrc_           = {};
    volatile D2DoorObjectAiCallbackArgStrc   D2DoorObjectAiCallbackArgStrc_   = {};
    volatile D2FallenShamanAiCallbackArgStrc D2FallenShamanAiCallbackArgStrc_ = {};
    volatile D2VileMotherAiCallbackArgStrc   D2VileMotherAiCallbackArgStrc_   = {};
    volatile UnkAiStrc5                      UnkAiStrc5_                      = {};

    volatile D2PacketTableStrc          D2PacketTableStrc_          = {};
    volatile D2SystemError              D2SystemError_              = SYSERROR_SUCCESS;
    volatile D2ClientFlagsEx            D2ClientFlagsEx_            = CLIENTFLAGEX_PLAYER_UNIT_ALIVE;
    volatile D2ClientUnitUpdateSortStrc D2ClientUnitUpdateSortStrc_ = {};

    volatile D2MessageListStrc        D2MessageListStrc_        = {};
    volatile D2GSPacketClt01          D2GSPacketClt01_          = {};
    volatile D2GSPacketClt02          D2GSPacketClt02_          = {};
    volatile D2GSPacketClt03          D2GSPacketClt03_          = {};
    volatile D2GSPacketClt04          D2GSPacketClt04_          = {};
    volatile D2GSPacketClt05          D2GSPacketClt05_          = {};
    volatile D2GSPacketClt06          D2GSPacketClt06_          = {};
    volatile D2GSPacketClt07          D2GSPacketClt07_          = {};
    volatile D2GSPacketClt08          D2GSPacketClt08_          = {};
    volatile D2GSPacketClt09          D2GSPacketClt09_          = {};
    volatile D2GSPacketClt0A          D2GSPacketClt0A_          = {};
    volatile D2GSPacketClt0B          D2GSPacketClt0B_          = {};
    volatile D2GSPacketClt0C          D2GSPacketClt0C_          = {};
    volatile D2GSPacketClt0D          D2GSPacketClt0D_          = {};
    volatile D2GSPacketClt0E          D2GSPacketClt0E_          = {};
    volatile D2GSPacketClt0F          D2GSPacketClt0F_          = {};
    volatile D2GSPacketClt10          D2GSPacketClt10_          = {};
    volatile D2GSPacketClt11          D2GSPacketClt11_          = {};
    volatile D2GSPacketClt12          D2GSPacketClt12_          = {};
    volatile D2GSPacketClt13          D2GSPacketClt13_          = {};
    volatile D2GSPacketClt14          D2GSPacketClt14_          = {};
    volatile D2GSPacketClt15          D2GSPacketClt15_          = {};
    volatile D2GSPacketClt16          D2GSPacketClt16_          = {};
    volatile D2GSPacketClt17          D2GSPacketClt17_          = {};
    volatile D2GSPacketClt18          D2GSPacketClt18_          = {};
    volatile D2GSPacketClt19          D2GSPacketClt19_          = {};
    volatile D2GSPacketClt20          D2GSPacketClt20_          = {};
    volatile D2GSPacketClt23          D2GSPacketClt23_          = {};
    volatile D2GSPacketClt26          D2GSPacketClt26_          = {};
    volatile D2GSPacketClt27          D2GSPacketClt27_          = {};
    volatile D2GSPacketClt29          D2GSPacketClt29_          = {};
    volatile D2GSPacketClt2A          D2GSPacketClt2A_          = {};
    volatile D2GSPacketClt2B          D2GSPacketClt2B_          = {};
    volatile D2GSPacketClt31          D2GSPacketClt31_          = {};
    volatile D2GSPacketClt32          D2GSPacketClt32_          = {};
    volatile D2GSPacketClt33          D2GSPacketClt33_          = {};
    volatile D2GSPacketClt38          D2GSPacketClt38_          = {};
    volatile D2GSPacketClt3A          D2GSPacketClt3A_          = {};
    volatile D2GSPacketClt3B          D2GSPacketClt3B_          = {};
    volatile D2GSPacketClt3C          D2GSPacketClt3C_          = {};
    volatile D2GSPacketClt3D          D2GSPacketClt3D_          = {};
    volatile D2GSPacketClt41          D2GSPacketClt41_          = {};
    volatile D2GSPacketClt42          D2GSPacketClt42_          = {};
    volatile D2GSPacketClt44          D2GSPacketClt44_          = {};
    volatile D2GSPacketClt45          D2GSPacketClt45_          = {};
    volatile D2GSPacketClt49          D2GSPacketClt49_          = {};
    volatile D2GSPacketClt4F          D2GSPacketClt4F_          = {};
    volatile D2GSPacketClt51          D2GSPacketClt51_          = {};
    volatile D2GSPacketClt58          D2GSPacketClt58_          = {};
    volatile D2GSPacketClt59          D2GSPacketClt59_          = {};
    volatile D2GSPacketClt5D          D2GSPacketClt5D_          = {};
    volatile D2GSPacketClt5E          D2GSPacketClt5E_          = {};
    volatile D2GSPacketClt5F          D2GSPacketClt5F_          = {};
    volatile D2GSPacketClt63          D2GSPacketClt63_          = {};
    volatile D2GSPacketClt64          D2GSPacketClt64_          = {};
    volatile D2GSPacketClt65          D2GSPacketClt65_          = {};
    volatile D2GSPacketClt66          D2GSPacketClt66_          = {};
    volatile D2GSPacketClt67          D2GSPacketClt67_          = {};
    volatile D2GSPacketClt68          D2GSPacketClt68_          = {};
    volatile D2GSPacketClt69          D2GSPacketClt69_          = {};
    volatile D2GSPacketClt6A          D2GSPacketClt6A_          = {};
    volatile D2GSPacketClt6B          D2GSPacketClt6B_          = {};
    volatile D2GSPacketClt6C          D2GSPacketClt6C_          = {};
    volatile D2GSPacketClt6D          D2GSPacketClt6D_          = {};
    volatile D2GSPacketClt6F          D2GSPacketClt6F_          = {};
    volatile D2GSPacketSrv00          D2GSPacketSrv00_          = {};
    volatile D2GSPacketSrv01          D2GSPacketSrv01_          = {};
    volatile D2GSPacketSrv02          D2GSPacketSrv02_          = {};
    volatile D2GSPacketSrv03          D2GSPacketSrv03_          = {};
    volatile D2GSPacketSrv04          D2GSPacketSrv04_          = {};
    volatile D2GSPacketSrv05          D2GSPacketSrv05_          = {};
    volatile D2GSPacketSrv06          D2GSPacketSrv06_          = {};
    volatile D2GSPacketSrv07          D2GSPacketSrv07_          = {};
    volatile D2GSPacketSrv08          D2GSPacketSrv08_          = {};
    volatile D2GSPacketSrv09          D2GSPacketSrv09_          = {};
    volatile D2GSPacketSrv0A          D2GSPacketSrv0A_          = {};
    volatile D2GSPacketSrv0B          D2GSPacketSrv0B_          = {};
    volatile D2GSPacketSrv0C          D2GSPacketSrv0C_          = {};
    volatile D2GSPacketSrv0D          D2GSPacketSrv0D_          = {};
    volatile D2GSPacketSrv0E          D2GSPacketSrv0E_          = {};
    volatile D2GSPacketSrv0F          D2GSPacketSrv0F_          = {};
    volatile D2GSPacketSrv10          D2GSPacketSrv10_          = {};
    volatile D2GSPacketSrv11          D2GSPacketSrv11_          = {};
    volatile D2GSPacketSrv12          D2GSPacketSrv12_          = {};
    volatile D2GSPacketSrv13          D2GSPacketSrv13_          = {};
    volatile D2GSPacketSrv14          D2GSPacketSrv14_          = {};
    volatile D2GSPacketSrv15          D2GSPacketSrv15_          = {};
    volatile D2ClientUnitUpdateStrc   D2ClientUnitUpdateStrc_   = {};
    volatile D2GSPacketSrv16          D2GSPacketSrv16_          = {};
    volatile D2GSPacketSrv17          D2GSPacketSrv17_          = {};
    volatile D2GSPacketSrv18          D2GSPacketSrv18_          = {};
    volatile D2GSPacketSrv19          D2GSPacketSrv19_          = {};
    volatile D2GSPacketSrv1A          D2GSPacketSrv1A_          = {};
    volatile D2GSPacketSrv1B          D2GSPacketSrv1B_          = {};
    volatile D2GSPacketSrv1C          D2GSPacketSrv1C_          = {};
    volatile D2GSPacketSrvStat        D2GSPacketSrvStat_        = {};
    volatile D2GSPacketSrv20          D2GSPacketSrv20_          = {};
    volatile D2GSPacketSrv21          D2GSPacketSrv21_          = {};
    volatile D2GSPacketSrv22          D2GSPacketSrv22_          = {};
    volatile D2GSPacketSrv23          D2GSPacketSrv23_          = {};
    volatile D2GSPacketSrv24          D2GSPacketSrv24_          = {};
    volatile D2GSPacketSrv25          D2GSPacketSrv25_          = {};
    volatile D2GSPacketSrv26          D2GSPacketSrv26_          = {};
    volatile D2GSPacketSrv26Args      D2GSPacketSrv26Args_      = {};
    volatile D2GSPacketSrv27          D2GSPacketSrv27_          = {};
    volatile D2GSPacketSrv28          D2GSPacketSrv28_          = {};
    volatile D2GSPacketSrv29          D2GSPacketSrv29_          = {};
    volatile D2GSPacketSrv2A          D2GSPacketSrv2A_          = {};
    volatile D2GSPacketSrv2B          D2GSPacketSrv2B_          = {};
    volatile D2GSPacketSrv2C          D2GSPacketSrv2C_          = {};
    volatile D2GSPacketSrv3A          D2GSPacketSrv3A_          = {};
    volatile D2GSPacketSrv3B          D2GSPacketSrv3B_          = {};
    volatile D2GSPacketSrv3E          D2GSPacketSrv3E_          = {};
    volatile D2GSPacketSrv3F          D2GSPacketSrv3F_          = {};
    volatile D2GSPacketSrv40          D2GSPacketSrv40_          = {};
    volatile D2GSPacketSrv42          D2GSPacketSrv42_          = {};
    volatile D2GSPacketSrv45          D2GSPacketSrv45_          = {};
    volatile D2GSPacketSrv47          D2GSPacketSrv47_          = {};
    volatile D2GSPacketSrv48          D2GSPacketSrv48_          = {};
    volatile D2GSPacketSrv4C          D2GSPacketSrv4C_          = {};
    volatile D2GSPacketSrv4D          D2GSPacketSrv4D_          = {};
    volatile D2GSPacketSrv4E          D2GSPacketSrv4E_          = {};
    volatile D2GSPacketSrv4F          D2GSPacketSrv4F_          = {};
    volatile D2GSPacketSrv50          D2GSPacketSrv50_          = {};
    volatile D2GSPacketSrv51          D2GSPacketSrv51_          = {};
    volatile D2GSPacketSrv52          D2GSPacketSrv52_          = {};
    volatile D2GSPacketSrv53          D2GSPacketSrv53_          = {};
    volatile D2GSPacketSrv54          D2GSPacketSrv54_          = {};
    volatile D2GSPacketSrv55          D2GSPacketSrv55_          = {};
    volatile D2GSPacketSrv57          D2GSPacketSrv57_          = {};
    volatile D2GSPacketSrv58          D2GSPacketSrv58_          = {};
    volatile D2GSPacketSrv59          D2GSPacketSrv59_          = {};
    volatile D2GSPacketSrv5A          D2GSPacketSrv5A_          = {};
    volatile D2GSPacketSrv5B          D2GSPacketSrv5B_          = {};
    volatile D2GSPacketSrv5C          D2GSPacketSrv5C_          = {};
    volatile D2GSPacketSrv5D          D2GSPacketSrv5D_          = {};
    volatile D2GSPacketSrv5E          D2GSPacketSrv5E_          = {};
    volatile D2GSPacketSrv5F          D2GSPacketSrv5F_          = {};
    volatile D2GSPacketSrv60          D2GSPacketSrv60_          = {};
    volatile D2GSPacketSrv61          D2GSPacketSrv61_          = {};
    volatile D2GSPacketSrv62          D2GSPacketSrv62_          = {};
    volatile D2GSPacketSrv63          D2GSPacketSrv63_          = {};
    volatile D2GSPacketSrv65          D2GSPacketSrv65_          = {};
    volatile D2GSPacketSrv66          D2GSPacketSrv66_          = {};
    volatile D2GSPacketSrv67          D2GSPacketSrv67_          = {};
    volatile D2GSPacketSrv68          D2GSPacketSrv68_          = {};
    volatile D2GSPacketSrv69          D2GSPacketSrv69_          = {};
    volatile D2GSPacketSrv6A          D2GSPacketSrv6A_          = {};
    volatile D2GSPacketSrv6B          D2GSPacketSrv6B_          = {};
    volatile D2GSPacketSrv6C          D2GSPacketSrv6C_          = {};
    volatile D2GSPacketSrv6D          D2GSPacketSrv6D_          = {};
    volatile D2GSPacketSrv6E          D2GSPacketSrv6E_          = {};
    volatile D2GSPacketSrv6F          D2GSPacketSrv6F_          = {};
    volatile D2GSPacketSrv70          D2GSPacketSrv70_          = {};
    volatile D2GSPacketSrv71          D2GSPacketSrv71_          = {};
    volatile D2GSPacketSrv72          D2GSPacketSrv72_          = {};
    volatile D2GSPacketSrv73          D2GSPacketSrv73_          = {};
    volatile D2GSPacketSrv74          D2GSPacketSrv74_          = {};
    volatile D2GSPacketSrv75          D2GSPacketSrv75_          = {};
    volatile D2GSPacketSrv76          D2GSPacketSrv76_          = {};
    volatile D2GSPacketSrv77          D2GSPacketSrv77_          = {};
    volatile D2GSPacketSrv78          D2GSPacketSrv78_          = {};
    volatile D2GSPacketSrv79          D2GSPacketSrv79_          = {};
    volatile D2GSPacketSrv7A          D2GSPacketSrv7A_          = {};
    volatile D2GSPacketSrv7B          D2GSPacketSrv7B_          = {};
    volatile D2GSPacketSrv7C          D2GSPacketSrv7C_          = {};
    volatile D2GSPacketSrv7D          D2GSPacketSrv7D_          = {};
    volatile D2GSPacketSrv7E          D2GSPacketSrv7E_          = {};
    volatile D2GSPacketSrv7F          D2GSPacketSrv7F_          = {};
    volatile D2GSPacketSrv81          D2GSPacketSrv81_          = {};
    volatile D2GSPacketSrv82          D2GSPacketSrv82_          = {};
    volatile D2GSPacketSrv89          D2GSPacketSrv89_          = {};
    volatile D2GSPacketSrv8A          D2GSPacketSrv8A_          = {};
    volatile D2GSPacketSrv8B          D2GSPacketSrv8B_          = {};
    volatile D2GSPacketSrv8C          D2GSPacketSrv8C_          = {};
    volatile D2GSPacketSrv8D          D2GSPacketSrv8D_          = {};
    volatile D2GSPacketSrv8E          D2GSPacketSrv8E_          = {};
    volatile D2GSPacketSrv8F          D2GSPacketSrv8F_          = {};
    volatile D2GSPacketSrv90          D2GSPacketSrv90_          = {};
    volatile D2GSPacketSrv91          D2GSPacketSrv91_          = {};
    volatile D2GSPacketSrv92          D2GSPacketSrv92_          = {};
    volatile D2GSPacketSrv93          D2GSPacketSrv93_          = {};
    volatile D2GSPacketSrv94          D2GSPacketSrv94_          = {};
    volatile D2GSPacketSrv95          D2GSPacketSrv95_          = {};
    volatile D2GSPacketSrv96          D2GSPacketSrv96_          = {};
    volatile D2GSPacketSrv97          D2GSPacketSrv97_          = {};
    volatile D2GSPacketSrv98          D2GSPacketSrv98_          = {};
    volatile D2GSPacketSrv99          D2GSPacketSrv99_          = {};
    volatile D2GSPacketSrv9A          D2GSPacketSrv9A_          = {};
    volatile D2GSPacketSrv9B          D2GSPacketSrv9B_          = {};
    volatile D2GSPacketSrv9C          D2GSPacketSrv9C_          = {};
    volatile D2GSPacketSrv9D          D2GSPacketSrv9D_          = {};
    volatile D2GSPacketSrvStatAndGuid D2GSPacketSrvStatAndGuid_ = {};
    volatile D2GSPacketSrvA3          D2GSPacketSrvA3_          = {};
    volatile D2GSPacketSrvA4          D2GSPacketSrvA4_          = {};
    volatile D2GSPacketSrvA5          D2GSPacketSrvA5_          = {};
    volatile D2GSPacketSrvA6          D2GSPacketSrvA6_          = {};
    volatile D2GSPacketSrvA7          D2GSPacketSrvA7_          = {};
    volatile D2GSPacketSrvA8          D2GSPacketSrvA8_          = {};
    volatile D2GSPacketSrvA9          D2GSPacketSrvA9_          = {};
    volatile D2GSPacketSrvAA          D2GSPacketSrvAA_          = {};
    volatile D2GSPacketSrvAB          D2GSPacketSrvAB_          = {};
    volatile D2GSPacketSrvAC          D2GSPacketSrvAC_          = {};
    volatile D2GSPacketSrvAD          D2GSPacketSrvAD_          = {};
    volatile D2GSPacketSrvAE          D2GSPacketSrvAE_          = {};
    volatile D2GSPacketSrvAF          D2GSPacketSrvAF_          = {};
    volatile D2GSPacketSrvB0          D2GSPacketSrvB0_          = {};
    volatile D2GSPacketSrvB1          D2GSPacketSrvB1_          = {};
    volatile D2GSPacketSrvB2          D2GSPacketSrvB2_          = {};
    volatile D2GSPacketSrvB3          D2GSPacketSrvB3_          = {};

    volatile D2GSPacketSrvB4        D2GSPacketSrvB4_        = {};
    volatile D2GameServerInfoStrc   D2GameServerInfoStrc_   = {};
    volatile D2GameServerInfoExStrc D2GameServerInfoExStrc_ = {};
    volatile D2GSPacketSrvFFFD      D2GSPacketSrvFFFD_      = {};
    volatile D2GSPacketSrvFF01      D2GSPacketSrvFF01_      = {};

    volatile D2C_EventFlags     D2C_EventFlags_  = EVENTFLAG_0x1;
    volatile D2C_UnitEventTypes D2C_EventTypes_  = UNITEVENT_HITBYMISSILE;
    volatile D2TimerArg2Strc    D2TimerArg2Strc_ = {};
    volatile D2TimerArgStrc     D2TimerArgStrc_  = {};

    volatile D2C_TaskConstants D2C_TaskConstants_ = TASKQSLOTS;
    volatile D2C_TaskTypes     D2C_TaskTypes_     = TASK_PROCESSGAME;
    volatile D2LinkStrc        D2LinkStrc_        = {};
    volatile D2TaskStrc        D2TaskStrc_        = {};

    volatile D2ObeliskPowerUpStrc D2ObeliskPowerUpStrc_ = {};
    volatile D2ObjOperateFnStrc   D2ObjOperateFnStrc_   = {};
    volatile D2ShrineTableStrc    D2ShrineTableStrc_    = {};

    volatile D2ObjInitFnStrc D2ObjInitFnStrc_ = {};

    volatile D2DamageResultFlags   D2DamageResultFlags_   = DAMAGERESULTFLAG_SUCCESSFULHIT;
    volatile D2DamageHitFlags      D2DamageHitFlags_      = DAMAGEHITFLAG_1;
    volatile D2DamageInfoStrc      D2DamageInfoStrc_      = {};
    volatile D2DamageStatTableStrc D2DamageStatTableStrc_ = {};

    volatile D2NPCMessageListStrc D2NPCMessageListStrc_ = {};

    volatile D2PetTypes D2PetTypes_ = PETTYPE_NONE;

    volatile D2UnkPlrModeStrc2  D2UnkPlrModeStrc2_  = {};
    volatile D2PlayerSave2Error D2PlayerSave2Error_ = PLRSAVE2ERROR_SUCCESS;

    volatile D2SavedItemStrc  D2SavedItemStrc_  = {};
    volatile D2SaveHeaderStrc D2SaveHeaderStrc_ = {};
    volatile D2CubeTableStrc  D2CubeTableStrc_  = {};

    volatile D2QuestStateFlagIds     D2QuestStateFlagIds_     = QUESTSTATEFLAG_A1Q0;
    volatile D2Quests                D2Quests_                = QUEST_A1Q0_WARRIVGOSSIP;
    volatile D2QuestInitTableStrc    D2QuestInitTableStrc_    = {};
    volatile D2QuestIntroTableStrc   D2QuestIntroTableStrc_   = {};
    volatile D2Act1Quest1Strc        D2Act1Quest1Strc_        = {};
    volatile D2Act1Quest2Strc        D2Act1Quest2Strc_        = {};
    volatile D2Act1Quest3Strc        D2Act1Quest3Strc_        = {};
    volatile D2Act1Quest4Strc        D2Act1Quest4Strc_        = {};
    volatile D2Act1Quest5Strc        D2Act1Quest5Strc_        = {};
    volatile D2Act1Quest6Strc        D2Act1Quest6Strc_        = {};
    volatile D2Act2Quest0Strc        D2Act2Quest0Strc_        = {};
    volatile D2Act2Quest1Strc        D2Act2Quest1Strc_        = {};
    volatile D2Act2Quest2Strc        D2Act2Quest2Strc_        = {};
    volatile D2Act2Quest3Strc        D2Act2Quest3Strc_        = {};
    volatile D2Act2Quest4Strc        D2Act2Quest4Strc_        = {};
    volatile D2Act2Quest5Strc        D2Act2Quest5Strc_        = {};
    volatile D2Act2Quest6Strc        D2Act2Quest6Strc_        = {};
    volatile D2Act2Quest7Strc        D2Act2Quest7Strc_        = {};
    volatile D2Act2Quest8Strc        D2Act2Quest8Strc_        = {};
    volatile D2Act3Quest0Strc        D2Act3Quest0Strc_        = {};
    volatile D2Act3Quest1Strc        D2Act3Quest1Strc_        = {};
    volatile D2Act3Quest2Strc        D2Act3Quest2Strc_        = {};
    volatile D2Act3Quest3Strc        D2Act3Quest3Strc_        = {};
    volatile D2Act3Quest4Strc        D2Act3Quest4Strc_        = {};
    volatile D2Act3Quest5Strc        D2Act3Quest5Strc_        = {};
    volatile D2Act3Quest6Strc        D2Act3Quest6Strc_        = {};
    volatile D2Act3Quest7Strc        D2Act3Quest7Strc_        = {};
    volatile D2Act4Quest1Strc        D2Act4Quest1Strc_        = {};
    volatile D2Act4Quest2Strc        D2Act4Quest2Strc_        = {};
    volatile D2Act4Quest3Strc        D2Act4Quest3Strc_        = {};
    volatile D2Act5Quest1Strc        D2Act5Quest1Strc_        = {};
    volatile D2Act5Quest2Strc        D2Act5Quest2Strc_        = {};
    volatile D2Act5Quest3Strc        D2Act5Quest3Strc_        = {};
    volatile D2Act5Quest4Strc        D2Act5Quest4Strc_        = {};
    volatile D2Act5Quest5Strc        D2Act5Quest5Strc_        = {};
    volatile D2Act5Quest6Strc        D2Act5Quest6Strc_        = {};
    volatile D2PrisonOfIceRewardStrc D2PrisonOfIceRewardStrc_ = {};

    volatile D2UnitInfoStrc            D2UnitInfoStrc_            = {};
    volatile D2UnitDescriptionListStrc D2UnitDescriptionListStrc_ = {};

    volatile D2AuraCallbackStrc           D2AuraCallbackStrc_           = {};
    volatile D2StaticFieldCallbackArgStrc D2StaticFieldCallbackArgStrc_ = {};
    volatile D2UnkNecSkillStrc            D2UnkNecSkillStrc_            = {};
    volatile D2_6FD106F0_Strc             D2_6FD106F0_Strc_             = {};
    volatile D2_6FD10880_Strc             D2_6FD10880_Strc_             = {};
    volatile D2EffectStrc                 D2EffectStrc_                 = {};
    volatile D2MonSkillInfoStrc           D2MonSkillInfoStrc_           = {};
    volatile D2CurseStrc                  D2CurseStrc_                  = {};
    volatile D2SummonArgStrc              D2SummonArgStrc_              = {};

    volatile UnkAiStrc1                 UnkAiStrc1_                 = {};
    volatile D2ArenaScoreTypes          D2ArenaScoreTypes_          = ARENASCORE_SUICIDE;
    volatile D2C_ClientSystemMessage    D2C_ClientSystemMessage_    = D2CLTSYS_NEWGAME;
    volatile D2ItemDropStrc             D2ItemDropStrc_             = {};
    volatile D2UnkItemModeStrc          D2UnkItemModeStrc_          = {};
    volatile D2UnkItemModeStrc2         D2UnkItemModeStrc2_         = {};
    volatile D2ItemModeArgStrc          D2ItemModeArgStrc_          = {};
    volatile D2MissileUnitFindArgStrc   D2MissileUnitFindArgStrc_   = {};
    volatile D2MissileUnitFindTableStrc D2MissileUnitFindTableStrc_ = {};
    volatile Unk                        Unk_                        = {};
    volatile D2ModeChangeStrc           D2ModeChangeStrc_           = {};
    volatile D2MonModeCallbackTableStrc D2MonModeCallbackTableStrc_ = {};
    volatile D2UnkMonCreateStrc         D2UnkMonCreateStrc_         = {};
    volatile D2UnkMonCreateStrc3        D2UnkMonCreateStrc3_        = {};
    volatile D2UnkMonCreateStrc2        D2UnkMonCreateStrc2_        = {};

    volatile D2PathIDAStarNodeStrc D2PathIDAStarNodeStrc_ = {};

    volatile D2PathIDAStarContextStrc D2PathIDAStarContextStrc_ = {};

    volatile D2C_SuperUniques D2C_SuperUniques_ = {};

    volatile Font              Font_              = {};
    volatile D2AutomapCellStrc D2AutomapCellStrc_ = {};

    volatile D2AutomapLayerStrc D2AutomapLayerStrc_ = {};

    volatile DrawMode               DrawMode_               = {};
    volatile DisplayType            DisplayType_            = {};
    volatile D2PaletteTableStrc     D2PaletteTableStrc_     = {};
    volatile D2TileLibraryBlockStrc D2TileLibraryBlockStrc_ = {};
    volatile D2GfxLightExStrc       D2GfxLightExStrc_       = {};

    volatile D2ArchiveHandleStrc D2ArchiveHandleStrc_ = {};

    volatile ARCHIVE_ShowMessageFunctionPtr ARCHIVE_ShowMessageFunctionPtr_ = {};

    volatile D2CubeItemStrc D2CubeItemStrc_ = {};

    volatile SMSGHANDLER_PARAMS SMSGHANDLER_PARAMS_ = {};

    volatile D2C_StringIndices D2C_StringIndices_ = {};
    
}
