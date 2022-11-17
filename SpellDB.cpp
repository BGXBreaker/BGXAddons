// You are free to use this as you will, you can modify it freely!
// It'd be appreciated if you left the credits in the menu functions though :)
// Updates can be found at https://github.com/0x8L4H4J/BGXAddons
// Feel free to join my Discord at https://discord.gg/czsJYCYSn8 as I'll be pinging the 'BGX Dev' role everytime the databases are updated!
#include "SpellDB.h"

namespace Database
{
    namespace db
    {
        std::map<std::string, TreeEntry*> CanCancel;
        std::map<std::string, TreeEntry*> CanOnAllyBuff;
    }

    int getCastingImportance(game_object_script target)
    {
        if (!target || !target->is_valid() || !target->is_ai_hero() || target->is_dead())
            return 0;

        auto id = target->get_champion();
        auto cast = target->get_active_spell();

        if (!cast)
            return 0;

        auto spellSlot = cast->get_spellslot();

        switch (id) {
        case champion_id::Akshan:
            switch (spellSlot) {
            case spellslot::e:
                return 1;
            case spellslot::r:
                return 2; // Not sure whether Akshan [R] should be 2 or 3.
            default:
                break;
            }

        case champion_id::Caitlyn:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::FiddleSticks:
            switch (spellSlot) {
            case spellslot::w:
                return 1;
            case spellslot::r:
                return 3;
            default:
                break;
            }

        case champion_id::Galio:
            switch (spellSlot) {
            case spellslot::w:
                return 1;
            case spellslot::r:
                return 3;
            default:
                break;
            }

        case champion_id::Gragas:
            if (spellSlot == spellslot::w)
                return 1;
            break;

        case champion_id::Irelia:
            if (spellSlot == spellslot::w)
                return 1;
            break;

        case champion_id::Ivern:
            if (spellSlot == spellslot::invalid) // Use spell hash
                return 1;
            break;

        case champion_id::Janna:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Jhin:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Karthus:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Katarina:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Kayn:
            if (spellSlot == spellslot::r) // Might discard this as the channel is being done while untargettable no matter what happens
                return 2;
            break;

        case champion_id::KSante:
            if (spellSlot == spellslot::w)
                return 1;
            break;

        case champion_id::Lucian:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Malzahar:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::MasterYi:
            if (spellSlot == spellslot::w)
                return 1; // Not sure if I should return 1 or 2 considering it's mostly used as an AA reset... returning 2 seems odd
            break;

        case champion_id::MissFortune:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Nunu:
            switch (spellSlot) {
            case spellslot::w:
                return 1;
            case spellslot::r:
                return 3;
            default:
                break;
            }

        case champion_id::Pantheon:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Poppy:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Pyke:
            if (spellSlot == spellslot::q)
                return 1;
            break;

        case champion_id::Quinn:
            if (spellSlot == spellslot::r)
                return 1;
            break;

        case champion_id::Rammus:
            if (spellSlot == spellslot::q)
                return 1;
            break;

        case champion_id::Ryze:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Shen:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Sion:
            switch (spellSlot) {
            case spellslot::q:
                return 2;
            case spellslot::r:
                return 3;
            default:
                break;
            }
            break;

        case champion_id::TahmKench:
            if (spellSlot == spellslot::w)
                return 2;
            break;

        case champion_id::Taliyah:
            if (spellSlot == spellslot::w)
                return 2;
            break;

        case champion_id::TwistedFate:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Varus:
            if (spellSlot == spellslot::q)
                return 1;
            break;

        case champion_id::Velkoz:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Vi:
            if (spellSlot == spellslot::q)
                return 1;
            break;

        case champion_id::Warwick:
            if (spellSlot == (spellslot)48 || spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Xerath:
            switch (spellSlot) {
            case spellslot::q:
                return 1;
            case spellslot::r:
                return 3;
            default:
                break;
            }

        case champion_id::Yuumi:
            switch (spellSlot) {
            case spellslot::q:
                return 1;
            case spellslot::r:
                return 3;
            default:
                break;
            }

        case champion_id::Zac:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        default:
            return 0;
        }

        return 0;
    }

    int localImportance(champion_id id, spellslot spellSlot)
    {
        switch (id) {
        case champion_id::Akshan:
            switch (spellSlot) {
            case spellslot::e:
                return 1;
            case spellslot::r:
                return 2; // Not sure whether Akshan [R] should be 2 or 3.
            default:
                break;
            }

        case champion_id::Caitlyn:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::FiddleSticks:
            switch (spellSlot) {
            case spellslot::w:
                return 1;
            case spellslot::r:
                return 3;
            default:
                break;
            }

        case champion_id::Galio:
            switch (spellSlot) {
            case spellslot::w:
                return 1;
            case spellslot::r:
                return 3;
            default:
                break;
            }

        case champion_id::Gragas:
            if (spellSlot == spellslot::w)
                return 1;
            break;

        case champion_id::Irelia:
            if (spellSlot == spellslot::w)
                return 1;
            break;

        case champion_id::Ivern:
            if (spellSlot == spellslot::invalid) // Use spell hash
                return 1;
            break;

        case champion_id::Janna:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Jhin:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Karthus:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Katarina:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Kayn:
            if (spellSlot == spellslot::r) // Might discard this as the channel is being done while untargettable no matter what happens
                return 2;
            break;

        case champion_id::KSante:
            if (spellSlot == spellslot::w)
                return 1;
            break;

        case champion_id::Lucian:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Malzahar:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::MasterYi:
            if (spellSlot == spellslot::w)
                return 1; // Not sure if I should return 1 or 2 considering it's mostly used as an AA reset... returning 2 seems odd
            break;

        case champion_id::MissFortune:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Nunu:
            switch (spellSlot) {
            case spellslot::w:
                return 1;
            case spellslot::r:
                return 3;
            default:
                break;
            }

        case champion_id::Pantheon:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Poppy:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Pyke:
            if (spellSlot == spellslot::q)
                return 1;
            break;

        case champion_id::Quinn:
            if (spellSlot == spellslot::r)
                return 1;
            break;

        case champion_id::Rammus:
            if (spellSlot == spellslot::q)
                return 1;
            break;

        case champion_id::Ryze:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Shen:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Sion:
            switch (spellSlot) {
                case spellslot::q:
                    return 2;
                case spellslot::r:
                    return 3;
                default:
                    break;
            }
            break;

        case champion_id::TahmKench:
            if (spellSlot == spellslot::w)
                return 2;
            break;

        case champion_id::Taliyah:
            if (spellSlot == spellslot::w)
                return 2;
            break;

        case champion_id::TwistedFate:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Varus:
            if (spellSlot == spellslot::q)
                return 1;
            break;

        case champion_id::Velkoz:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Vi:
            if (spellSlot == spellslot::q)
                return 1;
            break;

        case champion_id::Warwick:
            if (spellSlot == (spellslot)48 || spellSlot == spellslot::r)
                return 3;
            break;

        case champion_id::Xerath:
            switch (spellSlot) {
                case spellslot::q:
                    return 1;
                case spellslot::r:
                    return 3;
                default:
                    break;
                }

        case champion_id::Yuumi:
            switch (spellSlot) {
                case spellslot::q:
                    return 1;
                case spellslot::r:
                    return 3;
                default:
                    break;
            }

        case champion_id::Zac:
            if (spellSlot == spellslot::r)
                return 3;
            break;

        default:
            return 0;
        }

        return 0;
    }

    void InitiateSlot(TreeTab* tab, game_object_script entity, spellslot slot, std::string name, std::string spellName, bool defaultValue, int mode)
    {
        std::string key;
        void* texture;
        switch (slot)
        {
            case spellslot::q:
                key = "Q";
                texture = entity->get_spell(slot)->get_icon_texture();
                break;
            case spellslot::w:
                key = "W";
                texture = entity->get_spell(slot)->get_icon_texture();
                break;
            case spellslot::e:
                key = "E";
                texture = entity->get_spell(slot)->get_icon_texture();
                break;
            case spellslot::r:
                key = "R";
                texture = entity->get_spell(slot)->get_icon_texture();
                break;
            case spellslot::item_1:
                key = "Q1";
                texture = entity->get_spell(slot)->get_icon_texture_by_index(1);
                break;
            case spellslot::invalid:
                key = "P";
                texture = entity->get_passive_icon_texture();
                break;
            default:
                key = "?";
                texture = entity->get_passive_icon_texture();
                break;
        }

        if (entity == nullptr)
            return;

        auto model = entity->get_model();
        auto id = std::to_string((int)entity->get_champion());

        auto t = tab->add_tab(model, "[" + name + "]");
        t->set_texture(entity->get_square_icon_portrait());

        switch (mode)
        {
            case 1: // Consider Case 1 as "Cancel"
                db::CanCancel[model + key] = t->add_checkbox(model + key, "[" + key + "] - " + spellName, defaultValue);
                db::CanCancel[model + key]->set_texture(texture);
                db::CanCancel[model + key]->set_tooltip("[Importance] of " + std::to_string(localImportance(entity->get_champion(), slot)));
                break;
            case 2: // Consider Case 2 as "Ally Buff"
                db::CanOnAllyBuff[id + key] = t->add_checkbox(id + key, "[" + key + "] - " + spellName, defaultValue);
                db::CanOnAllyBuff[id + key]->set_texture(texture);
                break;
        }
    }

    void InitializeCancelMenu(TreeTab* tab)
    {
        if (!tab) // To prevent crashes in case of bad usage!
        {
            console->print_error("[BlahajDB] - Error Code: DB-IM1");
            return;
        }

        std::vector<game_object_script> enemyList = entitylist->get_enemy_heroes();

        int counter = 5;

        for (auto& e : enemyList)
        {
            if (e == nullptr)
                return;

            auto id = e->get_champion();

            switch (id) {
                case champion_id::Akshan:
                    InitiateSlot(tab, e, spellslot::r, "Akshan", "Comeuppance", true, 1);
                    break;

                case champion_id::Caitlyn:
                    InitiateSlot(tab, e, spellslot::r, "Caitlyn", "Ace in the Hole", true, 1);
                    break;

                case champion_id::FiddleSticks:
                    InitiateSlot(tab, e, spellslot::w, "Fiddlesticks", "Bountiful Harvest", true, 1);
                    InitiateSlot(tab, e, spellslot::r, "Fiddlesticks", "Crowstorm", true, 1);
                    break;

                case champion_id::Galio:
                    InitiateSlot(tab, e, spellslot::w, "Galio", "Shield of Durand", false, 1);
                    InitiateSlot(tab, e, spellslot::r, "Galio", "Hero's Entrance", true, 1);
                    break;

                case champion_id::Gragas:
                    InitiateSlot(tab, e, spellslot::w, "Gragas", "Drunken Rage", false, 1);
                    break;

                case champion_id::Irelia:
                    InitiateSlot(tab, e, spellslot::w, "Irelia", "Defiant Dance", false, 1);
                    break;

                case champion_id::Janna:
                    InitiateSlot(tab, e, spellslot::r, "Janna", "Monsoon", true, 1);
                    break;

                case champion_id::Jhin:
                    InitiateSlot(tab, e, spellslot::r, "Jhin", "Curtain's Call", true, 1);
                    break;

                case champion_id::Karthus:
                    InitiateSlot(tab, e, spellslot::r, "Karthus", "Requiem", true, 1);
                    break;

                case champion_id::Katarina:
                    InitiateSlot(tab, e, spellslot::r, "Katarina", "Death Lotus", true, 1);
                    break;

                case champion_id::Kayn:
                    InitiateSlot(tab, e, spellslot::r, "Kayn", "Umbral Trespass", true, 1);
                    break;

                case champion_id::KSante:
                    InitiateSlot(tab, e, spellslot::w, "K'Sante", "Path Maker", true, 1);
                    break;

                case champion_id::Lucian:
                    InitiateSlot(tab, e, spellslot::r, "Lucian", "The Culling", true, 1);
                    break;

                case champion_id::Malzahar:
                    InitiateSlot(tab, e, spellslot::r, "Malzahar", "Death Grasp", true, 1);
                    break;

                case champion_id::MasterYi:
                    InitiateSlot(tab, e, spellslot::w, "Master Yi", "Meditate", true, 1);
                    break;

                case champion_id::MissFortune:
                    InitiateSlot(tab, e, spellslot::r, "Miss Fortune", "Bullet Time", true, 1);
                    break;

                case champion_id::Nunu:
                    InitiateSlot(tab, e, spellslot::w, "Nunu and Willump", "Biggest Snowball Ever!", true, 1);

                    InitiateSlot(tab, e, spellslot::r, "Nunu and Willump", "Absolute Zero", true, 1);
                    break;

                case champion_id::Pantheon:
                    InitiateSlot(tab, e, spellslot::q, "Pantheon", "Comet Spear", true, 1);

                    InitiateSlot(tab, e, spellslot::r, "Pantheon", "Grand Starfall", true, 1);
                    break;

                case champion_id::Poppy:
                    InitiateSlot(tab, e, spellslot::r, "Poppy", "Keeper's Verdict", true, 1);

                case champion_id::Pyke:
                    InitiateSlot(tab, e, spellslot::q, "Pyke", "Bone Skewer", true, 1);

                case champion_id::Quinn:
                    InitiateSlot(tab, e, spellslot::r, "Quinn", "Behind Enemy Lines", true, 1);

                case champion_id::Rammus:
                    InitiateSlot(tab, e, spellslot::q, "Rammus", "Powerball", true, 1);
                    break;

                case champion_id::Ryze:
                    InitiateSlot(tab, e, spellslot::r, "Ryze", "Realm Warp", true, 1);
                    break;

                case champion_id::Shen:
                    InitiateSlot(tab, e, spellslot::r, "Shen", "Stand United", true, 1);
                    break;

                case champion_id::Sion:
                    InitiateSlot(tab, e, spellslot::r, "Sion", "Decimating Smash", true, 1);
                    InitiateSlot(tab, e, spellslot::r, "Sion", "Unstoppable Onslaught", true, 1);
                    break;

                case champion_id::TahmKench:
                    InitiateSlot(tab, e, spellslot::w, "Tahm Kench", "Abyssal Dive", true, 1);
                    break;

                case champion_id::Taliyah:
                    InitiateSlot(tab, e, spellslot::r, "Taliyah", "Weaver's Wall", true, 1);
                    break;

                case champion_id::TwistedFate:
                    InitiateSlot(tab, e, spellslot::r, "Twisted Fate", "Gate", true, 1);
                    break;

                case champion_id::Varus:
                    InitiateSlot(tab, e, spellslot::q, "Varus", "Piercing Arrow", true, 1);
                    break;

                case champion_id::Velkoz:
                    InitiateSlot(tab, e, spellslot::r, "Vel'Koz", "Life Form Disintegration Ray", true, 1);
                    break;

                case champion_id::Vi:
                    InitiateSlot(tab, e, spellslot::q, "Vi", "Vault Breaker", true, 1);
                    break;

                case champion_id::Viego:
                    InitiateSlot(tab, e, spellslot::w, "Viego", "Spectral Maw", true, 1);
                    break;

                case champion_id::Vladimir:
                    InitiateSlot(tab, e, spellslot::e, "Vladimir", "Tides of Blood", true, 1);
                    break;

                case champion_id::Warwick:
                    InitiateSlot(tab, e, spellslot::q, "Warwick", "Jaws of the Beast", true, 1);
                    InitiateSlot(tab, e, spellslot::r, "Warwick", "Infinite Duress", true, 1);
                    break;

                case champion_id::Xerath:
                    InitiateSlot(tab, e, spellslot::q, "Xerath", "Arcanopulse", true, 1);
                    InitiateSlot(tab, e, spellslot::r, "Xerath", "Rite of the Arcane", true, 1);
                    break;

                case champion_id::Yuumi:
                    InitiateSlot(tab, e, spellslot::q, "Yuumi", "Prowling Projectile", true, 1);
                    InitiateSlot(tab, e, spellslot::r, "Yuumi", "Final Chapter", true, 1);
                    break;

                case champion_id::Zac:
                    InitiateSlot(tab, e, spellslot::r, "Zac", "Elastic Slingshot", true, 1);
                    break;

                default:
                    counter = -1;
                    break;
            }
        }

        tab->add_separator("databaseInfo", "- Database made by Omori! <3 -");
        tab->add_separator("databaseVersion", "Version: " + DBVersion);
    }

    void InitializeBuffMenu(TreeTab* tab)
    {
        if (!tab) // To prevent crashes in case of bad usage!
        {
            console->print_error("[BlahajDB] - Error Code: DB-IM2");
            return;
        }

        std::vector<game_object_script> allyList = entitylist->get_ally_heroes();

        int counter = 5;

        for (auto& e : allyList)
        {
            if (e == nullptr)
                return;

            auto id = e->get_champion();

            switch (id)
            {
                case champion_id::Ashe:
                    InitiateSlot(tab, e, spellslot::q, "Ashe", "Ranger's Focus", true, 2);
                    break;
                case champion_id::Draven:
                    InitiateSlot(tab, e, spellslot::w, "Draven", "Blood Rush", true, 2);
                    break;
                case champion_id::Jinx:
                    InitiateSlot(tab, e, spellslot::invalid, "Jinx", "Get Excited!", true, 2);
                    InitiateSlot(tab, e, spellslot::q, "Jinx", "Pow-Pow (3 Stacks)", false, 2);
                    break;
                case champion_id::Kaisa:
                    InitiateSlot(tab, e, spellslot::e, "Kai'Sa", "Supercharge", true, 2);
                    break;
                case champion_id::KogMaw:
                    InitiateSlot(tab, e, spellslot::w, "Kog'Maw", "Bio-Arcane Barrage", true, 2);
                    break;
                case champion_id::Lucian:
                    InitiateSlot(tab, e, spellslot::invalid, "Lucian", "Lightslinger", false, 2);
                    break;
                case champion_id::MissFortune:
                    InitiateSlot(tab, e, spellslot::w, "Miss Fortune", "Strut", true, 2);
                    break;
                case champion_id::Nilah:
                    InitiateSlot(tab, e, spellslot::w, "Nilah", "Jubilant Veil", false, 2);
                    break;
                case champion_id::Samira:
                    InitiateSlot(tab, e, spellslot::invalid, "Samira", "Daredevil Impulse (S Tier)", false, 2);
                    InitiateSlot(tab, e, spellslot::w, "Samira", "Blade Whirl", false, 2);
                    InitiateSlot(tab, e, spellslot::e, "Samira", "Wild Rush", false, 2);
                    InitiateSlot(tab, e, spellslot::r, "Samira", "Inferno Trigger", true, 2);
                    break;
                case champion_id::Sivir:
                    InitiateSlot(tab, e, spellslot::w, "Sivir", "Ricochet", true, 2);
                    InitiateSlot(tab, e, spellslot::e, "Sivir", "Spell Shield", false, 2);
                    InitiateSlot(tab, e, spellslot::r, "Sivir", "On The Hunt", false, 2);
                    break;
                case champion_id::Tristana:
                    InitiateSlot(tab, e, spellslot::q, "Tristana", "Rapid Fire", true, 2);
                    break;
                case champion_id::Twitch:
                    InitiateSlot(tab, e, spellslot::q, "Twitch", "Ambush (Stealth)", false, 2);
                    InitiateSlot(tab, e, spellslot::item_1, "Twitch", "Ambush (Attack Speed Buff)", true, 2);
                    InitiateSlot(tab, e, spellslot::r, "Twitch", "Spray and Pray", true, 2);
                    break;
                case champion_id::Vayne:
                    InitiateSlot(tab, e, spellslot::q, "Vayne", "Tumble", false, 2);
                    InitiateSlot(tab, e, spellslot::item_1, "Vayne", "Tumble (Stealth)", true, 2);
                    InitiateSlot(tab, e, spellslot::r, "Vayne", "Final Hour", false, 2);
                    break;
                case champion_id::Xayah:
                    InitiateSlot(tab, e, spellslot::invalid, "Xayah", "Clean Cuts", false, 2);
                    InitiateSlot(tab, e, spellslot::w, "Xayah", "Deadly Plumage", true, 2);
                    break;
                case champion_id::Zeri:
                    InitiateSlot(tab, e, spellslot::e, "Zeri", "Spark Surge", true, 2);
                    InitiateSlot(tab, e, spellslot::r, "Zeri", "Lightning Crash", true, 2);
                    break;
            }
        }

        tab->add_separator("databaseInfo", "- Database made by Omori! <3 -");
        tab->add_separator("databaseVersion", "Version: " + DBVersion);
    }
    
    bool canOnAllyBuff(uint32_t buffHash)
    {
        spellslot slot = spellslot::invalid;
        champion_id id = (champion_id)-1;

        switch (buffHash)
        {
            case (buff_hash("AsheQAttack")): // Ashe Q
                slot = spellslot::q;
                id = champion_id::Ashe;
                break;
            case (buff_hash("DravenFury")): // Draven W
                slot = spellslot::w;
                id = champion_id::Draven;
                break;
            case (buff_hash("jinxpassivekill")): // Jinx Passive
                slot = spellslot::invalid;
                id = champion_id::Jinx;
                break;
            case (buff_hash("jinxqramp")): // Jinx 3 Stacks Minigun
                slot = spellslot::q;
                id = champion_id::Jinx;
                break;
            case (buff_hash("kaisaeattackspeed")): // Kai'Sa E AS Buff
                slot = spellslot::e;
                id = champion_id::Kaisa;
                break;
            case (buff_hash("KogMawBioArcaneBarrage")): // Kog'Maw W
                slot = spellslot::w;
                id = champion_id::KogMaw;
                break;
            case (buff_hash("LucianPassiveBuff")): // Lucian Passive
                slot = spellslot::invalid;
                id = champion_id::Lucian;
                break;
            case (buff_hash("MissFortuneViciousStrikes")): // MF W
                slot = spellslot::w;
                id = champion_id::MissFortune;
                break;
            case (buff_hash("NilahW")): // Nilah W
                slot = spellslot::w;
                id = champion_id::Nilah;
                break;
            case (buff_hash("samirarreadybuff")): // Samira R Available
                slot = spellslot::invalid;
                id = champion_id::Samira;
                break;
            case (buff_hash("SamiraW")): // Samira W
                slot = spellslot::w;
                id = champion_id::Samira;
                break;
            case (buff_hash("SamiraEBuff")): // Samira E
                slot = spellslot::e;
                id = champion_id::Samira;
                break;
            case (buff_hash("SamiraR")): // Samira R
                slot = spellslot::r;
                id = champion_id::Samira;
                break;
            case (buff_hash("vaynetumblebonus")): // Vayne Q (normal)
                slot = spellslot::q;
                id = champion_id::Vayne;
                break;
            case (buff_hash("vaynetumblefade")): // Vayne Q (stealth)
                slot = spellslot::item_1;
                id = champion_id::Vayne;
                break;
            case (buff_hash("VayneInquisition")): // Vayne R
                slot = spellslot::r;
                id = champion_id::Vayne;
                break;
            case (buff_hash("SivirE")): // Sivir E
                slot = spellslot::e;
                id = champion_id::Sivir;
                break;
            case (buff_hash("SivirW")): // Sivir W
                slot = spellslot::w;
                id = champion_id::Sivir;
                break;
            case (buff_hash("SivirR")): // Sivir R
                slot = spellslot::r;
                id = champion_id::Sivir;
                break;
            case (buff_hash("TristanaQ")): // Tristana Q
                slot = spellslot::q;
                id = champion_id::Tristana;
                break;
            case (buff_hash("TwitchHideInShadows")): // Twitch Q Stealth
                slot = spellslot::q;
                id = champion_id::Twitch;
                break;
            case (buff_hash("twitchhideinshadowsbuff")): // Twitch Q AS
                slot = spellslot::item_1;
                id = champion_id::Twitch;
                break;
            case (buff_hash("TwitchFullAutomatic")): // Twitch R
                slot = spellslot::r;
                id = champion_id::Twitch;
                break;
            case (buff_hash("XayahW")): // Xayah W
                slot = spellslot::w;
                id = champion_id::Xayah;
                break;
            case (buff_hash("XayahPassiveActive")): // Xayah Passive
                slot = spellslot::invalid;
                id = champion_id::Xayah;
                break;
            case (buff_hash("ZeriR")): // Zeri R
                slot = spellslot::r;
                id = champion_id::Zeri;
                break;
            case (buff_hash("zeriespecialrounds")): // Zeri E
                slot = spellslot::e;
                id = champion_id::Zeri;
                break;
            default:
                return false;

        }

        std::string key;

        switch (slot)
        {
            case spellslot::q:
                key = "Q";
                break;
            case spellslot::w:
                key = "W";
                break;
            case spellslot::e:
                key = "E";
                break;
            case spellslot::r:
                key = "R";
                break;
            case spellslot::item_1:
                key = "Q1";
                break;
            case spellslot::invalid:
                key = "P";
                break;
            default:
                key = "?";
                break;
        }

        auto toCheck = std::to_string((int)id);

        auto entity = Database::db::CanOnAllyBuff.find(toCheck + key);
        if (entity == Database::db::CanOnAllyBuff.end())
            return false;

        return entity->second->get_bool();
    }

    bool canCancel(game_object_script target)
    {
        auto active = target->get_active_spell();
        if (!active)
            return false;
        auto slot = active->get_spellslot();

        std::string key;

        switch (slot)
        {
            case spellslot::q:
                key = "Q";
                break;
            case spellslot::w:
                key = "W";
                break;
            case spellslot::e:
                key = "E";
                break;
            case spellslot::r:
                key = "R";
                break;
            default:
                key = "?";
                break;
        }

        auto entity = Database::db::CanCancel.find(target->get_model() + key);
        if (entity == Database::db::CanCancel.end())
            return false;

        return entity->second->get_bool();
    }
}


