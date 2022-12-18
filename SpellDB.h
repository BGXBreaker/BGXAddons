#pragma once
#include "../plugin_sdk/plugin_sdk.hpp"

namespace Database
{
	inline std::string DBVersion = "0.4.2";

	/*
	I'll try to make this as noob friendly as possible!
	If you're somewhat experienced you can skip this block of text (and probably every comment lol)

	First of all, import this (SpellDB.h) and SpellDB.cpp in your Visual Studio Project, then on your champion (or Utility for that matter) .cpp/.h file, write:
	#include "SpellDB.h"

	Then when you initalize your menu, you'll need to Initialize the Menus you need (e.g. CancelMenu, DashMenu...)
	To do that, you need to declare a TreeTab* like that:

	TreeTab *name = YourMenu->add_tab("spells", "Spells to Cancel:");

	Then call whatever menu you need; e.g.:

	Database::InitializeCancelMenu(spells);
	*/

	// Not to be used
	void InitiateSlot(TreeTab* tab, game_object_script entity, spellslot slot, std::string name, std::string spellName, bool defaultValue, int mode);

	// Returns a std::string containing the display name of a champion
	// e.g. Kaisa -> Kai'Sa / Monkeyking -> Wukong
	// NOTE: Do not use this in your 'key' for menus! This contains special characters and **WILL** break menus.
	// You can use the string in the display name of the menus without any issue.
	std::string getDisplayName(game_object_script target);

	// Returns Importance via active spell
	// Possible Return Values:
	//	0 = Not Casting / Not Supported
	//	1 = Low Importance
	//	2 = Medium Importance
	//	3 = Critical Importance
	int getCastingImportance(game_object_script target);

	// Returns Importance via spell_hash
	// Possible Return Values:
	//	0 = Not Supported
	//	1 = Low Importance
	//	2 = Medium Importance
	//	3 = Critical Importance
	// int getSpellImportanceByHash(uint32_t hash); - Not done yet.

	// Initializes Cancel Spell Menu, will only initialize for Champions Supported **and** in-game!
	void InitializeCancelMenu(TreeTab* tab);

	// Initializes Buff Menu, will only initialize for Champions Supported **and** in-game!
	void InitializeBuffMenu(TreeTab* tab);

	// Returns if buff_hash is supported **and** toggled on by user in BuffMenu
	// Use in OnBuffGain(sender, buff) as such: Database::canOnAllyBuff(buff->get_hash_name());
	bool canOnAllyBuff(uint32_t buffHash);

	// Checks if user ticked active spell
	bool canCancel(game_object_script target);

	// For Circular Spells;
	// Checks if you can guarantee a hit on a champion. To be reworked (for better usage / not exclusivity to circular spells)
	// Please refrain from using this at the moment!
	bool canGuaranteeHit(game_object_script target, float range = FLT_MAX, float speed = FLT_MAX, float delay = 0, float width = 0);
}