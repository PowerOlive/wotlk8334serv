/* 
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __BATTLEGROUNDAB_H
#define __BATTLEGROUNDAB_H

class BattleGround;

enum BG_AB_WorldStates
{
    BG_AB_OP_OCCUPIED_BASES_HORDE       = 1778,
    BG_AB_OP_OCCUPIED_BASES_ALLY        = 1779,
    BG_AB_OP_RESOURCES_ALLY             = 1776,
    BG_AB_OP_RESOURCES_HORDE            = 1777,
    BG_AB_OP_RESOURCES_MAX              = 1780,
    BG_AB_OP_RESOURCES_WARNING          = 1955
/*
    BG_AB_OP_STABLE_ICON                = 1842,             //Stable map icon (NONE)
    BG_AB_OP_STABLE_STATE_ALIENCE       = 1767,             //Stable map state (ALIENCE)
    BG_AB_OP_STABLE_STATE_HORDE         = 1768,             //Stable map state (HORDE)
    BG_AB_OP_STABLE_STATE_CON_ALI       = 1769,             //Stable map state (CON ALIENCE)
    BG_AB_OP_STABLE_STATE_CON_HOR       = 1770,             //Stable map state (CON HORDE)
    BG_AB_OP_FARM_ICON                  = 1845,             //Farm map icon (NONE)
    BG_AB_OP_FARM_STATE_ALIENCE         = 1772,             //Farm state (ALIENCE)
    BG_AB_OP_FARM_STATE_HORDE           = 1773,             //Farm state (HORDE)
    BG_AB_OP_FARM_STATE_CON_ALI         = 1774,             //Farm state (CON ALIENCE)
    BG_AB_OP_FARM_STATE_CON_HOR         = 1775,             //Farm state (CON HORDE)

    BG_AB_OP_BLACKSMITH_ICON            = 1846,             //Blacksmith map icon (NONE)
    BG_AB_OP_BLACKSMITH_STATE_ALIENCE   = 1782,             //Blacksmith map state (ALIENCE)
    BG_AB_OP_BLACKSMITH_STATE_HORDE     = 1783,             //Blacksmith map state (HORDE)
    BG_AB_OP_BLACKSMITH_STATE_CON_ALI   = 1784,             //Blacksmith map state (CON ALIENCE)
    BG_AB_OP_BLACKSMITH_STATE_CON_HOR   = 1785,             //Blacksmith map state (CON HORDE)
    BG_AB_OP_LUMBERMILL_ICON            = 1844,             //Lumber Mill map icon (NONE)
    BG_AB_OP_LUMBERMILL_STATE_ALIENCE   = 1792,             //Lumber Mill map state (ALIENCE)
    BG_AB_OP_LUMBERMILL_STATE_HORDE     = 1793,             //Lumber Mill map state (HORDE)
    BG_AB_OP_LUMBERMILL_STATE_CON_ALI   = 1794,             //Lumber Mill map state (CON ALIENCE)
    BG_AB_OP_LUMBERMILL_STATE_CON_HOR   = 1795,             //Lumber Mill map state (CON HORDE)
    BG_AB_OP_GOLDMINE_ICON              = 1843,             //Gold Mine map icon (NONE)
    BG_AB_OP_GOLDMINE_STATE_ALIENCE     = 1787,             //Gold Mine map state (ALIENCE)
    BG_AB_OP_GOLDMINE_STATE_HORDE       = 1788,             //Gold Mine map state (HORDE)
    BG_AB_OP_GOLDMINE_STATE_CON_ALI     = 1789,             //Gold Mine map state (CON ALIENCE
    BG_AB_OP_GOLDMINE_STATE_CON_HOR     = 1790,             //Gold Mine map state (CON HORDE)
*/
};

const uint32 BG_AB_OP_NODESTATES[5] =    {1767, 1782, 1772, 1792, 1787};

const uint32 BG_AB_OP_NODEICONS[5]  =    {1842, 1846, 1845, 1844, 1843};

/* Note: code uses that these IDs follow each other */
enum BG_AB_NodeObjectId
{
    BG_AB_OBJECTID_NODE_BANNER_0    = 180087,       // Stables banner
    BG_AB_OBJECTID_NODE_BANNER_1    = 180088,       // Blacksmith banner
    BG_AB_OBJECTID_NODE_BANNER_2    = 180089,       // Farm banner
    BG_AB_OBJECTID_NODE_BANNER_3    = 180090,       // Lumber mill banner
    BG_AB_OBJECTID_NODE_BANNER_4    = 180091        // Gold mine banner
};

enum BG_AB_ObjectType
{
    // for all 5 node points 8*5=40 objects
    BG_AB_OBJECT_BANNER_NEUTRAL     = 0,
    BG_AB_OBJECT_BANNER_CONT_A      = 1,
    BG_AB_OBJECT_BANNER_CONT_H      = 2,
    BG_AB_OBJECT_BANNER_ALLY        = 3,
    BG_AB_OBJECT_BANNER_HORDE       = 4,
    BG_AB_OBJECT_AURA_ALLY          = 5,
    BG_AB_OBJECT_AURA_HORDE         = 6,
    BG_AB_OBJECT_AURA_CONTESTED     = 7,

    BG_AB_OBJECT_GATE_A             = 40,
    BG_AB_OBJECT_GATE_H             = 41,

    BG_AB_OBJECT_MAX                = 42,

    BG_AB_CREATURES_MAX             = 7
};

/* Object id templates from DB */
enum BG_AB_ObjectTypes
{
    /*
    BG_AB_BUFFSPELLID_SPEEDBUFF         = 23451,
    BG_AB_BUFFSPELLID_REGENBUFF         = 23493,
    BG_AB_BUFFSPELLID_BERSERKERBUFF     = 23505,*/

    BG_AB_OBJECTID_BANNER_A             = 180058,
    BG_AB_OBJECTID_BANNER_CONT_A        = 180059,
    BG_AB_OBJECTID_BANNER_H             = 180060,
    BG_AB_OBJECTID_BANNER_CONT_H        = 180061,

    BG_AB_OBJECTID_AURA_A               = 180100,
    BG_AB_OBJECTID_AURA_H               = 180101,
    BG_AB_OBJECTID_AURA_C               = 180102,

    BG_AB_OBJECTID_GATE_A               = 180255,
    BG_AB_OBJECTID_GATE_H               = 180256
};

enum BG_AB_Timers
{
    BG_AB_FLAG_CAPTURING_TIME           = 60000,
    BG_AB_BUFF_RESPAWN_TIME             = 180000,
    BG_AB_BUFFCHECK_TIME                = 1000    // How often do we check every player's distance to every spawned buff object ?
};

enum BG_AB_Score
{
    BG_AB_MAX_TEAM_SCORE                = 2000,
    BG_AB_WARNING_SCORE                 = 1800
};

enum BG_AB_BuffObjectType
{
    BG_AB_OBJECT_SPEEDBUFF              = 0,
    BG_AB_OBJECT_REGENBUFF              = 1,
    BG_AB_OBJECT_BERSERKERBUFF          = 2
};

// buff objectid, spellid
//                                       0-speed,         1-regen,         2-berserker
const uint32 BG_AB_BuffObjects[3][2] = { {179871, 23451}, {179904, 23493}, {179905, 23505} };

/* do NOT change the order, else wrong behaviour */
enum BG_AB_BattleGroundNodes
{
    BG_AB_NODE_STABLES          = 0,
    BG_AB_NODE_BLACKSMITH       = 1,
    BG_AB_NODE_FARM             = 2,
    BG_AB_NODE_LUMBER_MILL      = 3,
    BG_AB_NODE_GOLD_MINE        = 4,

    BG_AB_NODES_COUNT           = 5
};

enum BG_AB_NodeStatus
{
    BG_AB_NODE_TYPE_NEUTRAL             = 0,
    BG_AB_NODE_TYPE_CONTESTED           = 1,
    BG_AB_NODE_STATUS_ALLY_CONTESTED    = 1,
    BG_AB_NODE_STATUS_HORDE_CONTESTED   = 2,
    BG_AB_BODE_TYPE_OCCUPIED            = 3,
    BG_AB_NODE_STATUS_ALLY_OCCUPIED     = 3,
    BG_AB_NODE_STATUS_HORDE_OCCUPIED    = 4
};

enum BG_AB_Sounds
{
    SOUND_NODE_CLAIMED                  = 8192,
    SOUND_NODE_CAPTURED_ALLIANCE        = 8173,
    SOUND_NODE_CAPTURED_HORDE           = 8213,
    SOUND_NODE_ASSAULTED_ALLIANCE       = 8174,
    SOUND_NODE_ASSAULTED_HORDE          = 8212,
    SOUND_NEAR_VICTORY                  = 8456
};

// x, y, z, o
const float BG_AB_NodePositions[5][4] = {
    {1166.785f, 1200.132f, -56.70859f, 0.9075713f},     // stables
    {977.0156f, 1046.616f, -44.80923f, -2.600541f},     // blacksmith
    {806.1821f, 874.2723f, -55.99371f, -2.303835f},     // farm
    {856.1419f, 1148.902f, 11.18469f, -2.303835f},      // lumber mill
    {1146.923f, 848.1782f, -110.917f, -0.7330382f}      // gold mine
};

// x, y, z, o, rot0, rot1, rot2, rot3
const float BG_AB_DoorPositions[2][8] = {
    {1284.597f, 1281.167f, -15.97792f, 0.7068594f, 0.012957f, -0.060288f, 0.344959f, 0.93659f},
    {708.0903f, 708.4479f, -17.8342f, -2.391099f, 0.050291f, 0.015127f, 0.929217f, -0.365784f}
};

// Tick intervals and given points: case 0,1,2,3,4,5 captured nodes
const uint32 BG_AB_TickIntervals[6] = {0, 12000, 9000, 6000, 3000, 1000};
const uint32 BG_AB_TickPoints[6] = {0, 10, 10, 10, 10, 30};

// WorldSafeLocs ids for 5 nodes, and for ally, and horde starting location
const uint32 BG_AB_GraveyardIds[7] = {895, 894, 893, 897, 896, 898, 899};

// x, y, z, o
const float BG_AB_BuffPositions[5][4] = {
    {1185.71f, 1185.24f, -56.36f, 2.56f},               // stables
    {990.75f, 1008.18f, -42.60f, 2.43f},                // blacksmith
    {817.66f, 843.34f, -56.54f, 3.01f},                 // farm
    {807.46f, 1189.16f, 11.92f, 5.44f},                 // lumber mill
    {1146.62f, 816.94f, -98.49f, 6.14f}                 // gold mine
};

// x, y, z, o
const float BG_AB_SpiritGuidePos[7][4] = {
    {1200.03f, 1171.09f, -56.47f, 5.15f},               // stables
    {1017.43f, 960.61f, -42.95f, 4.88f},                // blacksmith
    {833.00f, 793.00f, -57.25f, 5.27f},                 // farm
    {775.17f, 1206.40f, 15.79f, 1.90f},                 // lumber mill
    {1207.48f, 787.00f, -83.36f, 5.51f},                // gold mine
    {1354.05f, 1275.48f, -11.30f, 4.77f},               // alliance starting base
    {714.61f, 646.15f, -10.87f, 4.34f} };               // horde starting base

// Alliance spirit guide, Horde spirit guide from DB
const uint32 BG_AB_SpiritGuideId[2]     = {13116, 13117};
const uint32 BG_AB_SpiritGuideTeamId[2] = { ALLIANCE, HORDE };

struct BG_AB_BuffObjectInfo
{
    GameObject  *object;
    uint32      timer;
    uint32      spellId;
};

struct BG_AB_BannerTimer
{
    uint32      timer;
    uint8       type;
    uint8       teamIndex;
};

class BattleGroundABScore : public BattleGroundScore
{
    public:
        BattleGroundABScore(): BasesAssaulted(0), BasesDefended(0) {};
        virtual ~BattleGroundABScore() {};
        uint32 BasesAssaulted;
        uint32 BasesDefended;
};

class BattleGroundAB : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundAB();
        ~BattleGroundAB();

        void Update(time_t diff);
        void AddPlayer(Player *plr);
        void RemovePlayer(Player *plr,uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        virtual bool SetupBattleGround();
        virtual void ResetBGSubclass();
        virtual WorldSafeLocsEntry const* GetClosestGraveYard(float x, float y, float z, uint32 MapId, uint32 team);

        /* Scorekeeping */
        virtual void UpdatePlayerScore(Player *Source, uint32 type, uint32 value);

        virtual void FillInitialWorldStates(WorldPacket& data);

        /* Nodes occupying */
        virtual void EventPlayerClickedOnFlag(Player *source, GameObject* target_obj);

    private:
        /* Gameobject spawning/despawning */
        void _CreateBanner(uint8 node, uint8 type, uint8 teamIndex, bool delay);
        void _DelBanner(uint8 node, uint8 type, uint8 teamIndex);
        void _SendNodeUpdate(uint8 node);

        /* Creature spawning/despawning */
        // TODO: working, scripted peons spawning
        void _NodeOccupied(uint8 node);
        void _NodeDeOccupied(uint8 node);

        const char* _GetNodeName(uint8 node);

        /* Nodes info:
            0: neutral
            1: ally contested
            2: horde contested
            3: ally occupied
            4: horde occupied     */
        uint8             m_Nodes[BG_AB_NODES_COUNT];
        uint8             m_prevNodes[BG_AB_NODES_COUNT];
        BG_AB_BannerTimer m_BannerTimers[BG_AB_NODES_COUNT];
        int32             m_NodeTimers[BG_AB_NODES_COUNT];
        Creature*         m_spiritGuides[7];
        uint32            m_TeamScores[2];
        uint32            m_lastTick[2];
        uint32            m_HonorScoreTics[2];
        uint32            m_ReputationScoreTics[2];
        uint32            m_buffchecktimer;
        bool              m_IsInformedNearVictory;

        GameObject* m_bgobjects[BG_AB_OBJECT_MAX];
        BG_AB_BuffObjectInfo m_bgbuffobjects[5];
};
#endif
