#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "LineTargetValue.h"

using namespace ai;

Unit* LineTargetValue::Calculate()
{
    
    

    Group* group = master->GetGroup();
    if (!group)
        return NULL;

    Player *prev = master;
    Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
    for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
    {
        Player *player = sObjectMgr.GetPlayer(itr->guid);
        if( !player || !player->isAlive() || player == master)
            continue;

        if (player == bot)
            return prev;

        prev = player;
    }

    return master;
}
