#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "GenericWarriorStrategy.h"
#include "WarriorAiObjectContext.h"

using namespace ai;

class GenericWarriorStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericWarriorStrategyActionNodeFactory()
    {
        creators["hamstring"] = &hamstring;
        creators["heroic strike"] = &heroic_strike;
        creators["battle shout"] = &battle_shout;
    }
private:
    static ActionNode* hamstring(PlayerbotAI* ai)
    {
        return new ActionNode ("hamstring",
            /*P*/ NextAction::array(0, new NextAction("battle stance"), NULL),
            /*A*/ NULL,
            /*C*/ NULL);
    }
    static ActionNode* heroic_strike(PlayerbotAI* ai)
    {
        return new ActionNode ("heroic strike",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
    static ActionNode* battle_shout(PlayerbotAI* ai)
    {
        return new ActionNode ("battle shout",
            /*P*/ NULL,
            /*A*/ NextAction::array(0, new NextAction("melee"), NULL),
            /*C*/ NULL);
    }
};

GenericWarriorStrategy::GenericWarriorStrategy(PlayerbotAI* ai) : CombatStrategy(ai)
{
    actionNodeFactories.Add(new GenericWarriorStrategyActionNodeFactory());
}

void GenericWarriorStrategy::InitTriggers(std::list<TriggerNode*> &triggers)
{
	CombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "battle shout",
        NextAction::array(0, new NextAction("battle shout", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "rend",
        NextAction::array(0, new NextAction("rend", ACTION_NORMAL + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "light aoe",
        NextAction::array(0, new NextAction("thunder clap", ACTION_HIGH + 2), new NextAction("demoralizing shout", ACTION_HIGH + 2), NULL)));

    triggers.push_back(new TriggerNode(
        "medium aoe",
        NextAction::array(0, new NextAction("cleave", ACTION_HIGH + 3), NULL)));

    triggers.push_back(new TriggerNode(
        "bloodrage",
        NextAction::array(0, new NextAction("bloodrage", ACTION_HIGH + 1), NULL)));

    triggers.push_back(new TriggerNode(
        "shield bash",
        NextAction::array(0, new NextAction("shield bash", ACTION_NORMAL + 4), NULL)));

	triggers.push_back(new TriggerNode(
		"critical health",
		NextAction::array(0, new NextAction("intimidating shout", ACTION_EMERGENCY), NULL)));
}