ep3_rryatt_gotal_hunter_01 = Creature:new {
	customName = "Gotal Hunter",
	randomNameType = NAME_GENERIC_TAG,
	socialGroup = "",
	faction = "",
	level = 85,
	chanceHit = 0.85,
	damageMin = 1200,
	damageMax = 1800,
	baseXp = 8500,
	baseHAM = 45000,
	baseHAMmax = 55000,
	armor = 3,
	resists = {80,80,80,80,80,80,80,80,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = NONE,
	optionsBitmask = AIENABLED,
	diet = HERBIVORE,

	templates = {"object/mobile/ep3/ep3_rryatt_gotal_hunter_01.iff"},
	lootGroups = {
		{
			groups = {
				{group = "clothing_attachments", chance = 1000000},
				{group = "pistols", chance = 2000000},
				{group = "rifles", chance = 2000000},
				{group = "carbines", chance = 2000000},
				{group = "armor_attachments", chance = 1000000},
				{group = "melee_weapons", chance = 2000000},
			}
		}
	},
	weapons = {"pirate_weapons_heavy"},
	conversationTemplate = "",
	reactionStf = "@npc_reaction/slang",
	attacks = merge(brawlermaster,marksmanmaster)
}

CreatureTemplates:addCreatureTemplate(ep3_rryatt_gotal_hunter_01, "ep3_rryatt_gotal_hunter_01")
