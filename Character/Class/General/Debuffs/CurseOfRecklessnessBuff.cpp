
#include "CurseOfRecklessnessBuff.h"
#include "Character.h"
#include "Target.h"

CurseOfRecklessnessBuff::CurseOfRecklessnessBuff(Character* pchar):
    ExternalBuff(pchar, "Curse of Recklessness", BuffDuration::PERMANENT, 0,
                 "Assets/buffs/Spell_shadow_unholystrength.png",
                 "Reduces target armor by 640.", QVersionNumber::fromString("1.0.0"))
{
    this->enabled = true;
}

void CurseOfRecklessnessBuff::buff_effect_when_applied() {
    pchar->get_target()->decrease_armor(640);
}

void CurseOfRecklessnessBuff::buff_effect_when_removed() {
    pchar->get_target()->increase_armor(640);
}