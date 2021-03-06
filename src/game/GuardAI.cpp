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

#include "GuardAI.h"
#include "Errors.h"
#include "Creature.h"
#include "Player.h"
#include "TargetedMovementGenerator.h"
#include "ObjectAccessor.h"
#include "World.h"

int GuardAI::Permissible(const Creature *creature)
{
    if( creature->isGuard())
        return PERMIT_BASE_SPECIAL;

    return PERMIT_BASE_NO;
}

GuardAI::GuardAI(Creature &c) : i_creature(c), i_victimGuid(0), i_state(STATE_NORMAL), i_tracker(TIME_INTERVAL_LOOK)
{
}

void GuardAI::MoveInLineOfSight(Unit *u)
{
    if( !i_creature.getVictim() && u->isTargetableForAttack() &&
        ( u->IsHostileToPlayers() || i_creature.IsHostileTo(u) /*|| u->getVictim() && i_creature.IsFriendlyTo(u->getVictim())*/ ) &&
        u->isInAccessablePlaceFor(&i_creature))
    {
        float attackRadius = i_creature.GetAttackDistance(u);
        if(i_creature.IsWithinDistInMap(u,attackRadius) && i_creature.GetDistanceZ(u) <= CREATURE_Z_ATTACK_RANGE)
        {
            //Need add code to let guard suport player
            AttackStart(u);
            u->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
        }
    }
}

void GuardAI::EnterEvadeMode()
{
    if( !i_creature.isAlive() )
    {
        DEBUG_LOG("Creature stopped attacking because he's dead [guid=%u]", i_creature.GetGUIDLow());
        i_creature.StopMoving();
        i_creature.GetMotionMaster()->Idle();

        i_state = STATE_NORMAL;

        i_victimGuid = 0;
        i_creature.CombatStop();
        i_creature.DeleteThreatList();
        return;
    }

    Unit* victim = ObjectAccessor::GetUnit(i_creature, i_victimGuid );

    if( !victim  )
    {
        DEBUG_LOG("Creature stopped attacking because victim is non exist [guid=%u]", i_creature.GetGUIDLow());
    }
    else if( !victim ->isAlive() )
    {
        DEBUG_LOG("Creature stopped attacking because victim is dead [guid=%u]", i_creature.GetGUIDLow());
    }
    else if( victim ->HasStealthAura() )
    {
        DEBUG_LOG("Creature stopped attacking because victim is using stealth [guid=%u]", i_creature.GetGUIDLow());
    }
    else if( victim ->isInFlight() )
    {
        DEBUG_LOG("Creature stopped attacking because victim is flying away [guid=%u]", i_creature.GetGUIDLow());
    }
    else
    {
        DEBUG_LOG("Creature stopped attacking because victim outran him [guid=%u]", i_creature.GetGUIDLow());
    }

    i_creature.RemoveAllAuras();
    i_creature.DeleteThreatList();
    i_victimGuid = 0;
    i_creature.CombatStop();
    i_state = STATE_NORMAL;

    // Remove TargetedMovementGenerator from MotionMaster stack list, and add HomeMovementGenerator instead
    if( i_creature.GetMotionMaster()->top()->GetMovementGeneratorType() == TARGETED_MOTION_TYPE )
        i_creature.GetMotionMaster()->TargetedHome();
}

void GuardAI::UpdateAI(const uint32 /*diff*/)
{
    // update i_victimGuid if i_creature.getVictim() !=0 and changed
    if(!i_creature.SelectHostilTarget() || !i_creature.getVictim())
        return;

    i_victimGuid = i_creature.getVictim()->GetGUID();

    if( i_creature.isAttackReady() )
    {
        if( i_creature.IsWithinDistInMap(i_creature.getVictim(), ATTACK_DISTANCE))
        {
            i_creature.AttackerStateUpdate(i_creature.getVictim());
            i_creature.resetAttackTimer();
        }
    }
}

bool GuardAI::IsVisible(Unit *pl) const
{
    return i_creature.GetDistanceSq(pl) < sWorld.getConfig(CONFIG_SIGHT_GUARDER)
        && pl->isVisibleForOrDetect(&i_creature,true);
}

void GuardAI::AttackStart(Unit *u)
{
    if( !u )
        return;

    if (u->GetTypeId() == TYPEID_PLAYER)
        i_creature.SendZoneUnderAttackMessage((Player*)u);

    //    DEBUG_LOG("Creature %s tagged a victim to kill [guid=%u]", i_creature.GetName(), u->GetGUIDLow());
    if(i_creature.Attack(u))
    {
        i_creature.AddThreat(u, 0.0f);
        i_victimGuid = u->GetGUID();
        i_creature.GetMotionMaster()->Mutate(new TargetedMovementGenerator<Creature>(*u));
    }
}
